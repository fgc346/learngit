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
CMAKE_SOURCE_DIR = /home/erma/Program/learngit/Practice/TestEigen

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/erma/Program/learngit/Practice/TestEigen/build

# Include any dependencies generated for this target.
include CMakeFiles/EigenDemo.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/EigenDemo.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/EigenDemo.dir/flags.make

CMakeFiles/EigenDemo.dir/main.cpp.o: CMakeFiles/EigenDemo.dir/flags.make
CMakeFiles/EigenDemo.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/erma/Program/learngit/Practice/TestEigen/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/EigenDemo.dir/main.cpp.o"
	/usr/bin/g++-7  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/EigenDemo.dir/main.cpp.o -c /home/erma/Program/learngit/Practice/TestEigen/main.cpp

CMakeFiles/EigenDemo.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/EigenDemo.dir/main.cpp.i"
	/usr/bin/g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/erma/Program/learngit/Practice/TestEigen/main.cpp > CMakeFiles/EigenDemo.dir/main.cpp.i

CMakeFiles/EigenDemo.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/EigenDemo.dir/main.cpp.s"
	/usr/bin/g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/erma/Program/learngit/Practice/TestEigen/main.cpp -o CMakeFiles/EigenDemo.dir/main.cpp.s

CMakeFiles/EigenDemo.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/EigenDemo.dir/main.cpp.o.requires

CMakeFiles/EigenDemo.dir/main.cpp.o.provides: CMakeFiles/EigenDemo.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/EigenDemo.dir/build.make CMakeFiles/EigenDemo.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/EigenDemo.dir/main.cpp.o.provides

CMakeFiles/EigenDemo.dir/main.cpp.o.provides.build: CMakeFiles/EigenDemo.dir/main.cpp.o


# Object files for target EigenDemo
EigenDemo_OBJECTS = \
"CMakeFiles/EigenDemo.dir/main.cpp.o"

# External object files for target EigenDemo
EigenDemo_EXTERNAL_OBJECTS =

../bin/EigenDemo: CMakeFiles/EigenDemo.dir/main.cpp.o
../bin/EigenDemo: CMakeFiles/EigenDemo.dir/build.make
../bin/EigenDemo: CMakeFiles/EigenDemo.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/erma/Program/learngit/Practice/TestEigen/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ../bin/EigenDemo"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/EigenDemo.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/EigenDemo.dir/build: ../bin/EigenDemo

.PHONY : CMakeFiles/EigenDemo.dir/build

CMakeFiles/EigenDemo.dir/requires: CMakeFiles/EigenDemo.dir/main.cpp.o.requires

.PHONY : CMakeFiles/EigenDemo.dir/requires

CMakeFiles/EigenDemo.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/EigenDemo.dir/cmake_clean.cmake
.PHONY : CMakeFiles/EigenDemo.dir/clean

CMakeFiles/EigenDemo.dir/depend:
	cd /home/erma/Program/learngit/Practice/TestEigen/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/erma/Program/learngit/Practice/TestEigen /home/erma/Program/learngit/Practice/TestEigen /home/erma/Program/learngit/Practice/TestEigen/build /home/erma/Program/learngit/Practice/TestEigen/build /home/erma/Program/learngit/Practice/TestEigen/build/CMakeFiles/EigenDemo.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/EigenDemo.dir/depend

