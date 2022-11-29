# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.25

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
CMAKE_COMMAND = /Users/vicgarci/.brew/Cellar/cmake/3.25.0/bin/cmake

# The command to remove a file.
RM = /Users/vicgarci/.brew/Cellar/cmake/3.25.0/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/vicgarci/Desktop/glfw

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/vicgarci/Desktop/Felix/glfw_build

# Include any dependencies generated for this target.
include examples/CMakeFiles/triangle-opengl.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include examples/CMakeFiles/triangle-opengl.dir/compiler_depend.make

# Include the progress variables for this target.
include examples/CMakeFiles/triangle-opengl.dir/progress.make

# Include the compile flags for this target's objects.
include examples/CMakeFiles/triangle-opengl.dir/flags.make

examples/triangle-opengl.app/Contents/Resources/glfw.icns: /Users/vicgarci/Desktop/glfw/examples/glfw.icns
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Copying OS X content examples/triangle-opengl.app/Contents/Resources/glfw.icns"
	$(CMAKE_COMMAND) -E copy /Users/vicgarci/Desktop/glfw/examples/glfw.icns examples/triangle-opengl.app/Contents/Resources/glfw.icns

examples/CMakeFiles/triangle-opengl.dir/triangle-opengl.c.o: examples/CMakeFiles/triangle-opengl.dir/flags.make
examples/CMakeFiles/triangle-opengl.dir/triangle-opengl.c.o: /Users/vicgarci/Desktop/glfw/examples/triangle-opengl.c
examples/CMakeFiles/triangle-opengl.dir/triangle-opengl.c.o: examples/CMakeFiles/triangle-opengl.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/vicgarci/Desktop/Felix/glfw_build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object examples/CMakeFiles/triangle-opengl.dir/triangle-opengl.c.o"
	cd /Users/vicgarci/Desktop/Felix/glfw_build/examples && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT examples/CMakeFiles/triangle-opengl.dir/triangle-opengl.c.o -MF CMakeFiles/triangle-opengl.dir/triangle-opengl.c.o.d -o CMakeFiles/triangle-opengl.dir/triangle-opengl.c.o -c /Users/vicgarci/Desktop/glfw/examples/triangle-opengl.c

examples/CMakeFiles/triangle-opengl.dir/triangle-opengl.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/triangle-opengl.dir/triangle-opengl.c.i"
	cd /Users/vicgarci/Desktop/Felix/glfw_build/examples && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/vicgarci/Desktop/glfw/examples/triangle-opengl.c > CMakeFiles/triangle-opengl.dir/triangle-opengl.c.i

examples/CMakeFiles/triangle-opengl.dir/triangle-opengl.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/triangle-opengl.dir/triangle-opengl.c.s"
	cd /Users/vicgarci/Desktop/Felix/glfw_build/examples && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/vicgarci/Desktop/glfw/examples/triangle-opengl.c -o CMakeFiles/triangle-opengl.dir/triangle-opengl.c.s

# Object files for target triangle-opengl
triangle__opengl_OBJECTS = \
"CMakeFiles/triangle-opengl.dir/triangle-opengl.c.o"

# External object files for target triangle-opengl
triangle__opengl_EXTERNAL_OBJECTS =

examples/triangle-opengl.app/Contents/MacOS/triangle-opengl: examples/CMakeFiles/triangle-opengl.dir/triangle-opengl.c.o
examples/triangle-opengl.app/Contents/MacOS/triangle-opengl: examples/CMakeFiles/triangle-opengl.dir/build.make
examples/triangle-opengl.app/Contents/MacOS/triangle-opengl: src/libglfw3.a
examples/triangle-opengl.app/Contents/MacOS/triangle-opengl: examples/CMakeFiles/triangle-opengl.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/vicgarci/Desktop/Felix/glfw_build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable triangle-opengl.app/Contents/MacOS/triangle-opengl"
	cd /Users/vicgarci/Desktop/Felix/glfw_build/examples && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/triangle-opengl.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
examples/CMakeFiles/triangle-opengl.dir/build: examples/triangle-opengl.app/Contents/MacOS/triangle-opengl
examples/CMakeFiles/triangle-opengl.dir/build: examples/triangle-opengl.app/Contents/Resources/glfw.icns
.PHONY : examples/CMakeFiles/triangle-opengl.dir/build

examples/CMakeFiles/triangle-opengl.dir/clean:
	cd /Users/vicgarci/Desktop/Felix/glfw_build/examples && $(CMAKE_COMMAND) -P CMakeFiles/triangle-opengl.dir/cmake_clean.cmake
.PHONY : examples/CMakeFiles/triangle-opengl.dir/clean

examples/CMakeFiles/triangle-opengl.dir/depend:
	cd /Users/vicgarci/Desktop/Felix/glfw_build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/vicgarci/Desktop/glfw /Users/vicgarci/Desktop/glfw/examples /Users/vicgarci/Desktop/Felix/glfw_build /Users/vicgarci/Desktop/Felix/glfw_build/examples /Users/vicgarci/Desktop/Felix/glfw_build/examples/CMakeFiles/triangle-opengl.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : examples/CMakeFiles/triangle-opengl.dir/depend

