# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.20

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
CMAKE_COMMAND = /home/samuel/clion-2021.2.3/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/samuel/clion-2021.2.3/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/samuel/Documents/c++/DT064G/sorting_competition

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/samuel/Documents/c++/DT064G/sorting_competition/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/comp.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/comp.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/comp.dir/flags.make

CMakeFiles/comp.dir/main.cpp.o: CMakeFiles/comp.dir/flags.make
CMakeFiles/comp.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/samuel/Documents/c++/DT064G/sorting_competition/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/comp.dir/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/comp.dir/main.cpp.o -c /home/samuel/Documents/c++/DT064G/sorting_competition/main.cpp

CMakeFiles/comp.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/comp.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/samuel/Documents/c++/DT064G/sorting_competition/main.cpp > CMakeFiles/comp.dir/main.cpp.i

CMakeFiles/comp.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/comp.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/samuel/Documents/c++/DT064G/sorting_competition/main.cpp -o CMakeFiles/comp.dir/main.cpp.s

CMakeFiles/comp.dir/timer.cpp.o: CMakeFiles/comp.dir/flags.make
CMakeFiles/comp.dir/timer.cpp.o: ../timer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/samuel/Documents/c++/DT064G/sorting_competition/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/comp.dir/timer.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/comp.dir/timer.cpp.o -c /home/samuel/Documents/c++/DT064G/sorting_competition/timer.cpp

CMakeFiles/comp.dir/timer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/comp.dir/timer.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/samuel/Documents/c++/DT064G/sorting_competition/timer.cpp > CMakeFiles/comp.dir/timer.cpp.i

CMakeFiles/comp.dir/timer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/comp.dir/timer.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/samuel/Documents/c++/DT064G/sorting_competition/timer.cpp -o CMakeFiles/comp.dir/timer.cpp.s

CMakeFiles/comp.dir/reader.cpp.o: CMakeFiles/comp.dir/flags.make
CMakeFiles/comp.dir/reader.cpp.o: ../reader.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/samuel/Documents/c++/DT064G/sorting_competition/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/comp.dir/reader.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/comp.dir/reader.cpp.o -c /home/samuel/Documents/c++/DT064G/sorting_competition/reader.cpp

CMakeFiles/comp.dir/reader.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/comp.dir/reader.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/samuel/Documents/c++/DT064G/sorting_competition/reader.cpp > CMakeFiles/comp.dir/reader.cpp.i

CMakeFiles/comp.dir/reader.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/comp.dir/reader.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/samuel/Documents/c++/DT064G/sorting_competition/reader.cpp -o CMakeFiles/comp.dir/reader.cpp.s

# Object files for target comp
comp_OBJECTS = \
"CMakeFiles/comp.dir/main.cpp.o" \
"CMakeFiles/comp.dir/timer.cpp.o" \
"CMakeFiles/comp.dir/reader.cpp.o"

# External object files for target comp
comp_EXTERNAL_OBJECTS =

comp: CMakeFiles/comp.dir/main.cpp.o
comp: CMakeFiles/comp.dir/timer.cpp.o
comp: CMakeFiles/comp.dir/reader.cpp.o
comp: CMakeFiles/comp.dir/build.make
comp: CMakeFiles/comp.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/samuel/Documents/c++/DT064G/sorting_competition/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable comp"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/comp.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/comp.dir/build: comp
.PHONY : CMakeFiles/comp.dir/build

CMakeFiles/comp.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/comp.dir/cmake_clean.cmake
.PHONY : CMakeFiles/comp.dir/clean

CMakeFiles/comp.dir/depend:
	cd /home/samuel/Documents/c++/DT064G/sorting_competition/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/samuel/Documents/c++/DT064G/sorting_competition /home/samuel/Documents/c++/DT064G/sorting_competition /home/samuel/Documents/c++/DT064G/sorting_competition/cmake-build-debug /home/samuel/Documents/c++/DT064G/sorting_competition/cmake-build-debug /home/samuel/Documents/c++/DT064G/sorting_competition/cmake-build-debug/CMakeFiles/comp.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/comp.dir/depend

