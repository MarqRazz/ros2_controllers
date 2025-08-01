// Copyright (c) 2023, Stogl Robotics Consulting UG (haftungsbeschränkt)
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include <memory>
#include <string>
#include <vector>

#include "hardware_interface/types/hardware_interface_type_values.hpp"
#include "test_bicycle_steering_controller.hpp"

class BicycleSteeringControllerTest
: public BicycleSteeringControllerFixture<TestableBicycleSteeringController>
{
};

TEST_F(BicycleSteeringControllerTest, all_parameters_set_configure_success)
{
  SetUpController();

  ASSERT_EQ(controller_->on_configure(rclcpp_lifecycle::State()), NODE_SUCCESS);

  ASSERT_THAT(
    controller_->params_.traction_joints_names, testing::ElementsAreArray(traction_joints_names_));
  ASSERT_THAT(
    controller_->params_.steering_joints_names, testing::ElementsAreArray(steering_joints_names_));
  ASSERT_EQ(controller_->params_.open_loop, open_loop_);
  ASSERT_EQ(controller_->params_.velocity_rolling_window_size, velocity_rolling_window_size_);
  ASSERT_EQ(controller_->params_.position_feedback, position_feedback_);
  ASSERT_EQ(controller_->bicycle_params_.wheelbase, wheelbase_);
  ASSERT_EQ(controller_->bicycle_params_.traction_wheel_radius, traction_wheel_radius_);
}

TEST_F(BicycleSteeringControllerTest, check_exported_interfaces)
{
  SetUpController();

  ASSERT_EQ(controller_->on_configure(rclcpp_lifecycle::State()), NODE_SUCCESS);

  auto cmd_if_conf = controller_->command_interface_configuration();
  ASSERT_EQ(cmd_if_conf.names.size(), joint_command_values_.size());
  EXPECT_EQ(
    cmd_if_conf.names[CMD_TRACTION_WHEEL],
    traction_joints_names_[0] + "/" + traction_interface_name_);
  EXPECT_EQ(
    cmd_if_conf.names[CMD_STEER_WHEEL], steering_joints_names_[0] + "/" + steering_interface_name_);
  EXPECT_EQ(cmd_if_conf.type, controller_interface::interface_configuration_type::INDIVIDUAL);

  auto state_if_conf = controller_->state_interface_configuration();
  ASSERT_EQ(state_if_conf.names.size(), joint_state_values_.size());
  EXPECT_EQ(
    state_if_conf.names[STATE_TRACTION_WHEEL],
    controller_->traction_joints_state_names_[0] + "/" + traction_interface_name_);
  EXPECT_EQ(
    state_if_conf.names[STATE_STEER_AXIS],
    controller_->steering_joints_state_names_[0] + "/" + steering_interface_name_);
  EXPECT_EQ(state_if_conf.type, controller_interface::interface_configuration_type::INDIVIDUAL);

  // check ref itfs
  auto reference_interfaces = controller_->export_reference_interfaces();
  ASSERT_EQ(reference_interfaces.size(), joint_reference_interfaces_.size());
  for (size_t i = 0; i < joint_reference_interfaces_.size(); ++i)
  {
    const std::string ref_itf_prefix_name =
      std::string(controller_->get_node()->get_name()) + "/" + joint_reference_interfaces_[i];
    EXPECT_EQ(
      reference_interfaces[i]->get_name(),
      ref_itf_prefix_name + "/" + hardware_interface::HW_IF_VELOCITY);
    EXPECT_EQ(reference_interfaces[i]->get_prefix_name(), ref_itf_prefix_name);
    EXPECT_EQ(reference_interfaces[i]->get_interface_name(), hardware_interface::HW_IF_VELOCITY);
  }
}

TEST_F(BicycleSteeringControllerTest, activate_success)
{
  SetUpController();

  ASSERT_EQ(controller_->on_configure(rclcpp_lifecycle::State()), NODE_SUCCESS);
  ASSERT_EQ(controller_->on_activate(rclcpp_lifecycle::State()), NODE_SUCCESS);

  // check that the message is reset
  auto msg = controller_->input_ref_.get();
  EXPECT_TRUE(std::isnan(msg.twist.linear.x));
  EXPECT_TRUE(std::isnan(msg.twist.linear.y));
  EXPECT_TRUE(std::isnan(msg.twist.linear.z));
  EXPECT_TRUE(std::isnan(msg.twist.angular.x));
  EXPECT_TRUE(std::isnan(msg.twist.angular.y));
  EXPECT_TRUE(std::isnan(msg.twist.angular.z));
}

