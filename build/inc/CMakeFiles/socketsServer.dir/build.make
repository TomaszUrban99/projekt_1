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
CMAKE_SOURCE_DIR = /home/tomasz/Documents/Studia/PAMSI/Projekt1/Stos

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/tomasz/Documents/Studia/PAMSI/Projekt1/Stos/build

# Include any dependencies generated for this target.
include inc/CMakeFiles/socketsServer.dir/depend.make

# Include the progress variables for this target.
include inc/CMakeFiles/socketsServer.dir/progress.make

# Include the compile flags for this target's objects.
include inc/CMakeFiles/socketsServer.dir/flags.make

# Object files for target socketsServer
socketsServer_OBJECTS =

# External object files for target socketsServer
socketsServer_EXTERNAL_OBJECTS =

inc/libsocketsServer.a: inc/CMakeFiles/socketsServer.dir/build.make
inc/libsocketsServer.a: inc/CMakeFiles/socketsServer.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/tomasz/Documents/Studia/PAMSI/Projekt1/Stos/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Linking CXX static library libsocketsServer.a"
	cd /home/tomasz/Documents/Studia/PAMSI/Projekt1/Stos/build/inc && $(CMAKE_COMMAND) -P CMakeFiles/socketsServer.dir/cmake_clean_target.cmake
	cd /home/tomasz/Documents/Studia/PAMSI/Projekt1/Stos/build/inc && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/socketsServer.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
inc/CMakeFiles/socketsServer.dir/build: inc/libsocketsServer.a

.PHONY : inc/CMakeFiles/socketsServer.dir/build

inc/CMakeFiles/socketsServer.dir/clean:
	cd /home/tomasz/Documents/Studia/PAMSI/Projekt1/Stos/build/inc && $(CMAKE_COMMAND) -P CMakeFiles/socketsServer.dir/cmake_clean.cmake
.PHONY : inc/CMakeFiles/socketsServer.dir/clean

inc/CMakeFiles/socketsServer.dir/depend:
	cd /home/tomasz/Documents/Studia/PAMSI/Projekt1/Stos/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/tomasz/Documents/Studia/PAMSI/Projekt1/Stos /home/tomasz/Documents/Studia/PAMSI/Projekt1/Stos/inc /home/tomasz/Documents/Studia/PAMSI/Projekt1/Stos/build /home/tomasz/Documents/Studia/PAMSI/Projekt1/Stos/build/inc /home/tomasz/Documents/Studia/PAMSI/Projekt1/Stos/build/inc/CMakeFiles/socketsServer.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : inc/CMakeFiles/socketsServer.dir/depend

