^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
Changelog for package diff_drive_controller
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

5.5.0 (2025-07-31)
------------------

5.4.0 (2025-07-23)
------------------
* Use new handles API in ros2_controllers to fix deprecation warnings (`#1566 <https://github.com/ros-controls/ros2_controllers/issues/1566>`_)
* Contributors: Sanjeev Kumar

5.3.0 (2025-07-14)
------------------
* Explicit cast `rcutils_duration_value_t` (`#1808 <https://github.com/ros-controls/ros2_controllers/issues/1808>`_)
* Update description of limit() function in speed_limiter (`#1793 <https://github.com/ros-controls/ros2_controllers/issues/1793>`_)
* Use ParamListener::try_get_params to Avoid Blocking in Real-Time Contexts (`#1198 <https://github.com/ros-controls/ros2_controllers/issues/1198>`_)
* Update realtime containers (`#1721 <https://github.com/ros-controls/ros2_controllers/issues/1721>`_)
* Contributors: Aarav Gupta, Christoph Fröhlich, Kenta Kato

5.2.0 (2025-06-23)
------------------

5.1.0 (2025-06-11)
------------------
* Fix DiffDrive claiming state when open_loop is set (`#1731 <https://github.com/ros-controls/ros2_controllers/issues/1731>`_)
* Contributors: mergify[bot]

5.0.2 (2025-05-26)
------------------

5.0.1 (2025-05-24)
------------------
* Use target_link_libraries instead of ament_target_dependencies (`#1697 <https://github.com/ros-controls/ros2_controllers/issues/1697>`_)
* Contributors: Sai Kishor Kothakota

5.0.0 (2025-05-17)
------------------
* Simplify `on_set_chained_mode` implementations avoiding cpplint warnings (`#1564 <https://github.com/ros-controls/ros2_controllers/issues/1564>`_)
* Cleanup deprecations in diff_drive_controller (`#1653 <https://github.com/ros-controls/ros2_controllers/issues/1653>`_)
* Deprecating tf2 C Headers (`#1325 <https://github.com/ros-controls/ros2_controllers/issues/1325>`_)
* Contributors: Bhagyesh Agresar, Christoph Fröhlich, Lucas Wendland

4.24.0 (2025-04-27)
-------------------
* Call `configure()` of base class instead of node (`#1659 <https://github.com/ros-controls/ros2_controllers/issues/1659>`_)
* Contributors: Christoph Fröhlich

4.23.0 (2025-04-10)
-------------------
* Bump version of pre-commit hooks (`#1618 <https://github.com/ros-controls/ros2_controllers/issues/1618>`_)
* Use global cmake macros and fix gcc-10 build (`#1527 <https://github.com/ros-controls/ros2_controllers/issues/1527>`_)
* Contributors: Christoph Fröhlich, github-actions[bot]

4.22.0 (2025-03-17)
-------------------
* Use the custom validators directly from control_toolbox (`#1504 <https://github.com/ros-controls/ros2_controllers/issues/1504>`_)
* Use new handles API in diff_drive_controller (`#1565 <https://github.com/ros-controls/ros2_controllers/issues/1565>`_)
* Contributors: Christoph Fröhlich, Sai Kishor Kothakota

4.21.0 (2025-03-01)
-------------------
* Fix the exported interface naming in the chainable controllers (`#1528 <https://github.com/ros-controls/ros2_controllers/issues/1528>`_)
* Cleanup wrong lifecycle transitions in tests and unnecessary checks (`#1534 <https://github.com/ros-controls/ros2_controllers/issues/1534>`_)
* Fix reference in chained diff drive controller (`#1529 <https://github.com/ros-controls/ros2_controllers/issues/1529>`_)
* docs for chainable diff_drive_controller (`#1518 <https://github.com/ros-controls/ros2_controllers/issues/1518>`_)
* Contributors: Arthur Lovekin, Christoph Fröhlich, Sai Kishor Kothakota, Thibault Poignonec

4.20.0 (2025-01-29)
-------------------
* Make diff_drive_controller a ChainableControllerInterface (`#1485 <https://github.com/ros-controls/ros2_controllers/issues/1485>`_)
* Update paths of GPL includes (`#1487 <https://github.com/ros-controls/ros2_controllers/issues/1487>`_)
* Fix SpeedLimiter Constructor regression (`#1478 <https://github.com/ros-controls/ros2_controllers/issues/1478>`_)
* Contributors: Arthur Lovekin, Christoph Fröhlich, Sai Kishor Kothakota