TEST_F(BicycleSteeringControllerTest, update_success)
{
  SetUpController();

  ASSERT_EQ(controller_->on_configure(rclcpp_lifecycle::State()), NODE_SUCCESS);
  ASSERT_EQ(controller_->on_activate(rclcpp_lifecycle::State()), NODE_SUCCESS);

  ASSERT_EQ(
    controller_->update(rclcpp::Time(0, 0, RCL_ROS_TIME), rclcpp::Duration::from_seconds(0.01)),
    controller_interface::return_type::OK);
}

TEST_F(BicycleSteeringControllerTest, deactivate_success)
{
  SetUpController();

  ASSERT_EQ(controller_->on_configure(rclcpp_lifecycle::State()), NODE_SUCCESS);
  ASSERT_EQ(controller_->on_activate(rclcpp_lifecycle::State()), NODE_SUCCESS);
  ASSERT_EQ(controller_->on_deactivate(rclcpp_lifecycle::State()), NODE_SUCCESS);
}

TEST_F(BicycleSteeringControllerTest, reactivate_success)
{
  SetUpController();

  ASSERT_EQ(controller_->on_configure(rclcpp_lifecycle::State()), NODE_SUCCESS);
  ASSERT_EQ(controller_->on_activate(rclcpp_lifecycle::State()), NODE_SUCCESS);
  ASSERT_EQ(controller_->on_deactivate(rclcpp_lifecycle::State()), NODE_SUCCESS);
  ASSERT_TRUE(std::isnan(controller_->command_interfaces_[0].get_optional().value()));
  ASSERT_EQ(controller_->on_activate(rclcpp_lifecycle::State()), NODE_SUCCESS);
  ASSERT_TRUE(std::isnan(controller_->command_interfaces_[0].get_optional().value()));

  ASSERT_EQ(
    controller_->update(rclcpp::Time(0, 0, RCL_ROS_TIME), rclcpp::Duration::from_seconds(0.01)),
    controller_interface::return_type::OK);
}

TEST_F(BicycleSteeringControllerTest, test_update_logic)
{
  SetUpController();
  rclcpp::executors::MultiThreadedExecutor executor;
  executor.add_node(controller_->get_node()->get_node_base_interface());

  ASSERT_EQ(controller_->on_configure(rclcpp_lifecycle::State()), NODE_SUCCESS);
  controller_->set_chained_mode(false);
  ASSERT_EQ(controller_->on_activate(rclcpp_lifecycle::State()), NODE_SUCCESS);
  ASSERT_FALSE(controller_->is_in_chained_mode());

  // set command statically
  ControllerReferenceMsg msg;
  msg.header.stamp = controller_->get_node()->now();
  msg.twist.linear.x = 0.1;
  msg.twist.angular.z = 0.2;
  controller_->input_ref_.set(msg);

  ASSERT_EQ(
    controller_->update(rclcpp::Time(0, 0, RCL_ROS_TIME), rclcpp::Duration::from_seconds(0.01)),
    controller_interface::return_type::OK);

  EXPECT_NEAR(
    controller_->command_interfaces_[CMD_TRACTION_WHEEL].get_optional().value(), 0.1 / 0.45,
    COMMON_THRESHOLD);
  EXPECT_NEAR(
    controller_->command_interfaces_[CMD_STEER_WHEEL].get_optional().value(), 1.4179821977774734,
    COMMON_THRESHOLD);

  EXPECT_FALSE(std::isnan(controller_->input_ref_.get().twist.linear.x));
  EXPECT_EQ(controller_->reference_interfaces_.size(), joint_reference_interfaces_.size());
  for (const auto & interface : controller_->reference_interfaces_)
  {
    EXPECT_TRUE(std::isnan(interface));
  }
}

