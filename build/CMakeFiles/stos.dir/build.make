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
include CMakeFiles/stos.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/stos.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/stos.dir/flags.make

CMakeFiles/stos.dir/src/main.cpp.o: CMakeFiles/stos.dir/flags.make
CMakeFiles/stos.dir/src/main.cpp.o: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/tomasz/Documents/Studia/PAMSI/Projekt1/Stos/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/stos.dir/src/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/stos.dir/src/main.cpp.o -c /home/tomasz/Documents/Studia/PAMSI/Projekt1/Stos/src/main.cpp

CMakeFiles/stos.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/stos.dir/src/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/tomasz/Documents/Studia/PAMSI/Projekt1/Stos/src/main.cpp > CMakeFiles/stos.dir/src/main.cpp.i

CMakeFiles/stos.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/stos.dir/src/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/tomasz/Documents/Studia/PAMSI/Projekt1/Stos/src/main.cpp -o CMakeFiles/stos.dir/src/main.cpp.s

# Object files for target stos
stos_OBJECTS = \
"CMakeFiles/stos.dir/src/main.cpp.o"

# External object files for target stos
stos_EXTERNAL_OBJECTS =

stos: CMakeFiles/stos.dir/src/main.cpp.o
stos: CMakeFiles/stos.dir/build.make
stos: libstos_tablica.a
stos: inc/libstackList.a
stos: libsocket_server.a
stos: libfile_transfer.a
stos: inc/libstackNode.a
stos: CMakeFiles/stos.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/tomasz/Documents/Studia/PAMSI/Projekt1/Stos/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable stos"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/stos.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/stos.dir/build: stos

.PHONY : CMakeFiles/stos.dir/build

CMakeFiles/stos.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/stos.dir/cmake_clean.cmake
.PHONY : CMakeFiles/stos.dir/clean

CMakeFiles/stos.dir/depend:
	cd /home/tomasz/Documents/Studia/PAMSI/Projekt1/Stos/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/tomasz/Documents/Studia/PAMSI/Projekt1/Stos /home/tomasz/Documents/Studia/PAMSI/Projekt1/Stos /home/tomasz/Documents/Studia/PAMSI/Projekt1/Stos/build /home/tomasz/Documents/Studia/PAMSI/Projekt1/Stos/build /home/tomasz/Documents/Studia/PAMSI/Projekt1/Stos/build/CMakeFiles/stos.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/stos.dir/depend