4.19.0 (2025-01-13)
-------------------
* Check dt in updateFromVelocity (`#1481 <https://github.com/ros-controls/ros2_controllers/issues/1481>`_)
* Remove empty on_shutdown() callbacks (`#1477 <https://github.com/ros-controls/ros2_controllers/issues/1477>`_)
* Remove visibility macros (`#1451 <https://github.com/ros-controls/ros2_controllers/issues/1451>`_)
* Contributors: Bence Magyar, Julia Jia, Tony Najjar

4.18.0 (2024-12-19)
-------------------
* Update command limiter of diff_drive_controller (`#1315 <https://github.com/ros-controls/ros2_controllers/issues/1315>`_)
* Improve tf_prefix based on namespace (`#1420 <https://github.com/ros-controls/ros2_controllers/issues/1420>`_)
* [CI] Add clang job and setup concurrency (`#1407 <https://github.com/ros-controls/ros2_controllers/issues/1407>`_)
* Contributors: Christoph Fröhlich, Rafal Gorecki

4.17.0 (2024-12-07)
-------------------
* Use the .hpp headers from `realtime_tools` package (`#1406 <https://github.com/ros-controls/ros2_controllers/issues/1406>`_)
* Fix RealtimeBox API changes (`#1385 <https://github.com/ros-controls/ros2_controllers/issues/1385>`_)
* Rename Twist->TwistStamped (`#1393 <https://github.com/ros-controls/ros2_controllers/issues/1393>`_)
* Add few warning flags to error in all ros2_controllers packages and fix tests (`#1370 <https://github.com/ros-controls/ros2_controllers/issues/1370>`_)
* Update maintainers and add url tags (`#1363 <https://github.com/ros-controls/ros2_controllers/issues/1363>`_)
* Contributors: Christoph Fröhlich, Sai Kishor Kothakota

4.16.0 (2024-11-08)
-------------------

4.15.0 (2024-10-07)
-------------------

4.14.0 (2024-09-11)
-------------------
* rename get/set_state to get/set_lifecylce_state (`#1250 <https://github.com/ros-controls/ros2_controllers/issues/1250>`_)
* Contributors: Manuel Muth

4.13.0 (2024-08-22)
-------------------
* Fixes tests to work with use_global_arguments NodeOptions parameter  (`#1256 <https://github.com/ros-controls/ros2_controllers/issues/1256>`_)
* Contributors: Sai Kishor Kothakota

4.12.1 (2024-08-14)
-------------------

4.12.0 (2024-07-23)
-------------------
* Add missing includes (`#1226 <https://github.com/ros-controls/ros2_controllers/issues/1226>`_)
* Remove duplicated call to rclcpp::shutdown in test (`#1220 <https://github.com/ros-controls/ros2_controllers/issues/1220>`_)
* Unused header cleanup (`#1199 <https://github.com/ros-controls/ros2_controllers/issues/1199>`_)
* Fix WaitSet issue in tests  (`#1206 <https://github.com/ros-controls/ros2_controllers/issues/1206>`_)
* Fix parallel gripper controller CI (`#1202 <https://github.com/ros-controls/ros2_controllers/issues/1202>`_)
* Contributors: Christoph Fröhlich, Henry Moore, Noel Jiménez García, Sai Kishor Kothakota

4.11.0 (2024-07-09)
-------------------
* added changes corresponding to the logger and clock propagation in ResourceManager (`#1184 <https://github.com/ros-controls/ros2_controllers/issues/1184>`_)
* Contributors: Sai Kishor Kothakota

4.10.0 (2024-07-01)
-------------------

4.9.0 (2024-06-05)
------------------
* Add mobile robot kinematics 101 and improve steering library docs (`#954 <https://github.com/ros-controls/ros2_controllers/issues/954>`_)
* Bump version of pre-commit hooks (`#1157 <https://github.com/ros-controls/ros2_controllers/issues/1157>`_)
* Contributors: Christoph Fröhlich, github-actions[bot]