TEST_F(BicycleSteeringControllerTest, test_update_logic_chained)
{
  SetUpController();
  rclcpp::executors::MultiThreadedExecutor executor;
  executor.add_node(controller_->get_node()->get_node_base_interface());

  ASSERT_EQ(controller_->on_configure(rclcpp_lifecycle::State()), NODE_SUCCESS);
  controller_->set_chained_mode(true);
  ASSERT_EQ(controller_->on_activate(rclcpp_lifecycle::State()), NODE_SUCCESS);
  ASSERT_TRUE(controller_->is_in_chained_mode());

  controller_->reference_interfaces_[0] = 0.1;
  controller_->reference_interfaces_[1] = 0.2;

  ASSERT_EQ(
    controller_->update(rclcpp::Time(0, 0, RCL_ROS_TIME), rclcpp::Duration::from_seconds(0.01)),
    controller_interface::return_type::OK);

  EXPECT_NEAR(
    controller_->command_interfaces_[CMD_TRACTION_WHEEL].get_optional().value(), 0.1 / 0.45,
    COMMON_THRESHOLD);
  EXPECT_NEAR(
    controller_->command_interfaces_[CMD_STEER_WHEEL].get_optional().value(), 1.4179821977774734,
    COMMON_THRESHOLD);

  EXPECT_TRUE(std::isnan(controller_->input_ref_.get().twist.linear.x));
  EXPECT_EQ(controller_->reference_interfaces_.size(), joint_reference_interfaces_.size());
  for (const auto & interface : controller_->reference_interfaces_)
  {
    EXPECT_TRUE(std::isnan(interface));
  }
}

TEST_F(BicycleSteeringControllerTest, publish_status_success)
{
  SetUpController();

  ASSERT_EQ(controller_->on_configure(rclcpp_lifecycle::State()), NODE_SUCCESS);
  ASSERT_EQ(controller_->on_activate(rclcpp_lifecycle::State()), NODE_SUCCESS);

  ASSERT_EQ(
    controller_->update(rclcpp::Time(0, 0, RCL_ROS_TIME), rclcpp::Duration::from_seconds(0.01)),
    controller_interface::return_type::OK);

  ControllerStateMsg msg;
  subscribe_and_get_messages(msg);
}

TEST_F(BicycleSteeringControllerTest, receive_message_and_publish_updated_status)
{
  SetUpController();
  rclcpp::executors::MultiThreadedExecutor executor;
  executor.add_node(controller_->get_node()->get_node_base_interface());

  ASSERT_EQ(controller_->on_configure(rclcpp_lifecycle::State()), NODE_SUCCESS);
  ASSERT_EQ(controller_->on_activate(rclcpp_lifecycle::State()), NODE_SUCCESS);

  ASSERT_EQ(
    controller_->update(rclcpp::Time(0, 0, RCL_ROS_TIME), rclcpp::Duration::from_seconds(0.01)),
    controller_interface::return_type::OK);

  ControllerStateMsg msg;
  subscribe_and_get_messages(msg);

  // never received a valid command, linear velocity should have been reset
  EXPECT_EQ(msg.traction_command[0], 0.0);
  EXPECT_EQ(msg.steering_angle_command[0], 2.2);

  publish_commands(0.1, 0.2);
  controller_->wait_for_commands(executor);

  ASSERT_EQ(
    controller_->update(rclcpp::Time(0, 0, RCL_ROS_TIME), rclcpp::Duration::from_seconds(0.01)),
    controller_interface::return_type::OK);

  EXPECT_NEAR(
    controller_->command_interfaces_[CMD_TRACTION_WHEEL].get_optional().value(), 0.1 / 0.45,
    COMMON_THRESHOLD);
  EXPECT_NEAR(
    controller_->command_interfaces_[CMD_STEER_WHEEL].get_optional().value(), 1.4179821977774734,
    COMMON_THRESHOLD);

  subscribe_and_get_messages(msg);

  EXPECT_NEAR(msg.traction_command[0], 0.1 / 0.45, COMMON_THRESHOLD);
  EXPECT_NEAR(msg.steering_angle_command[0], 1.4179821977774734, COMMON_THRESHOLD);
}

int main(int argc, char ** argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  rclcpp::init(argc, argv);
  int result = RUN_ALL_TESTS();
  rclcpp::shutdown();
  return result;
}
