# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
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

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/erma/Program/Test/TestLua

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/erma/Program/Test/TestLua/build

# Include any dependencies generated for this target.
include CMakeFiles/LuaDemo.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/LuaDemo.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/LuaDemo.dir/flags.make

CMakeFiles/LuaDemo.dir/main.cpp.o: CMakeFiles/LuaDemo.dir/flags.make
CMakeFiles/LuaDemo.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/erma/Program/Test/TestLua/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/LuaDemo.dir/main.cpp.o"
	/usr/bin/g++-7  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/LuaDemo.dir/main.cpp.o -c /home/erma/Program/Test/TestLua/main.cpp

CMakeFiles/LuaDemo.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/LuaDemo.dir/main.cpp.i"
	/usr/bin/g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/erma/Program/Test/TestLua/main.cpp > CMakeFiles/LuaDemo.dir/main.cpp.i

CMakeFiles/LuaDemo.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/LuaDemo.dir/main.cpp.s"
	/usr/bin/g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/erma/Program/Test/TestLua/main.cpp -o CMakeFiles/LuaDemo.dir/main.cpp.s

CMakeFiles/LuaDemo.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/LuaDemo.dir/main.cpp.o.requires

CMakeFiles/LuaDemo.dir/main.cpp.o.provides: CMakeFiles/LuaDemo.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/LuaDemo.dir/build.make CMakeFiles/LuaDemo.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/LuaDemo.dir/main.cpp.o.provides

CMakeFiles/LuaDemo.dir/main.cpp.o.provides.build: CMakeFiles/LuaDemo.dir/main.cpp.o


CMakeFiles/LuaDemo.dir/sample.cpp.o: CMakeFiles/LuaDemo.dir/flags.make
CMakeFiles/LuaDemo.dir/sample.cpp.o: ../sample.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/erma/Program/Test/TestLua/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/LuaDemo.dir/sample.cpp.o"
	/usr/bin/g++-7  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/LuaDemo.dir/sample.cpp.o -c /home/erma/Program/Test/TestLua/sample.cpp

CMakeFiles/LuaDemo.dir/sample.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/LuaDemo.dir/sample.cpp.i"
	/usr/bin/g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/erma/Program/Test/TestLua/sample.cpp > CMakeFiles/LuaDemo.dir/sample.cpp.i

CMakeFiles/LuaDemo.dir/sample.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/LuaDemo.dir/sample.cpp.s"
	/usr/bin/g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/erma/Program/Test/TestLua/sample.cpp -o CMakeFiles/LuaDemo.dir/sample.cpp.s

CMakeFiles/LuaDemo.dir/sample.cpp.o.requires:

.PHONY : CMakeFiles/LuaDemo.dir/sample.cpp.o.requires

CMakeFiles/LuaDemo.dir/sample.cpp.o.provides: CMakeFiles/LuaDemo.dir/sample.cpp.o.requires
	$(MAKE) -f CMakeFiles/LuaDemo.dir/build.make CMakeFiles/LuaDemo.dir/sample.cpp.o.provides.build
.PHONY : CMakeFiles/LuaDemo.dir/sample.cpp.o.provides

CMakeFiles/LuaDemo.dir/sample.cpp.o.provides.build: CMakeFiles/LuaDemo.dir/sample.cpp.o


# Object files for target LuaDemo
LuaDemo_OBJECTS = \
"CMakeFiles/LuaDemo.dir/main.cpp.o" \
"CMakeFiles/LuaDemo.dir/sample.cpp.o"

# External object files for target LuaDemo
LuaDemo_EXTERNAL_OBJECTS =

../bin/LuaDemo: CMakeFiles/LuaDemo.dir/main.cpp.o
../bin/LuaDemo: CMakeFiles/LuaDemo.dir/sample.cpp.o
../bin/LuaDemo: CMakeFiles/LuaDemo.dir/build.make
../bin/LuaDemo: CMakeFiles/LuaDemo.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/erma/Program/Test/TestLua/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable ../bin/LuaDemo"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/LuaDemo.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/LuaDemo.dir/build: ../bin/LuaDemo

.PHONY : CMakeFiles/LuaDemo.dir/build

CMakeFiles/LuaDemo.dir/requires: CMakeFiles/LuaDemo.dir/main.cpp.o.requires
CMakeFiles/LuaDemo.dir/requires: CMakeFiles/LuaDemo.dir/sample.cpp.o.requires

.PHONY : CMakeFiles/LuaDemo.dir/requires

CMakeFiles/LuaDemo.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/LuaDemo.dir/cmake_clean.cmake
.PHONY : CMakeFiles/LuaDemo.dir/clean

CMakeFiles/LuaDemo.dir/depend:
	cd /home/erma/Program/Test/TestLua/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/erma/Program/Test/TestLua /home/erma/Program/Test/TestLua /home/erma/Program/Test/TestLua/build /home/erma/Program/Test/TestLua/build /home/erma/Program/Test/TestLua/build/CMakeFiles/LuaDemo.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/LuaDemo.dir/depend