4.8.0 (2024-05-14)
------------------
* Remove non-existing parameter (`#1119 <https://github.com/ros-controls/ros2_controllers/issues/1119>`_)
* Add parameter check for geometric values (`#1120 <https://github.com/ros-controls/ros2_controllers/issues/1120>`_)
* Deprecate non-stamped twist for tricycle_controller and steering_controllers (`#1093 <https://github.com/ros-controls/ros2_controllers/issues/1093>`_)
* add missing compiler definitions of RCPPUTILS_VERSION (`#1089 <https://github.com/ros-controls/ros2_controllers/issues/1089>`_)
* Contributors: Christoph Fröhlich, Sai Kishor Kothakota

4.7.0 (2024-03-22)
------------------
* added conditioning to have rolling tags compilable in older versions (`#1071 <https://github.com/ros-controls/ros2_controllers/issues/1071>`_)
* Contributors: Sai Kishor Kothakota

4.6.0 (2024-02-12)
------------------
* Add test_depend on `hardware_interface_testing` also for diff_drive (`#1021 <https://github.com/ros-controls/ros2_controllers/issues/1021>`_)
* Add test_depend on `hardware_interface_testing` (`#1018 <https://github.com/ros-controls/ros2_controllers/issues/1018>`_)
* Fix tests for using new `get_node_options` API (`#840 <https://github.com/ros-controls/ros2_controllers/issues/840>`_)
* Contributors: Christoph Fröhlich, Sai Kishor Kothakota

4.5.0 (2024-01-31)
------------------
* [diff_drive] Remove unused parameter and add simple validation #abi-breaking (`#958 <https://github.com/ros-controls/ros2_controllers/issues/958>`_)
* Add tests for `interface_configuration_type` consistently (`#899 <https://github.com/ros-controls/ros2_controllers/issues/899>`_)
* Let sphinx add parameter description with nested structures to documentation (`#652 <https://github.com/ros-controls/ros2_controllers/issues/652>`_)
* Contributors: Christoph Fröhlich

4.4.0 (2024-01-11)
------------------

4.3.0 (2024-01-08)
------------------
* Add few warning flags to error (`#961 <https://github.com/ros-controls/ros2_controllers/issues/961>`_)
* Contributors: Sai Kishor Kothakota

4.2.0 (2023-12-12)
------------------

4.1.0 (2023-12-01)
------------------

4.0.0 (2023-11-21)
------------------
* fix tests for API break of passing controller manager update rate in init method (`#854 <https://github.com/ros-controls/ros2_controllers/issues/854>`_)
* [diff_drive_controller] Fixed typos in diff_drive_controller_parameter.yaml. (`#822 <https://github.com/ros-controls/ros2_controllers/issues/822>`_)
* [diff_drive_controller] Remove non-stamped Twist option (`#812 <https://github.com/ros-controls/ros2_controllers/issues/812>`_)
* Adjust tests after passing URDF to controllers (`#817 <https://github.com/ros-controls/ros2_controllers/issues/817>`_)
* Contributors: Bence Magyar, Sai Kishor Kothakota, Tony Baltovski

3.17.0 (2023-10-31)
-------------------

3.16.0 (2023-09-20)
-------------------

3.15.0 (2023-09-11)
-------------------
* Update docs for diff drive controller (`#751 <https://github.com/ros-controls/ros2_controllers/issues/751>`_)
* Contributors: Christoph Fröhlich

3.14.0 (2023-08-16)
-------------------

3.13.0 (2023-08-04)
-------------------
* [DiffDriveController] Optional tf namespace prefixes instead of using node namespace (`#533 <https://github.com/ros-controls/ros2_controllers/issues/533>`_)
* Contributors: Ben Holden, Bence Magyar

3.12.0 (2023-07-18)
-------------------

3.11.0 (2023-06-24)
-------------------
* Added -Wconversion flag and fix warnings (`#667 <https://github.com/ros-controls/ros2_controllers/issues/667>`_)
* Contributors: gwalck

3.10.1 (2023-06-06)
-------------------

