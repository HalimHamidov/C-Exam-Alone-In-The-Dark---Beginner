# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.14

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/apearl/Desktop/42-exam-miner-/level1/first_word

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/apearl/Desktop/42-exam-miner-/level1/first_word/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/first_word.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/first_word.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/first_word.dir/flags.make

CMakeFiles/first_word.dir/first_word.c.o: CMakeFiles/first_word.dir/flags.make
CMakeFiles/first_word.dir/first_word.c.o: ../first_word.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/apearl/Desktop/42-exam-miner-/level1/first_word/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/first_word.dir/first_word.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/first_word.dir/first_word.c.o   -c /Users/apearl/Desktop/42-exam-miner-/level1/first_word/first_word.c

CMakeFiles/first_word.dir/first_word.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/first_word.dir/first_word.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/apearl/Desktop/42-exam-miner-/level1/first_word/first_word.c > CMakeFiles/first_word.dir/first_word.c.i

CMakeFiles/first_word.dir/first_word.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/first_word.dir/first_word.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/apearl/Desktop/42-exam-miner-/level1/first_word/first_word.c -o CMakeFiles/first_word.dir/first_word.c.s

# Object files for target first_word
first_word_OBJECTS = \
"CMakeFiles/first_word.dir/first_word.c.o"

# External object files for target first_word
first_word_EXTERNAL_OBJECTS =

first_word: CMakeFiles/first_word.dir/first_word.c.o
first_word: CMakeFiles/first_word.dir/build.make
first_word: CMakeFiles/first_word.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/apearl/Desktop/42-exam-miner-/level1/first_word/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable first_word"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/first_word.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/first_word.dir/build: first_word

.PHONY : CMakeFiles/first_word.dir/build

CMakeFiles/first_word.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/first_word.dir/cmake_clean.cmake
.PHONY : CMakeFiles/first_word.dir/clean

CMakeFiles/first_word.dir/depend:
	cd /Users/apearl/Desktop/42-exam-miner-/level1/first_word/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/apearl/Desktop/42-exam-miner-/level1/first_word /Users/apearl/Desktop/42-exam-miner-/level1/first_word /Users/apearl/Desktop/42-exam-miner-/level1/first_word/cmake-build-debug /Users/apearl/Desktop/42-exam-miner-/level1/first_word/cmake-build-debug /Users/apearl/Desktop/42-exam-miner-/level1/first_word/cmake-build-debug/CMakeFiles/first_word.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/first_word.dir/depend

