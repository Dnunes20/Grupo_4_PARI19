# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

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
CMAKE_SOURCE_DIR = /home/dnunes/.local/share/Trash/files/Grupo_4_PARI19/Grupo_4_PARI19

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/dnunes/.local/share/Trash/files/Grupo_4_PARI19/Grupo_4_PARI19/doc

# Utility rule file for prototypes.h.

# Include the progress variables for this target.
include CMakeFiles/prototypes.h.dir/progress.make

CMakeFiles/prototypes.h: ../src/main.c
CMakeFiles/prototypes.h: ../src/myf.c
CMakeFiles/prototypes.h: ../src/callbacks.c
CMakeFiles/prototypes.h: ../src/auxcallbacks.c
	cd /home/dnunes/.local/share/Trash/files/Grupo_4_PARI19/Grupo_4_PARI19 && echo Rebuild\ prototypes.h
	cd /home/dnunes/.local/share/Trash/files/Grupo_4_PARI19/Grupo_4_PARI19 && echo '/*File generated automatically. Do not edit*/' > /home/dnunes/.local/share/Trash/files/Grupo_4_PARI19/Grupo_4_PARI19/src/prototypes.h
	cd /home/dnunes/.local/share/Trash/files/Grupo_4_PARI19/Grupo_4_PARI19 && echo '/*Generated on' `hostname` ',' `date` '*/' >> /home/dnunes/.local/share/Trash/files/Grupo_4_PARI19/Grupo_4_PARI19/src/prototypes.h
	cd /home/dnunes/.local/share/Trash/files/Grupo_4_PARI19/Grupo_4_PARI19 && echo '#ifdef __cplusplus' >> /home/dnunes/.local/share/Trash/files/Grupo_4_PARI19/Grupo_4_PARI19/src/prototypes.h
	cd /home/dnunes/.local/share/Trash/files/Grupo_4_PARI19/Grupo_4_PARI19 && echo 'extern "C" {' >> /home/dnunes/.local/share/Trash/files/Grupo_4_PARI19/Grupo_4_PARI19/src/prototypes.h
	cd /home/dnunes/.local/share/Trash/files/Grupo_4_PARI19/Grupo_4_PARI19 && echo '#endif' >> /home/dnunes/.local/share/Trash/files/Grupo_4_PARI19/Grupo_4_PARI19/src/prototypes.h
	cd /home/dnunes/.local/share/Trash/files/Grupo_4_PARI19/Grupo_4_PARI19 && cproto `pkg-config --cflags gtk+-3.0|awk '{$$1="" ; print $$0}'` `pkg-config --cflags opencv` -q -O /dev/null src/main.c src/myf.c src/callbacks.c src/auxcallbacks.c >> /home/dnunes/.local/share/Trash/files/Grupo_4_PARI19/Grupo_4_PARI19/src/prototypes.h
	cd /home/dnunes/.local/share/Trash/files/Grupo_4_PARI19/Grupo_4_PARI19 && echo '#ifdef __cplusplus' >> /home/dnunes/.local/share/Trash/files/Grupo_4_PARI19/Grupo_4_PARI19/src/prototypes.h
	cd /home/dnunes/.local/share/Trash/files/Grupo_4_PARI19/Grupo_4_PARI19 && echo '}' >> /home/dnunes/.local/share/Trash/files/Grupo_4_PARI19/Grupo_4_PARI19/src/prototypes.h
	cd /home/dnunes/.local/share/Trash/files/Grupo_4_PARI19/Grupo_4_PARI19 && echo '#endif' >> /home/dnunes/.local/share/Trash/files/Grupo_4_PARI19/Grupo_4_PARI19/src/prototypes.h

prototypes.h: CMakeFiles/prototypes.h
prototypes.h: CMakeFiles/prototypes.h.dir/build.make

.PHONY : prototypes.h

# Rule to build all files generated by this target.
CMakeFiles/prototypes.h.dir/build: prototypes.h

.PHONY : CMakeFiles/prototypes.h.dir/build

CMakeFiles/prototypes.h.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/prototypes.h.dir/cmake_clean.cmake
.PHONY : CMakeFiles/prototypes.h.dir/clean

CMakeFiles/prototypes.h.dir/depend:
	cd /home/dnunes/.local/share/Trash/files/Grupo_4_PARI19/Grupo_4_PARI19/doc && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/dnunes/.local/share/Trash/files/Grupo_4_PARI19/Grupo_4_PARI19 /home/dnunes/.local/share/Trash/files/Grupo_4_PARI19/Grupo_4_PARI19 /home/dnunes/.local/share/Trash/files/Grupo_4_PARI19/Grupo_4_PARI19/doc /home/dnunes/.local/share/Trash/files/Grupo_4_PARI19/Grupo_4_PARI19/doc /home/dnunes/.local/share/Trash/files/Grupo_4_PARI19/Grupo_4_PARI19/doc/CMakeFiles/prototypes.h.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/prototypes.h.dir/depend

