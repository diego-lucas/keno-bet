# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_SOURCE_DIR = /home/diego/code/lp1/projeto-1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/diego/code/lp1/projeto-1/build

# Include any dependencies generated for this target.
include CMakeFiles/keno.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/keno.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/keno.dir/flags.make

CMakeFiles/keno.dir/src/main.cpp.o: CMakeFiles/keno.dir/flags.make
CMakeFiles/keno.dir/src/main.cpp.o: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/diego/code/lp1/projeto-1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/keno.dir/src/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/keno.dir/src/main.cpp.o -c /home/diego/code/lp1/projeto-1/src/main.cpp

CMakeFiles/keno.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/keno.dir/src/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/diego/code/lp1/projeto-1/src/main.cpp > CMakeFiles/keno.dir/src/main.cpp.i

CMakeFiles/keno.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/keno.dir/src/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/diego/code/lp1/projeto-1/src/main.cpp -o CMakeFiles/keno.dir/src/main.cpp.s

# Object files for target keno
keno_OBJECTS = \
"CMakeFiles/keno.dir/src/main.cpp.o"

# External object files for target keno
keno_EXTERNAL_OBJECTS =

keno: CMakeFiles/keno.dir/src/main.cpp.o
keno: CMakeFiles/keno.dir/build.make
keno: CMakeFiles/keno.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/diego/code/lp1/projeto-1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable keno"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/keno.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/keno.dir/build: keno

.PHONY : CMakeFiles/keno.dir/build

CMakeFiles/keno.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/keno.dir/cmake_clean.cmake
.PHONY : CMakeFiles/keno.dir/clean

CMakeFiles/keno.dir/depend:
	cd /home/diego/code/lp1/projeto-1/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/diego/code/lp1/projeto-1 /home/diego/code/lp1/projeto-1 /home/diego/code/lp1/projeto-1/build /home/diego/code/lp1/projeto-1/build /home/diego/code/lp1/projeto-1/build/CMakeFiles/keno.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/keno.dir/depend

