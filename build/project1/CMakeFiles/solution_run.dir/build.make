# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.15

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
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.15.0/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.15.0/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/zhangjiashuo/Desktop/CompilerProject-2020Spring-Part1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/zhangjiashuo/Desktop/CompilerProject-2020Spring-Part1/build

# Utility rule file for solution_run.

# Include the progress variables for this target.
include project1/CMakeFiles/solution_run.dir/progress.make

project1/CMakeFiles/solution_run:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/Users/zhangjiashuo/Desktop/CompilerProject-2020Spring-Part1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "run generated solution in /Users/zhangjiashuo/Desktop/CompilerProject-2020Spring-Part1/project1"
	cd /Users/zhangjiashuo/Desktop/CompilerProject-2020Spring-Part1/project1 && /Users/zhangjiashuo/Desktop/CompilerProject-2020Spring-Part1/build/project1/solution

solution_run: project1/CMakeFiles/solution_run
solution_run: project1/CMakeFiles/solution_run.dir/build.make

.PHONY : solution_run

# Rule to build all files generated by this target.
project1/CMakeFiles/solution_run.dir/build: solution_run

.PHONY : project1/CMakeFiles/solution_run.dir/build

project1/CMakeFiles/solution_run.dir/clean:
	cd /Users/zhangjiashuo/Desktop/CompilerProject-2020Spring-Part1/build/project1 && $(CMAKE_COMMAND) -P CMakeFiles/solution_run.dir/cmake_clean.cmake
.PHONY : project1/CMakeFiles/solution_run.dir/clean

project1/CMakeFiles/solution_run.dir/depend:
	cd /Users/zhangjiashuo/Desktop/CompilerProject-2020Spring-Part1/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/zhangjiashuo/Desktop/CompilerProject-2020Spring-Part1 /Users/zhangjiashuo/Desktop/CompilerProject-2020Spring-Part1/project1 /Users/zhangjiashuo/Desktop/CompilerProject-2020Spring-Part1/build /Users/zhangjiashuo/Desktop/CompilerProject-2020Spring-Part1/build/project1 /Users/zhangjiashuo/Desktop/CompilerProject-2020Spring-Part1/build/project1/CMakeFiles/solution_run.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : project1/CMakeFiles/solution_run.dir/depend

