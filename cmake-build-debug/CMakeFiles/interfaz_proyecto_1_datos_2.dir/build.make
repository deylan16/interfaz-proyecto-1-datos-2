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
CMAKE_COMMAND = /home/deylan/Descargas/CLion-2021.2.1/clion-2021.2.1/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/deylan/Descargas/CLion-2021.2.1/clion-2021.2.1/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/deylan/Escritorio/interfaz-proyecto-1-datos-2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/deylan/Escritorio/interfaz-proyecto-1-datos-2/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/interfaz_proyecto_1_datos_2.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/interfaz_proyecto_1_datos_2.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/interfaz_proyecto_1_datos_2.dir/flags.make

CMakeFiles/interfaz_proyecto_1_datos_2.dir/main.cpp.o: CMakeFiles/interfaz_proyecto_1_datos_2.dir/flags.make
CMakeFiles/interfaz_proyecto_1_datos_2.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/deylan/Escritorio/interfaz-proyecto-1-datos-2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/interfaz_proyecto_1_datos_2.dir/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/interfaz_proyecto_1_datos_2.dir/main.cpp.o -c /home/deylan/Escritorio/interfaz-proyecto-1-datos-2/main.cpp

CMakeFiles/interfaz_proyecto_1_datos_2.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/interfaz_proyecto_1_datos_2.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/deylan/Escritorio/interfaz-proyecto-1-datos-2/main.cpp > CMakeFiles/interfaz_proyecto_1_datos_2.dir/main.cpp.i

CMakeFiles/interfaz_proyecto_1_datos_2.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/interfaz_proyecto_1_datos_2.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/deylan/Escritorio/interfaz-proyecto-1-datos-2/main.cpp -o CMakeFiles/interfaz_proyecto_1_datos_2.dir/main.cpp.s

# Object files for target interfaz_proyecto_1_datos_2
interfaz_proyecto_1_datos_2_OBJECTS = \
"CMakeFiles/interfaz_proyecto_1_datos_2.dir/main.cpp.o"

# External object files for target interfaz_proyecto_1_datos_2
interfaz_proyecto_1_datos_2_EXTERNAL_OBJECTS =

interfaz_proyecto_1_datos_2: CMakeFiles/interfaz_proyecto_1_datos_2.dir/main.cpp.o
interfaz_proyecto_1_datos_2: CMakeFiles/interfaz_proyecto_1_datos_2.dir/build.make
interfaz_proyecto_1_datos_2: CMakeFiles/interfaz_proyecto_1_datos_2.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/deylan/Escritorio/interfaz-proyecto-1-datos-2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable interfaz_proyecto_1_datos_2"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/interfaz_proyecto_1_datos_2.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/interfaz_proyecto_1_datos_2.dir/build: interfaz_proyecto_1_datos_2
.PHONY : CMakeFiles/interfaz_proyecto_1_datos_2.dir/build

CMakeFiles/interfaz_proyecto_1_datos_2.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/interfaz_proyecto_1_datos_2.dir/cmake_clean.cmake
.PHONY : CMakeFiles/interfaz_proyecto_1_datos_2.dir/clean

CMakeFiles/interfaz_proyecto_1_datos_2.dir/depend:
	cd /home/deylan/Escritorio/interfaz-proyecto-1-datos-2/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/deylan/Escritorio/interfaz-proyecto-1-datos-2 /home/deylan/Escritorio/interfaz-proyecto-1-datos-2 /home/deylan/Escritorio/interfaz-proyecto-1-datos-2/cmake-build-debug /home/deylan/Escritorio/interfaz-proyecto-1-datos-2/cmake-build-debug /home/deylan/Escritorio/interfaz-proyecto-1-datos-2/cmake-build-debug/CMakeFiles/interfaz_proyecto_1_datos_2.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/interfaz_proyecto_1_datos_2.dir/depend

