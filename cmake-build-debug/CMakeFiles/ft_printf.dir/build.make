# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.13

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
CMAKE_SOURCE_DIR = /Users/vtlostiu/Desktop/fdf_clion

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/vtlostiu/Desktop/fdf_clion/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/ft_printf.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/ft_printf.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ft_printf.dir/flags.make

CMakeFiles/ft_printf.dir/error_messages.c.o: CMakeFiles/ft_printf.dir/flags.make
CMakeFiles/ft_printf.dir/error_messages.c.o: ../error_messages.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/vtlostiu/Desktop/fdf_clion/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/ft_printf.dir/error_messages.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/ft_printf.dir/error_messages.c.o   -c /Users/vtlostiu/Desktop/fdf_clion/error_messages.c

CMakeFiles/ft_printf.dir/error_messages.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/ft_printf.dir/error_messages.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/vtlostiu/Desktop/fdf_clion/error_messages.c > CMakeFiles/ft_printf.dir/error_messages.c.i

CMakeFiles/ft_printf.dir/error_messages.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/ft_printf.dir/error_messages.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/vtlostiu/Desktop/fdf_clion/error_messages.c -o CMakeFiles/ft_printf.dir/error_messages.c.s

CMakeFiles/ft_printf.dir/main.c.o: CMakeFiles/ft_printf.dir/flags.make
CMakeFiles/ft_printf.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/vtlostiu/Desktop/fdf_clion/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/ft_printf.dir/main.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/ft_printf.dir/main.c.o   -c /Users/vtlostiu/Desktop/fdf_clion/main.c

CMakeFiles/ft_printf.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/ft_printf.dir/main.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/vtlostiu/Desktop/fdf_clion/main.c > CMakeFiles/ft_printf.dir/main.c.i

CMakeFiles/ft_printf.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/ft_printf.dir/main.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/vtlostiu/Desktop/fdf_clion/main.c -o CMakeFiles/ft_printf.dir/main.c.s

# Object files for target ft_printf
ft_printf_OBJECTS = \
"CMakeFiles/ft_printf.dir/error_messages.c.o" \
"CMakeFiles/ft_printf.dir/main.c.o"

# External object files for target ft_printf
ft_printf_EXTERNAL_OBJECTS =

ft_printf: CMakeFiles/ft_printf.dir/error_messages.c.o
ft_printf: CMakeFiles/ft_printf.dir/main.c.o
ft_printf: CMakeFiles/ft_printf.dir/build.make
ft_printf: CMakeFiles/ft_printf.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/vtlostiu/Desktop/fdf_clion/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable ft_printf"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ft_printf.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ft_printf.dir/build: ft_printf

.PHONY : CMakeFiles/ft_printf.dir/build

CMakeFiles/ft_printf.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ft_printf.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ft_printf.dir/clean

CMakeFiles/ft_printf.dir/depend:
	cd /Users/vtlostiu/Desktop/fdf_clion/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/vtlostiu/Desktop/fdf_clion /Users/vtlostiu/Desktop/fdf_clion /Users/vtlostiu/Desktop/fdf_clion/cmake-build-debug /Users/vtlostiu/Desktop/fdf_clion/cmake-build-debug /Users/vtlostiu/Desktop/fdf_clion/cmake-build-debug/CMakeFiles/ft_printf.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/ft_printf.dir/depend

