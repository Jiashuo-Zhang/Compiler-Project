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

# Include any dependencies generated for this target.
include test/CMakeFiles/gemm.dir/depend.make

# Include the progress variables for this target.
include test/CMakeFiles/gemm.dir/progress.make

# Include the compile flags for this target's objects.
include test/CMakeFiles/gemm.dir/flags.make

test/CMakeFiles/gemm.dir/gemm.cc.o: test/CMakeFiles/gemm.dir/flags.make
test/CMakeFiles/gemm.dir/gemm.cc.o: ../test/gemm.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/zhangjiashuo/Desktop/CompilerProject-2020Spring-Part1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object test/CMakeFiles/gemm.dir/gemm.cc.o"
	cd /Users/zhangjiashuo/Desktop/CompilerProject-2020Spring-Part1/build/test && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/gemm.dir/gemm.cc.o -c /Users/zhangjiashuo/Desktop/CompilerProject-2020Spring-Part1/test/gemm.cc

test/CMakeFiles/gemm.dir/gemm.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/gemm.dir/gemm.cc.i"
	cd /Users/zhangjiashuo/Desktop/CompilerProject-2020Spring-Part1/build/test && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/zhangjiashuo/Desktop/CompilerProject-2020Spring-Part1/test/gemm.cc > CMakeFiles/gemm.dir/gemm.cc.i

test/CMakeFiles/gemm.dir/gemm.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/gemm.dir/gemm.cc.s"
	cd /Users/zhangjiashuo/Desktop/CompilerProject-2020Spring-Part1/build/test && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/zhangjiashuo/Desktop/CompilerProject-2020Spring-Part1/test/gemm.cc -o CMakeFiles/gemm.dir/gemm.cc.s

# Object files for target gemm
gemm_OBJECTS = \
"CMakeFiles/gemm.dir/gemm.cc.o"

# External object files for target gemm
gemm_EXTERNAL_OBJECTS =

test/gemm: test/CMakeFiles/gemm.dir/gemm.cc.o
test/gemm: test/CMakeFiles/gemm.dir/build.make
test/gemm: libboost.dylib
test/gemm: test/CMakeFiles/gemm.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/zhangjiashuo/Desktop/CompilerProject-2020Spring-Part1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable gemm"
	cd /Users/zhangjiashuo/Desktop/CompilerProject-2020Spring-Part1/build/test && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/gemm.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
test/CMakeFiles/gemm.dir/build: test/gemm

.PHONY : test/CMakeFiles/gemm.dir/build

test/CMakeFiles/gemm.dir/clean:
	cd /Users/zhangjiashuo/Desktop/CompilerProject-2020Spring-Part1/build/test && $(CMAKE_COMMAND) -P CMakeFiles/gemm.dir/cmake_clean.cmake
.PHONY : test/CMakeFiles/gemm.dir/clean

test/CMakeFiles/gemm.dir/depend:
	cd /Users/zhangjiashuo/Desktop/CompilerProject-2020Spring-Part1/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/zhangjiashuo/Desktop/CompilerProject-2020Spring-Part1 /Users/zhangjiashuo/Desktop/CompilerProject-2020Spring-Part1/test /Users/zhangjiashuo/Desktop/CompilerProject-2020Spring-Part1/build /Users/zhangjiashuo/Desktop/CompilerProject-2020Spring-Part1/build/test /Users/zhangjiashuo/Desktop/CompilerProject-2020Spring-Part1/build/test/CMakeFiles/gemm.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : test/CMakeFiles/gemm.dir/depend