3.10.0 (2023-06-04)
-------------------
* removed duplicated previous_publish_timestamp\_ increment by publish_period\_ in diff_drive_controller.cpp (`#644 <https://github.com/ros-controls/ros2_controllers/issues/644>`_)
* enable ReflowComments to also use ColumnLimit on comments (`#625 <https://github.com/ros-controls/ros2_controllers/issues/625>`_)
* Contributors: Sai Kishor Kothakota, Jules CARPENTIER

3.9.0 (2023-05-28)
------------------
* Use generate_parameter_library for all params (`#601 <https://github.com/ros-controls/ros2_controllers/issues/601>`_)
* Use branch name substitution for all links (`#618 <https://github.com/ros-controls/ros2_controllers/issues/618>`_)
* Fix compilation warnings (`#621 <https://github.com/ros-controls/ros2_controllers/issues/621>`_)
* Fix github links on control.ros.org (`#604 <https://github.com/ros-controls/ros2_controllers/issues/604>`_)
* Contributors: Christoph Fröhlich, Noel Jiménez García, Mathias Lüdtke

3.8.0 (2023-05-14)
------------------
* Clear registered handles of DiffDriveController on deactivate (`#596 <https://github.com/ros-controls/ros2_controllers/issues/596>`_)
* Contributors: Noel Jiménez García

3.7.0 (2023-05-02)
------------------
* Fix wrong publish timestamp initialization (`#585 <https://github.com/ros-controls/ros2_controllers/issues/585>`_)
* Contributors: Noel Jiménez García

3.6.0 (2023-04-29)
------------------
* Renovate load controller tests (`#569 <https://github.com/ros-controls/ros2_controllers/issues/569>`_)
* adjusted open_loop param description in diff_drive_controller_parameter.yaml (`#570 <https://github.com/ros-controls/ros2_controllers/issues/570>`_)
* Contributors: Bence Magyar, muritane

3.5.0 (2023-04-14)
------------------

3.4.0 (2023-04-02)
------------------

3.3.0 (2023-03-07)
------------------
* Add comments about auto-generated header files (`#539 <https://github.com/ros-controls/ros2_controllers/issues/539>`_)
* Contributors: AndyZe

3.2.0 (2023-02-10)
------------------
* Fix overriding of install (`#510 <https://github.com/ros-controls/ros2_controllers/issues/510>`_)
* Remove compile warnings. (`#519 <https://github.com/ros-controls/ros2_controllers/issues/519>`_)
* Contributors: Dr. Denis, Tyler Weaver, Chris Thrasher

3.1.0 (2023-01-26)
------------------

3.0.0 (2023-01-19)
------------------
* diff_drive base_frame_id param (`#495 <https://github.com/ros-controls/ros2_controllers/issues/495>`_)
  changed default value from `odom` -> `base_link`
* Add backward_ros to all controllers (`#489 <https://github.com/ros-controls/ros2_controllers/issues/489>`_)
* Remove compilation warnings from DiffDriveController (`#477 <https://github.com/ros-controls/ros2_controllers/issues/477>`_)
* Contributors: Bence Magyar, Denis Štogl, Jakub Delicat

2.15.0 (2022-12-06)
-------------------
* [DiffDriveController] Use generate parameter library (`#386 <https://github.com/ros-controls/ros2_controllers/issues/386>`_)
* [DiffDriveController] Change units of velocity feedback (`#452 <https://github.com/ros-controls/ros2_controllers/issues/452>`_)
* Contributors: Maciej Stępień, Paul Gesel, Denis Štogl, Bence Magyar

2.14.0 (2022-11-18)
-------------------
* Odom Topic & Frame Namespaces  (`#461 <https://github.com/ros-controls/ros2_controllers/issues/461>`_)
* Write detailed Diff-Drive-Controller documentation to make all the interfaces understandable. (`#371 <https://github.com/ros-controls/ros2_controllers/issues/371>`_)
* Contributors: Denis Štogl, sp-sophia-labs

2.13.0 (2022-10-05)
-------------------

2.12.0 (2022-09-01)
-------------------
* Fix formatting CI job (`#418 <https://github.com/ros-controls/ros2_controllers/issues/418>`_)
* Contributors: Tyler Weaver

2.11.0 (2022-08-04)
-------------------

