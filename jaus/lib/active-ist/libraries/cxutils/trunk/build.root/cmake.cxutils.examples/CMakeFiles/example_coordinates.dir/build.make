# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

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

# The program to use to edit the cache.
CMAKE_EDIT_COMMAND = /usr/bin/ccmake

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/ras/IGVC2013/jaus/lib/active-ist/libraries/cxutils/trunk

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ras/IGVC2013/jaus/lib/active-ist/libraries/cxutils/trunk

# Include any dependencies generated for this target.
include build.root/cmake.cxutils.examples/CMakeFiles/example_coordinates.dir/depend.make

# Include the progress variables for this target.
include build.root/cmake.cxutils.examples/CMakeFiles/example_coordinates.dir/progress.make

# Include the compile flags for this target's objects.
include build.root/cmake.cxutils.examples/CMakeFiles/example_coordinates.dir/flags.make

build.root/cmake.cxutils.examples/CMakeFiles/example_coordinates.dir/__/__/src/examples/example_coordinates.cpp.o: build.root/cmake.cxutils.examples/CMakeFiles/example_coordinates.dir/flags.make
build.root/cmake.cxutils.examples/CMakeFiles/example_coordinates.dir/__/__/src/examples/example_coordinates.cpp.o: src/examples/example_coordinates.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/ras/IGVC2013/jaus/lib/active-ist/libraries/cxutils/trunk/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object build.root/cmake.cxutils.examples/CMakeFiles/example_coordinates.dir/__/__/src/examples/example_coordinates.cpp.o"
	cd /home/ras/IGVC2013/jaus/lib/active-ist/libraries/cxutils/trunk/build.root/cmake.cxutils.examples && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/example_coordinates.dir/__/__/src/examples/example_coordinates.cpp.o -c /home/ras/IGVC2013/jaus/lib/active-ist/libraries/cxutils/trunk/src/examples/example_coordinates.cpp

build.root/cmake.cxutils.examples/CMakeFiles/example_coordinates.dir/__/__/src/examples/example_coordinates.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/example_coordinates.dir/__/__/src/examples/example_coordinates.cpp.i"
	cd /home/ras/IGVC2013/jaus/lib/active-ist/libraries/cxutils/trunk/build.root/cmake.cxutils.examples && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/ras/IGVC2013/jaus/lib/active-ist/libraries/cxutils/trunk/src/examples/example_coordinates.cpp > CMakeFiles/example_coordinates.dir/__/__/src/examples/example_coordinates.cpp.i

build.root/cmake.cxutils.examples/CMakeFiles/example_coordinates.dir/__/__/src/examples/example_coordinates.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/example_coordinates.dir/__/__/src/examples/example_coordinates.cpp.s"
	cd /home/ras/IGVC2013/jaus/lib/active-ist/libraries/cxutils/trunk/build.root/cmake.cxutils.examples && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/ras/IGVC2013/jaus/lib/active-ist/libraries/cxutils/trunk/src/examples/example_coordinates.cpp -o CMakeFiles/example_coordinates.dir/__/__/src/examples/example_coordinates.cpp.s

build.root/cmake.cxutils.examples/CMakeFiles/example_coordinates.dir/__/__/src/examples/example_coordinates.cpp.o.requires:
.PHONY : build.root/cmake.cxutils.examples/CMakeFiles/example_coordinates.dir/__/__/src/examples/example_coordinates.cpp.o.requires

build.root/cmake.cxutils.examples/CMakeFiles/example_coordinates.dir/__/__/src/examples/example_coordinates.cpp.o.provides: build.root/cmake.cxutils.examples/CMakeFiles/example_coordinates.dir/__/__/src/examples/example_coordinates.cpp.o.requires
	$(MAKE) -f build.root/cmake.cxutils.examples/CMakeFiles/example_coordinates.dir/build.make build.root/cmake.cxutils.examples/CMakeFiles/example_coordinates.dir/__/__/src/examples/example_coordinates.cpp.o.provides.build
.PHONY : build.root/cmake.cxutils.examples/CMakeFiles/example_coordinates.dir/__/__/src/examples/example_coordinates.cpp.o.provides

build.root/cmake.cxutils.examples/CMakeFiles/example_coordinates.dir/__/__/src/examples/example_coordinates.cpp.o.provides.build: build.root/cmake.cxutils.examples/CMakeFiles/example_coordinates.dir/__/__/src/examples/example_coordinates.cpp.o

# Object files for target example_coordinates
example_coordinates_OBJECTS = \
"CMakeFiles/example_coordinates.dir/__/__/src/examples/example_coordinates.cpp.o"

# External object files for target example_coordinates
example_coordinates_EXTERNAL_OBJECTS =

bin/example_coordinates: build.root/cmake.cxutils.examples/CMakeFiles/example_coordinates.dir/__/__/src/examples/example_coordinates.cpp.o
bin/example_coordinates: lib/libcxutils.so
bin/example_coordinates: lib/libcxjpeg-6b.a
bin/example_coordinates: build.root/cmake.cxutils.examples/CMakeFiles/example_coordinates.dir/build.make
bin/example_coordinates: build.root/cmake.cxutils.examples/CMakeFiles/example_coordinates.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable ../../bin/example_coordinates"
	cd /home/ras/IGVC2013/jaus/lib/active-ist/libraries/cxutils/trunk/build.root/cmake.cxutils.examples && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/example_coordinates.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
build.root/cmake.cxutils.examples/CMakeFiles/example_coordinates.dir/build: bin/example_coordinates
.PHONY : build.root/cmake.cxutils.examples/CMakeFiles/example_coordinates.dir/build

build.root/cmake.cxutils.examples/CMakeFiles/example_coordinates.dir/requires: build.root/cmake.cxutils.examples/CMakeFiles/example_coordinates.dir/__/__/src/examples/example_coordinates.cpp.o.requires
.PHONY : build.root/cmake.cxutils.examples/CMakeFiles/example_coordinates.dir/requires

build.root/cmake.cxutils.examples/CMakeFiles/example_coordinates.dir/clean:
	cd /home/ras/IGVC2013/jaus/lib/active-ist/libraries/cxutils/trunk/build.root/cmake.cxutils.examples && $(CMAKE_COMMAND) -P CMakeFiles/example_coordinates.dir/cmake_clean.cmake
.PHONY : build.root/cmake.cxutils.examples/CMakeFiles/example_coordinates.dir/clean

build.root/cmake.cxutils.examples/CMakeFiles/example_coordinates.dir/depend:
	cd /home/ras/IGVC2013/jaus/lib/active-ist/libraries/cxutils/trunk && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ras/IGVC2013/jaus/lib/active-ist/libraries/cxutils/trunk /home/ras/IGVC2013/jaus/lib/active-ist/libraries/cxutils/trunk/build/cmake/examples /home/ras/IGVC2013/jaus/lib/active-ist/libraries/cxutils/trunk /home/ras/IGVC2013/jaus/lib/active-ist/libraries/cxutils/trunk/build.root/cmake.cxutils.examples /home/ras/IGVC2013/jaus/lib/active-ist/libraries/cxutils/trunk/build.root/cmake.cxutils.examples/CMakeFiles/example_coordinates.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : build.root/cmake.cxutils.examples/CMakeFiles/example_coordinates.dir/depend

