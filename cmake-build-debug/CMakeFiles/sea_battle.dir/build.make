# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.19

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
CMAKE_COMMAND = /home/linuxbrew/.linuxbrew/Cellar/cmake/3.19.1/bin/cmake

# The command to remove a file.
RM = /home/linuxbrew/.linuxbrew/Cellar/cmake/3.19.1/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/noisyboy/university/sea_battle

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/noisyboy/university/sea_battle/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/sea_battle.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/sea_battle.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/sea_battle.dir/flags.make

CMakeFiles/sea_battle.dir/main.c.o: CMakeFiles/sea_battle.dir/flags.make
CMakeFiles/sea_battle.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/noisyboy/university/sea_battle/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/sea_battle.dir/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/sea_battle.dir/main.c.o -c /home/noisyboy/university/sea_battle/main.c

CMakeFiles/sea_battle.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/sea_battle.dir/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/noisyboy/university/sea_battle/main.c > CMakeFiles/sea_battle.dir/main.c.i

CMakeFiles/sea_battle.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/sea_battle.dir/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/noisyboy/university/sea_battle/main.c -o CMakeFiles/sea_battle.dir/main.c.s

CMakeFiles/sea_battle.dir/menu/Menu.c.o: CMakeFiles/sea_battle.dir/flags.make
CMakeFiles/sea_battle.dir/menu/Menu.c.o: ../menu/Menu.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/noisyboy/university/sea_battle/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/sea_battle.dir/menu/Menu.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/sea_battle.dir/menu/Menu.c.o -c /home/noisyboy/university/sea_battle/menu/Menu.c

CMakeFiles/sea_battle.dir/menu/Menu.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/sea_battle.dir/menu/Menu.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/noisyboy/university/sea_battle/menu/Menu.c > CMakeFiles/sea_battle.dir/menu/Menu.c.i

CMakeFiles/sea_battle.dir/menu/Menu.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/sea_battle.dir/menu/Menu.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/noisyboy/university/sea_battle/menu/Menu.c -o CMakeFiles/sea_battle.dir/menu/Menu.c.s

# Object files for target sea_battle
sea_battle_OBJECTS = \
"CMakeFiles/sea_battle.dir/main.c.o" \
"CMakeFiles/sea_battle.dir/menu/Menu.c.o"

# External object files for target sea_battle
sea_battle_EXTERNAL_OBJECTS =

sea_battle: CMakeFiles/sea_battle.dir/main.c.o
sea_battle: CMakeFiles/sea_battle.dir/menu/Menu.c.o
sea_battle: CMakeFiles/sea_battle.dir/build.make
sea_battle: CMakeFiles/sea_battle.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/noisyboy/university/sea_battle/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable sea_battle"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/sea_battle.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/sea_battle.dir/build: sea_battle

.PHONY : CMakeFiles/sea_battle.dir/build

CMakeFiles/sea_battle.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/sea_battle.dir/cmake_clean.cmake
.PHONY : CMakeFiles/sea_battle.dir/clean

CMakeFiles/sea_battle.dir/depend:
	cd /home/noisyboy/university/sea_battle/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/noisyboy/university/sea_battle /home/noisyboy/university/sea_battle /home/noisyboy/university/sea_battle/cmake-build-debug /home/noisyboy/university/sea_battle/cmake-build-debug /home/noisyboy/university/sea_battle/cmake-build-debug/CMakeFiles/sea_battle.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/sea_battle.dir/depend