2.10.0 (2022-08-01)
-------------------
* Formatting changes from pre-commit (`#400 <https://github.com/ros-controls/ros2_controllers/issues/400>`_)
* Parameter loading fixup in diff_drive and gripper controllers (`#385 <https://github.com/ros-controls/ros2_controllers/issues/385>`_)
* Contributors: Andy Zelenak, Tyler Weaver

2.9.0 (2022-07-14)
------------------

2.8.0 (2022-07-09)
------------------

2.7.0 (2022-07-03)
------------------
* Update controllers with new get_name hardware interfaces (`#369 <https://github.com/ros-controls/ros2_controllers/issues/369>`_)
* Contributors: Lucas Schulze

2.6.0 (2022-06-18)
------------------
* Disable failing workflows (`#363 <https://github.com/ros-controls/ros2_controllers/issues/363>`_)
* CMakeLists cleanup (`#362 <https://github.com/ros-controls/ros2_controllers/issues/362>`_)
* Fix exception about parameter already been declared & Change default c++ version to 17 (`#360 <https://github.com/ros-controls/ros2_controllers/issues/360>`_)
  * Default C++ version to 17
  * Replace explicit use of declare_paremeter with auto_declare
* Contributors: Andy Zelenak, Jafar Abdi

2.5.0 (2022-05-13)
------------------
* [diff_drive_controller] Made odom topic name relative as it was in ROS1. (`#343 <https://github.com/ros-controls/ros2_controllers/issues/343>`_)
* Fix wrong integration of velocity feedback in odometry in diff_drive_controller (`#331 <https://github.com/ros-controls/ros2_controllers/issues/331>`_)
* Contributors: Patrick Roncagliolo, Tony Baltovski

2.4.0 (2022-04-29)
------------------
* updated to use node getter functions (`#329 <https://github.com/ros-controls/ros2_controllers/issues/329>`_)
* Contributors: Bence Magyar, Denis Štogl, Jack Center

2.3.0 (2022-04-21)
------------------
* Use CallbackReturn from controller_interface namespace (`#333 <https://github.com/ros-controls/ros2_controllers/issues/333>`_)
* Contributors: Bence Magyar, Denis Štogl

2.2.0 (2022-03-25)
------------------
* Use lifecycle node as base for controllers (`#244 <https://github.com/ros-controls/ros2_controllers/issues/244>`_)
* Contributors: Denis Štogl, Vatan Aksoy Tezer, Bence Magyar

2.1.0 (2022-02-23)
------------------
* use rolling mean from rcppmath (`#211 <https://github.com/ros-controls/ros2_controllers/issues/211>`_)
* Contributors: Karsten Knese, Bence Magyar

2.0.1 (2022-02-01)
------------------

2.0.0 (2022-01-28)
------------------

1.3.0 (2022-01-11)
------------------
* Add publish_rate option for the diff_drive_controller (`#278 <https://github.com/ros-controls/ros2_controllers/issues/278>`_)
* Fix angular velocity direction of diff_drive_controller odometry (`#281 <https://github.com/ros-controls/ros2_controllers/issues/281>`_)
* Contributors: Benjamin Hug, Paul Verhoeckx

1.2.0 (2021-12-29)
------------------
* Add velocity feedback option for diff_drive_controller (`#260 <https://github.com/ros-controls/ros2_controllers/issues/260>`_)
* Contributors: Patrick Roncagliolo

1.1.0 (2021-10-25)
------------------
* Use common test URDF from descriptions.hpp (`#258 <https://github.com/ros-controls/ros2_controllers/issues/258>`_)
* Fix header include on Fedora <https://github.com/ros-controls/ros2_controllers/issues/255>`_ (`#256 <https://github.com/ros-controls/ros2_controllers/issues/256>`_)
* Fix diff_drive accel limit (`#242 <https://github.com/ros-controls/ros2_controllers/issues/242>`_) (`#252 <https://github.com/ros-controls/ros2_controllers/issues/252>`_)
* Contributors: Denis Štogl, Josh Newans, Noeël Moeskops, bailaC

