# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.15

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = C:\Users\811243\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\193.5662.56\bin\cmake\win\bin\cmake.exe

# The command to remove a file.
RM = C:\Users\811243\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\193.5662.56\bin\cmake\win\bin\cmake.exe -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\811243\CLionProjects\Sopromat

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\811243\CLionProjects\Sopromat\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Sopromat.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Sopromat.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Sopromat.dir/flags.make

CMakeFiles/Sopromat.dir/main.cpp.obj: CMakeFiles/Sopromat.dir/flags.make
CMakeFiles/Sopromat.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\811243\CLionProjects\Sopromat\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Sopromat.dir/main.cpp.obj"
	C:\PROGRA~1\mingw-w64\x86_64-8.1.0-win32-seh-rt_v6-rev0\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Sopromat.dir\main.cpp.obj -c C:\Users\811243\CLionProjects\Sopromat\main.cpp

CMakeFiles/Sopromat.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Sopromat.dir/main.cpp.i"
	C:\PROGRA~1\mingw-w64\x86_64-8.1.0-win32-seh-rt_v6-rev0\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\811243\CLionProjects\Sopromat\main.cpp > CMakeFiles\Sopromat.dir\main.cpp.i

CMakeFiles/Sopromat.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Sopromat.dir/main.cpp.s"
	C:\PROGRA~1\mingw-w64\x86_64-8.1.0-win32-seh-rt_v6-rev0\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\811243\CLionProjects\Sopromat\main.cpp -o CMakeFiles\Sopromat.dir\main.cpp.s

CMakeFiles/Sopromat.dir/input_date.cpp.obj: CMakeFiles/Sopromat.dir/flags.make
CMakeFiles/Sopromat.dir/input_date.cpp.obj: ../input_date.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\811243\CLionProjects\Sopromat\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Sopromat.dir/input_date.cpp.obj"
	C:\PROGRA~1\mingw-w64\x86_64-8.1.0-win32-seh-rt_v6-rev0\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Sopromat.dir\input_date.cpp.obj -c C:\Users\811243\CLionProjects\Sopromat\input_date.cpp

CMakeFiles/Sopromat.dir/input_date.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Sopromat.dir/input_date.cpp.i"
	C:\PROGRA~1\mingw-w64\x86_64-8.1.0-win32-seh-rt_v6-rev0\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\811243\CLionProjects\Sopromat\input_date.cpp > CMakeFiles\Sopromat.dir\input_date.cpp.i

CMakeFiles/Sopromat.dir/input_date.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Sopromat.dir/input_date.cpp.s"
	C:\PROGRA~1\mingw-w64\x86_64-8.1.0-win32-seh-rt_v6-rev0\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\811243\CLionProjects\Sopromat\input_date.cpp -o CMakeFiles\Sopromat.dir\input_date.cpp.s

# Object files for target Sopromat
Sopromat_OBJECTS = \
"CMakeFiles/Sopromat.dir/main.cpp.obj" \
"CMakeFiles/Sopromat.dir/input_date.cpp.obj"

# External object files for target Sopromat
Sopromat_EXTERNAL_OBJECTS =

Sopromat.exe: CMakeFiles/Sopromat.dir/main.cpp.obj
Sopromat.exe: CMakeFiles/Sopromat.dir/input_date.cpp.obj
Sopromat.exe: CMakeFiles/Sopromat.dir/build.make
Sopromat.exe: CMakeFiles/Sopromat.dir/linklibs.rsp
Sopromat.exe: CMakeFiles/Sopromat.dir/objects1.rsp
Sopromat.exe: CMakeFiles/Sopromat.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\811243\CLionProjects\Sopromat\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable Sopromat.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Sopromat.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Sopromat.dir/build: Sopromat.exe

.PHONY : CMakeFiles/Sopromat.dir/build

CMakeFiles/Sopromat.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Sopromat.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Sopromat.dir/clean

CMakeFiles/Sopromat.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\811243\CLionProjects\Sopromat C:\Users\811243\CLionProjects\Sopromat C:\Users\811243\CLionProjects\Sopromat\cmake-build-debug C:\Users\811243\CLionProjects\Sopromat\cmake-build-debug C:\Users\811243\CLionProjects\Sopromat\cmake-build-debug\CMakeFiles\Sopromat.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Sopromat.dir/depend

