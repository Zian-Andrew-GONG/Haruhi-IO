# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.23

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /Applications/CMake.app/Contents/bin/cmake

# The command to remove a file.
RM = /Applications/CMake.app/Contents/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/gongzian/src/Haruhi-IO

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/gongzian/src/Haruhi-IO/cmake-build

# Include any dependencies generated for this target.
include include/CMakeFiles/haruhi-timer.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include include/CMakeFiles/haruhi-timer.dir/compiler_depend.make

# Include the progress variables for this target.
include include/CMakeFiles/haruhi-timer.dir/progress.make

# Include the compile flags for this target's objects.
include include/CMakeFiles/haruhi-timer.dir/flags.make

include/CMakeFiles/haruhi-timer.dir/haruhi-timer.cpp.o: include/CMakeFiles/haruhi-timer.dir/flags.make
include/CMakeFiles/haruhi-timer.dir/haruhi-timer.cpp.o: ../include/haruhi-timer.cpp
include/CMakeFiles/haruhi-timer.dir/haruhi-timer.cpp.o: include/CMakeFiles/haruhi-timer.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/gongzian/src/Haruhi-IO/cmake-build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object include/CMakeFiles/haruhi-timer.dir/haruhi-timer.cpp.o"
	cd /Users/gongzian/src/Haruhi-IO/cmake-build/include && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT include/CMakeFiles/haruhi-timer.dir/haruhi-timer.cpp.o -MF CMakeFiles/haruhi-timer.dir/haruhi-timer.cpp.o.d -o CMakeFiles/haruhi-timer.dir/haruhi-timer.cpp.o -c /Users/gongzian/src/Haruhi-IO/include/haruhi-timer.cpp

include/CMakeFiles/haruhi-timer.dir/haruhi-timer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/haruhi-timer.dir/haruhi-timer.cpp.i"
	cd /Users/gongzian/src/Haruhi-IO/cmake-build/include && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/gongzian/src/Haruhi-IO/include/haruhi-timer.cpp > CMakeFiles/haruhi-timer.dir/haruhi-timer.cpp.i

include/CMakeFiles/haruhi-timer.dir/haruhi-timer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/haruhi-timer.dir/haruhi-timer.cpp.s"
	cd /Users/gongzian/src/Haruhi-IO/cmake-build/include && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/gongzian/src/Haruhi-IO/include/haruhi-timer.cpp -o CMakeFiles/haruhi-timer.dir/haruhi-timer.cpp.s

# Object files for target haruhi-timer
haruhi__timer_OBJECTS = \
"CMakeFiles/haruhi-timer.dir/haruhi-timer.cpp.o"

# External object files for target haruhi-timer
haruhi__timer_EXTERNAL_OBJECTS =

include/libharuhi-timer.a: include/CMakeFiles/haruhi-timer.dir/haruhi-timer.cpp.o
include/libharuhi-timer.a: include/CMakeFiles/haruhi-timer.dir/build.make
include/libharuhi-timer.a: include/CMakeFiles/haruhi-timer.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/gongzian/src/Haruhi-IO/cmake-build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libharuhi-timer.a"
	cd /Users/gongzian/src/Haruhi-IO/cmake-build/include && $(CMAKE_COMMAND) -P CMakeFiles/haruhi-timer.dir/cmake_clean_target.cmake
	cd /Users/gongzian/src/Haruhi-IO/cmake-build/include && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/haruhi-timer.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
include/CMakeFiles/haruhi-timer.dir/build: include/libharuhi-timer.a
.PHONY : include/CMakeFiles/haruhi-timer.dir/build

include/CMakeFiles/haruhi-timer.dir/clean:
	cd /Users/gongzian/src/Haruhi-IO/cmake-build/include && $(CMAKE_COMMAND) -P CMakeFiles/haruhi-timer.dir/cmake_clean.cmake
.PHONY : include/CMakeFiles/haruhi-timer.dir/clean

include/CMakeFiles/haruhi-timer.dir/depend:
	cd /Users/gongzian/src/Haruhi-IO/cmake-build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/gongzian/src/Haruhi-IO /Users/gongzian/src/Haruhi-IO/include /Users/gongzian/src/Haruhi-IO/cmake-build /Users/gongzian/src/Haruhi-IO/cmake-build/include /Users/gongzian/src/Haruhi-IO/cmake-build/include/CMakeFiles/haruhi-timer.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : include/CMakeFiles/haruhi-timer.dir/depend

