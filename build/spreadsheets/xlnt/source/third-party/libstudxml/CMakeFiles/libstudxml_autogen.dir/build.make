# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/patrick/Projects/sr.ht/micro-desktop

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/patrick/Projects/sr.ht/micro-desktop/build

# Utility rule file for libstudxml_autogen.

# Include any custom commands dependencies for this target.
include spreadsheets/xlnt/source/third-party/libstudxml/CMakeFiles/libstudxml_autogen.dir/compiler_depend.make

# Include the progress variables for this target.
include spreadsheets/xlnt/source/third-party/libstudxml/CMakeFiles/libstudxml_autogen.dir/progress.make

spreadsheets/xlnt/source/third-party/libstudxml/CMakeFiles/libstudxml_autogen:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/patrick/Projects/sr.ht/micro-desktop/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Automatic MOC and UIC for target libstudxml"
	cd /home/patrick/Projects/sr.ht/micro-desktop/build/spreadsheets/xlnt/source/third-party/libstudxml && /usr/bin/cmake -E cmake_autogen /home/patrick/Projects/sr.ht/micro-desktop/build/spreadsheets/xlnt/source/third-party/libstudxml/CMakeFiles/libstudxml_autogen.dir/AutogenInfo.json ""

libstudxml_autogen: spreadsheets/xlnt/source/third-party/libstudxml/CMakeFiles/libstudxml_autogen
libstudxml_autogen: spreadsheets/xlnt/source/third-party/libstudxml/CMakeFiles/libstudxml_autogen.dir/build.make
.PHONY : libstudxml_autogen

# Rule to build all files generated by this target.
spreadsheets/xlnt/source/third-party/libstudxml/CMakeFiles/libstudxml_autogen.dir/build: libstudxml_autogen
.PHONY : spreadsheets/xlnt/source/third-party/libstudxml/CMakeFiles/libstudxml_autogen.dir/build

spreadsheets/xlnt/source/third-party/libstudxml/CMakeFiles/libstudxml_autogen.dir/clean:
	cd /home/patrick/Projects/sr.ht/micro-desktop/build/spreadsheets/xlnt/source/third-party/libstudxml && $(CMAKE_COMMAND) -P CMakeFiles/libstudxml_autogen.dir/cmake_clean.cmake
.PHONY : spreadsheets/xlnt/source/third-party/libstudxml/CMakeFiles/libstudxml_autogen.dir/clean

spreadsheets/xlnt/source/third-party/libstudxml/CMakeFiles/libstudxml_autogen.dir/depend:
	cd /home/patrick/Projects/sr.ht/micro-desktop/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/patrick/Projects/sr.ht/micro-desktop /home/patrick/Projects/sr.ht/micro-desktop/spreadsheets/xlnt/third-party/libstudxml /home/patrick/Projects/sr.ht/micro-desktop/build /home/patrick/Projects/sr.ht/micro-desktop/build/spreadsheets/xlnt/source/third-party/libstudxml /home/patrick/Projects/sr.ht/micro-desktop/build/spreadsheets/xlnt/source/third-party/libstudxml/CMakeFiles/libstudxml_autogen.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : spreadsheets/xlnt/source/third-party/libstudxml/CMakeFiles/libstudxml_autogen.dir/depend

