# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.17

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

# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "D:\Installed games and programs\C++\CLion 2020.2\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "D:\Installed games and programs\C++\CLion 2020.2\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "D:\Dino\Programiranje\Metode implementacije funkcije kvadratnog korjenovanja u kompjuterskoj nauci\Cpp kodovi\Korjenovanje Newton-ovom metodom"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "D:\Dino\Programiranje\Metode implementacije funkcije kvadratnog korjenovanja u kompjuterskoj nauci\Cpp kodovi\Korjenovanje Newton-ovom metodom\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/Korjenovanje_Newton_ovom_metodom.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Korjenovanje_Newton_ovom_metodom.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Korjenovanje_Newton_ovom_metodom.dir/flags.make

CMakeFiles/Korjenovanje_Newton_ovom_metodom.dir/main.cpp.obj: CMakeFiles/Korjenovanje_Newton_ovom_metodom.dir/flags.make
CMakeFiles/Korjenovanje_Newton_ovom_metodom.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="D:\Dino\Programiranje\Metode implementacije funkcije kvadratnog korjenovanja u kompjuterskoj nauci\Cpp kodovi\Korjenovanje Newton-ovom metodom\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Korjenovanje_Newton_ovom_metodom.dir/main.cpp.obj"
	"D:\Installed games and programs\C++\MinGW\mingw64\bin\g++.exe"  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Korjenovanje_Newton_ovom_metodom.dir\main.cpp.obj -c "D:\Dino\Programiranje\Metode implementacije funkcije kvadratnog korjenovanja u kompjuterskoj nauci\Cpp kodovi\Korjenovanje Newton-ovom metodom\main.cpp"

CMakeFiles/Korjenovanje_Newton_ovom_metodom.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Korjenovanje_Newton_ovom_metodom.dir/main.cpp.i"
	"D:\Installed games and programs\C++\MinGW\mingw64\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "D:\Dino\Programiranje\Metode implementacije funkcije kvadratnog korjenovanja u kompjuterskoj nauci\Cpp kodovi\Korjenovanje Newton-ovom metodom\main.cpp" > CMakeFiles\Korjenovanje_Newton_ovom_metodom.dir\main.cpp.i

CMakeFiles/Korjenovanje_Newton_ovom_metodom.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Korjenovanje_Newton_ovom_metodom.dir/main.cpp.s"
	"D:\Installed games and programs\C++\MinGW\mingw64\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "D:\Dino\Programiranje\Metode implementacije funkcije kvadratnog korjenovanja u kompjuterskoj nauci\Cpp kodovi\Korjenovanje Newton-ovom metodom\main.cpp" -o CMakeFiles\Korjenovanje_Newton_ovom_metodom.dir\main.cpp.s

# Object files for target Korjenovanje_Newton_ovom_metodom
Korjenovanje_Newton_ovom_metodom_OBJECTS = \
"CMakeFiles/Korjenovanje_Newton_ovom_metodom.dir/main.cpp.obj"

# External object files for target Korjenovanje_Newton_ovom_metodom
Korjenovanje_Newton_ovom_metodom_EXTERNAL_OBJECTS =

Korjenovanje_Newton_ovom_metodom.exe: CMakeFiles/Korjenovanje_Newton_ovom_metodom.dir/main.cpp.obj
Korjenovanje_Newton_ovom_metodom.exe: CMakeFiles/Korjenovanje_Newton_ovom_metodom.dir/build.make
Korjenovanje_Newton_ovom_metodom.exe: CMakeFiles/Korjenovanje_Newton_ovom_metodom.dir/linklibs.rsp
Korjenovanje_Newton_ovom_metodom.exe: CMakeFiles/Korjenovanje_Newton_ovom_metodom.dir/objects1.rsp
Korjenovanje_Newton_ovom_metodom.exe: CMakeFiles/Korjenovanje_Newton_ovom_metodom.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="D:\Dino\Programiranje\Metode implementacije funkcije kvadratnog korjenovanja u kompjuterskoj nauci\Cpp kodovi\Korjenovanje Newton-ovom metodom\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Korjenovanje_Newton_ovom_metodom.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Korjenovanje_Newton_ovom_metodom.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Korjenovanje_Newton_ovom_metodom.dir/build: Korjenovanje_Newton_ovom_metodom.exe

.PHONY : CMakeFiles/Korjenovanje_Newton_ovom_metodom.dir/build

CMakeFiles/Korjenovanje_Newton_ovom_metodom.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Korjenovanje_Newton_ovom_metodom.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Korjenovanje_Newton_ovom_metodom.dir/clean

CMakeFiles/Korjenovanje_Newton_ovom_metodom.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "D:\Dino\Programiranje\Metode implementacije funkcije kvadratnog korjenovanja u kompjuterskoj nauci\Cpp kodovi\Korjenovanje Newton-ovom metodom" "D:\Dino\Programiranje\Metode implementacije funkcije kvadratnog korjenovanja u kompjuterskoj nauci\Cpp kodovi\Korjenovanje Newton-ovom metodom" "D:\Dino\Programiranje\Metode implementacije funkcije kvadratnog korjenovanja u kompjuterskoj nauci\Cpp kodovi\Korjenovanje Newton-ovom metodom\cmake-build-debug" "D:\Dino\Programiranje\Metode implementacije funkcije kvadratnog korjenovanja u kompjuterskoj nauci\Cpp kodovi\Korjenovanje Newton-ovom metodom\cmake-build-debug" "D:\Dino\Programiranje\Metode implementacije funkcije kvadratnog korjenovanja u kompjuterskoj nauci\Cpp kodovi\Korjenovanje Newton-ovom metodom\cmake-build-debug\CMakeFiles\Korjenovanje_Newton_ovom_metodom.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/Korjenovanje_Newton_ovom_metodom.dir/depend

