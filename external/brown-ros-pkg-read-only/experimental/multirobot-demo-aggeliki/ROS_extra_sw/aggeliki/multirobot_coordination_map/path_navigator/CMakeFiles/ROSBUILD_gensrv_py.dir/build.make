# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.6

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canoncical targets will work.
.SUFFIXES:

# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list

# Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /opt/ros/boxturtle/ros/aggeliki/path_navigator

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /opt/ros/boxturtle/ros/aggeliki/path_navigator

# Utility rule file for ROSBUILD_gensrv_py.

CMakeFiles/ROSBUILD_gensrv_py: src/path_navigator/srv/__init__.py

src/path_navigator/srv/__init__.py: src/path_navigator/srv/_getNextWaypoint.py
src/path_navigator/srv/__init__.py: src/path_navigator/srv/_setWaypoints.py
	$(CMAKE_COMMAND) -E cmake_progress_report /opt/ros/boxturtle/ros/aggeliki/path_navigator/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold "Generating src/path_navigator/srv/__init__.py"
	/opt/ros/boxturtle/ros/core/rospy/scripts/gensrv_py --initpy /opt/ros/boxturtle/ros/aggeliki/path_navigator/srv/getNextWaypoint.srv /opt/ros/boxturtle/ros/aggeliki/path_navigator/srv/setWaypoints.srv

src/path_navigator/srv/_getNextWaypoint.py: srv/getNextWaypoint.srv
src/path_navigator/srv/_getNextWaypoint.py: /opt/ros/boxturtle/ros/core/rospy/scripts/gensrv_py
src/path_navigator/srv/_getNextWaypoint.py: /opt/ros/boxturtle/ros/core/roslib/scripts/gendeps
src/path_navigator/srv/_getNextWaypoint.py: manifest.xml
src/path_navigator/srv/_getNextWaypoint.py: /opt/ros/boxturtle/ros/core/genmsg_cpp/manifest.xml
src/path_navigator/srv/_getNextWaypoint.py: /opt/ros/boxturtle/ros/tools/rospack/manifest.xml
src/path_navigator/srv/_getNextWaypoint.py: /opt/ros/boxturtle/ros/core/roslib/manifest.xml
src/path_navigator/srv/_getNextWaypoint.py: /opt/ros/boxturtle/ros/std_msgs/manifest.xml
src/path_navigator/srv/_getNextWaypoint.py: /opt/ros/boxturtle/ros/core/roslang/manifest.xml
src/path_navigator/srv/_getNextWaypoint.py: /opt/ros/boxturtle/ros/3rdparty/xmlrpcpp/manifest.xml
src/path_navigator/srv/_getNextWaypoint.py: /opt/ros/boxturtle/ros/core/rosconsole/manifest.xml
src/path_navigator/srv/_getNextWaypoint.py: /opt/ros/boxturtle/ros/core/roscpp/manifest.xml
src/path_navigator/srv/_getNextWaypoint.py: /opt/ros/boxturtle/ros/core/rospy/manifest.xml
src/path_navigator/srv/_getNextWaypoint.py: /opt/ros/boxturtle/ros/3rdparty/pycrypto/manifest.xml
src/path_navigator/srv/_getNextWaypoint.py: /opt/ros/boxturtle/ros/3rdparty/paramiko/manifest.xml
src/path_navigator/srv/_getNextWaypoint.py: /opt/ros/boxturtle/ros/core/rosout/manifest.xml
src/path_navigator/srv/_getNextWaypoint.py: /opt/ros/boxturtle/ros/tools/roslaunch/manifest.xml
src/path_navigator/srv/_getNextWaypoint.py: /opt/ros/boxturtle/ros/test/rostest/manifest.xml
src/path_navigator/srv/_getNextWaypoint.py: /opt/ros/boxturtle/ros/tools/topic_tools/manifest.xml
src/path_navigator/srv/_getNextWaypoint.py: /opt/ros/boxturtle/ros/tools/rosrecord/manifest.xml
src/path_navigator/srv/_getNextWaypoint.py: /opt/ros/boxturtle/ros/tools/rosbagmigration/manifest.xml
src/path_navigator/srv/_getNextWaypoint.py: /opt/ros/boxturtle/stacks/common_msgs/geometry_msgs/manifest.xml
src/path_navigator/srv/_getNextWaypoint.py: /opt/ros/boxturtle/stacks/common_msgs/nav_msgs/manifest.xml
src/path_navigator/srv/_getNextWaypoint.py: /opt/ros/boxturtle/ros/brown-ros-pkg/position_tracker/manifest.xml
src/path_navigator/srv/_getNextWaypoint.py: /opt/ros/boxturtle/ros/aggeliki/map_loader/manifest.xml
	$(CMAKE_COMMAND) -E cmake_progress_report /opt/ros/boxturtle/ros/aggeliki/path_navigator/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold "Generating src/path_navigator/srv/_getNextWaypoint.py"
	/opt/ros/boxturtle/ros/core/rospy/scripts/gensrv_py --noinitpy /opt/ros/boxturtle/ros/aggeliki/path_navigator/srv/getNextWaypoint.srv