1.0.0 (2021-09-29)
------------------
* Add time and period to update function (`#241 <https://github.com/ros-controls/ros2_controllers/issues/241>`_)
* Unify style of controllers. (`#236 <https://github.com/ros-controls/ros2_controllers/issues/236>`_)
* ros2_controllers code changes to support ros2_controls issue `#489 <https://github.com/ros-controls/ros2_controllers/issues/489>`_ (`#233 <https://github.com/ros-controls/ros2_controllers/issues/233>`_)
* Removing Boost from controllers. (`#235 <https://github.com/ros-controls/ros2_controllers/issues/235>`_)
* refactor get_current_state to get_state (`#232 <https://github.com/ros-controls/ros2_controllers/issues/232>`_)
* Contributors: Bence Magyar, Denis Štogl, Márk Szitanics, bailaC

0.5.0 (2021-08-30)
------------------
* Add auto declaration of parameters. (`#224 <https://github.com/ros-controls/ros2_controllers/issues/224>`_)
* Bring precommit config up to speed with ros2_control (`#227 <https://github.com/ros-controls/ros2_controllers/issues/227>`_)
* Add initial pre-commit setup. (`#220 <https://github.com/ros-controls/ros2_controllers/issues/220>`_)
* Reduce docs warnings and correct adding guidelines (`#219 <https://github.com/ros-controls/ros2_controllers/issues/219>`_)
* Contributors: Bence Magyar, Denis Štogl, Lovro Ivanov

0.4.1 (2021-07-08)
------------------

0.4.0 (2021-06-28)
------------------
* Force torque sensor broadcaster (`#152 <https://github.com/ros-controls/ros2_controllers/issues/152>`_)
  * Add  rclcpp::shutdown(); to all standalone test functions
* Fixes for Windows (`#205 <https://github.com/ros-controls/ros2_controllers/issues/205>`_)
  * Fix MSVC build for diff_drive_controller test
* Fix parameter initialisation for galactic (`#199 <https://github.com/ros-controls/ros2_controllers/issues/199>`_)
* Contributors: Akash, Denis Štogl, Tim Clephas

0.3.1 (2021-05-23)
------------------

0.3.0 (2021-05-21)
------------------

0.2.1 (2021-05-03)
------------------
* Migrate from deprecated controller_interface::return_type::SUCCESS -> OK (`#167 <https://github.com/ros-controls/ros2_controllers/issues/167>`_)
* Add basic user docs pages for each package (`#156 <https://github.com/ros-controls/ros2_controllers/issues/156>`_)
* [diff_drive_controller] Change header math.h in cmath for better C++ compliance (`#148 <https://github.com/ros-controls/ros2_controllers/issues/148>`_)
  and isnan inclusion.
* Contributors: Bence Magyar, Olivier Stasse

0.2.0 (2021-02-06)
------------------
* Fix diff drive twist concurrency issues (`#146 <https://github.com/ros-controls/ros2_controllers/issues/146>`_)
  * Fix diff drive twist concurrency issues
  Before this fix, a twist message could be received and stored one
  thread, in the middle of the update() of the controller.
  This would be fixed by making a copy of the shared pointer at the
  beginning of the update() function, added realtime box to ensure safe
  concurrent access to the pointer.
  * Don't store limited command as last command
  Before these changes, the limited command overwrote the original
  command, which mean that it too much more time to reach the commanded
  speed.
  We only want this behavior when the command is too old and we replace it
  with 0 speed.
* Diff drive parameter fixes (`#145 <https://github.com/ros-controls/ros2_controllers/issues/145>`_)
  * Recover old speed limiter behavior, if unspecified min defaults to -max
  * Change cmd_vel_timeout to seconds (double) as ROS1 instead of ms(int)
* Unstamped cmd_vel subscriber rebased (`#143 <https://github.com/ros-controls/ros2_controllers/issues/143>`_)
* Contributors: Anas Abou Allaban, Victor Lopez

0.1.2 (2021-01-07)
------------------
* Remove unused sensor_msgs dependency (was non-declared in package.xml) (`#139 <https://github.com/ros-controls/ros2_controllers/issues/139>`_)
* Contributors: Bence Magyar

0.1.1 (2021-01-06)
------------------
* avoid warnings (`#137 <https://github.com/ros-controls/ros2_controllers/issues/137>`_)
* Migrate diff drive controller to resourcemanager (`#128 <https://github.com/ros-controls/ros2_controllers/issues/128>`_)
* Contributors: Bence Magyar, Karsten Knese

0.1.0 (2020-12-23)
------------------
