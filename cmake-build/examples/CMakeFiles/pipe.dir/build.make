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
CMAKE_SOURCE_DIR = /home/gongzian/src/Haruhi-IO

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/gongzian/src/Haruhi-IO/cmake-build

# Include any dependencies generated for this target.
include examples/CMakeFiles/pipe.dir/depend.make

# Include the progress variables for this target.
include examples/CMakeFiles/pipe.dir/progress.make

# Include the compile flags for this target's objects.
include examples/CMakeFiles/pipe.dir/flags.make

examples/CMakeFiles/pipe.dir/pipe.cpp.o: examples/CMakeFiles/pipe.dir/flags.make
examples/CMakeFiles/pipe.dir/pipe.cpp.o: ../examples/pipe.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/gongzian/src/Haruhi-IO/cmake-build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object examples/CMakeFiles/pipe.dir/pipe.cpp.o"
	cd /home/gongzian/src/Haruhi-IO/cmake-build/examples && /usr/bin/g++-10  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/pipe.dir/pipe.cpp.o -c /home/gongzian/src/Haruhi-IO/examples/pipe.cpp

examples/CMakeFiles/pipe.dir/pipe.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/pipe.dir/pipe.cpp.i"
	cd /home/gongzian/src/Haruhi-IO/cmake-build/examples && /usr/bin/g++-10 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/gongzian/src/Haruhi-IO/examples/pipe.cpp > CMakeFiles/pipe.dir/pipe.cpp.i

examples/CMakeFiles/pipe.dir/pipe.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/pipe.dir/pipe.cpp.s"
	cd /home/gongzian/src/Haruhi-IO/cmake-build/examples && /usr/bin/g++-10 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/gongzian/src/Haruhi-IO/examples/pipe.cpp -o CMakeFiles/pipe.dir/pipe.cpp.s

# Object files for target pipe
pipe_OBJECTS = \
"CMakeFiles/pipe.dir/pipe.cpp.o"

# External object files for target pipe
pipe_EXTERNAL_OBJECTS =

bin/pipe: examples/CMakeFiles/pipe.dir/pipe.cpp.o
bin/pipe: examples/CMakeFiles/pipe.dir/build.make
bin/pipe: src/libHaruhi.a
bin/pipe: examples/CMakeFiles/pipe.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/gongzian/src/Haruhi-IO/cmake-build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ../bin/pipe"
	cd /home/gongzian/src/Haruhi-IO/cmake-build/examples && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/pipe.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
examples/CMakeFiles/pipe.dir/build: bin/pipe

.PHONY : examples/CMakeFiles/pipe.dir/build

examples/CMakeFiles/pipe.dir/clean:
	cd /home/gongzian/src/Haruhi-IO/cmake-build/examples && $(CMAKE_COMMAND) -P CMakeFiles/pipe.dir/cmake_clean.cmake
.PHONY : examples/CMakeFiles/pipe.dir/clean

examples/CMakeFiles/pipe.dir/depend:
	cd /home/gongzian/src/Haruhi-IO/cmake-build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/gongzian/src/Haruhi-IO /home/gongzian/src/Haruhi-IO/examples /home/gongzian/src/Haruhi-IO/cmake-build /home/gongzian/src/Haruhi-IO/cmake-build/examples /home/gongzian/src/Haruhi-IO/cmake-build/examples/CMakeFiles/pipe.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : examples/CMakeFiles/pipe.dir/depend