src/path_navigator/srv/_setWaypoints.py: srv/setWaypoints.srv
src/path_navigator/srv/_setWaypoints.py: /opt/ros/boxturtle/ros/core/rospy/scripts/gensrv_py
src/path_navigator/srv/_setWaypoints.py: /opt/ros/boxturtle/ros/core/roslib/scripts/gendeps
src/path_navigator/srv/_setWaypoints.py: /opt/ros/boxturtle/ros/aggeliki/map_loader/msg/Node.msg
src/path_navigator/srv/_setWaypoints.py: /opt/ros/boxturtle/ros/core/roslib/msg/Header.msg
src/path_navigator/srv/_setWaypoints.py: msg/Waypoints.msg
src/path_navigator/srv/_setWaypoints.py: /opt/ros/boxturtle/ros/brown-ros-pkg/position_tracker/msg/Position.msg
src/path_navigator/srv/_setWaypoints.py: manifest.xml
src/path_navigator/srv/_setWaypoints.py: /opt/ros/boxturtle/ros/core/genmsg_cpp/manifest.xml
src/path_navigator/srv/_setWaypoints.py: /opt/ros/boxturtle/ros/tools/rospack/manifest.xml
src/path_navigator/srv/_setWaypoints.py: /opt/ros/boxturtle/ros/core/roslib/manifest.xml
src/path_navigator/srv/_setWaypoints.py: /opt/ros/boxturtle/ros/std_msgs/manifest.xml
src/path_navigator/srv/_setWaypoints.py: /opt/ros/boxturtle/ros/core/roslang/manifest.xml
src/path_navigator/srv/_setWaypoints.py: /opt/ros/boxturtle/ros/3rdparty/xmlrpcpp/manifest.xml
src/path_navigator/srv/_setWaypoints.py: /opt/ros/boxturtle/ros/core/rosconsole/manifest.xml
src/path_navigator/srv/_setWaypoints.py: /opt/ros/boxturtle/ros/core/roscpp/manifest.xml
src/path_navigator/srv/_setWaypoints.py: /opt/ros/boxturtle/ros/core/rospy/manifest.xml
src/path_navigator/srv/_setWaypoints.py: /opt/ros/boxturtle/ros/3rdparty/pycrypto/manifest.xml
src/path_navigator/srv/_setWaypoints.py: /opt/ros/boxturtle/ros/3rdparty/paramiko/manifest.xml
src/path_navigator/srv/_setWaypoints.py: /opt/ros/boxturtle/ros/core/rosout/manifest.xml
src/path_navigator/srv/_setWaypoints.py: /opt/ros/boxturtle/ros/tools/roslaunch/manifest.xml
src/path_navigator/srv/_setWaypoints.py: /opt/ros/boxturtle/ros/test/rostest/manifest.xml
src/path_navigator/srv/_setWaypoints.py: /opt/ros/boxturtle/ros/tools/topic_tools/manifest.xml
src/path_navigator/srv/_setWaypoints.py: /opt/ros/boxturtle/ros/tools/rosrecord/manifest.xml
src/path_navigator/srv/_setWaypoints.py: /opt/ros/boxturtle/ros/tools/rosbagmigration/manifest.xml
src/path_navigator/srv/_setWaypoints.py: /opt/ros/boxturtle/stacks/common_msgs/geometry_msgs/manifest.xml
src/path_navigator/srv/_setWaypoints.py: /opt/ros/boxturtle/stacks/common_msgs/nav_msgs/manifest.xml
src/path_navigator/srv/_setWaypoints.py: /opt/ros/boxturtle/ros/brown-ros-pkg/position_tracker/manifest.xml
src/path_navigator/srv/_setWaypoints.py: /opt/ros/boxturtle/ros/aggeliki/map_loader/manifest.xml
	$(CMAKE_COMMAND) -E cmake_progress_report /opt/ros/boxturtle/ros/aggeliki/path_navigator/CMakeFiles $(CMAKE_PROGRESS_3)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold "Generating src/path_navigator/srv/_setWaypoints.py"
	/opt/ros/boxturtle/ros/core/rospy/scripts/gensrv_py --noinitpy /opt/ros/boxturtle/ros/aggeliki/path_navigator/srv/setWaypoints.srv

ROSBUILD_gensrv_py: CMakeFiles/ROSBUILD_gensrv_py
ROSBUILD_gensrv_py: src/path_navigator/srv/__init__.py
ROSBUILD_gensrv_py: src/path_navigator/srv/_getNextWaypoint.py
ROSBUILD_gensrv_py: src/path_navigator/srv/_setWaypoints.py
ROSBUILD_gensrv_py: CMakeFiles/ROSBUILD_gensrv_py.dir/build.make
.PHONY : ROSBUILD_gensrv_py

# Rule to build all files generated by this target.
CMakeFiles/ROSBUILD_gensrv_py.dir/build: ROSBUILD_gensrv_py
.PHONY : CMakeFiles/ROSBUILD_gensrv_py.dir/build

CMakeFiles/ROSBUILD_gensrv_py.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ROSBUILD_gensrv_py.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ROSBUILD_gensrv_py.dir/clean

CMakeFiles/ROSBUILD_gensrv_py.dir/depend:
	cd /opt/ros/boxturtle/ros/aggeliki/path_navigator && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /opt/ros/boxturtle/ros/aggeliki/path_navigator /opt/ros/boxturtle/ros/aggeliki/path_navigator /opt/ros/boxturtle/ros/aggeliki/path_navigator /opt/ros/boxturtle/ros/aggeliki/path_navigator /opt/ros/boxturtle/ros/aggeliki/path_navigator/CMakeFiles/ROSBUILD_gensrv_py.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/ROSBUILD_gensrv_py.dir/depend

