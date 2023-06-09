# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.26

# Default target executed when no arguments are given to make.
default_target: all
.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:

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
CMAKE_COMMAND = /Applications/CMake.app/Contents/bin/cmake

# The command to remove a file.
RM = /Applications/CMake.app/Contents/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/mlyin/Desktop/MonteCarlo-Poker-master

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/mlyin/Desktop/MonteCarlo-Poker-master

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake cache editor..."
	/Applications/CMake.app/Contents/bin/ccmake -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache
.PHONY : edit_cache/fast

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/Applications/CMake.app/Contents/bin/cmake --regenerate-during-build -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache
.PHONY : rebuild_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /Users/mlyin/Desktop/MonteCarlo-Poker-master/CMakeFiles /Users/mlyin/Desktop/MonteCarlo-Poker-master//CMakeFiles/progress.marks
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /Users/mlyin/Desktop/MonteCarlo-Poker-master/CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean
.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named MonteCarloPoker

# Build rule for target.
MonteCarloPoker: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 MonteCarloPoker
.PHONY : MonteCarloPoker

# fast build rule for target.
MonteCarloPoker/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/MonteCarloPoker.dir/build.make CMakeFiles/MonteCarloPoker.dir/build
.PHONY : MonteCarloPoker/fast

cards.o: cards.cpp.o
.PHONY : cards.o

# target to build an object file
cards.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/MonteCarloPoker.dir/build.make CMakeFiles/MonteCarloPoker.dir/cards.cpp.o
.PHONY : cards.cpp.o

cards.i: cards.cpp.i
.PHONY : cards.i

# target to preprocess a source file
cards.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/MonteCarloPoker.dir/build.make CMakeFiles/MonteCarloPoker.dir/cards.cpp.i
.PHONY : cards.cpp.i

cards.s: cards.cpp.s
.PHONY : cards.s

# target to generate assembly for a file
cards.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/MonteCarloPoker.dir/build.make CMakeFiles/MonteCarloPoker.dir/cards.cpp.s
.PHONY : cards.cpp.s

main.o: main.cpp.o
.PHONY : main.o

# target to build an object file
main.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/MonteCarloPoker.dir/build.make CMakeFiles/MonteCarloPoker.dir/main.cpp.o
.PHONY : main.cpp.o

main.i: main.cpp.i
.PHONY : main.i

# target to preprocess a source file
main.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/MonteCarloPoker.dir/build.make CMakeFiles/MonteCarloPoker.dir/main.cpp.i
.PHONY : main.cpp.i

main.s: main.cpp.s
.PHONY : main.s

# target to generate assembly for a file
main.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/MonteCarloPoker.dir/build.make CMakeFiles/MonteCarloPoker.dir/main.cpp.s
.PHONY : main.cpp.s

samples.o: samples.cpp.o
.PHONY : samples.o

# target to build an object file
samples.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/MonteCarloPoker.dir/build.make CMakeFiles/MonteCarloPoker.dir/samples.cpp.o
.PHONY : samples.cpp.o

samples.i: samples.cpp.i
.PHONY : samples.i

# target to preprocess a source file
samples.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/MonteCarloPoker.dir/build.make CMakeFiles/MonteCarloPoker.dir/samples.cpp.i
.PHONY : samples.cpp.i

samples.s: samples.cpp.s
.PHONY : samples.s

# target to generate assembly for a file
samples.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/MonteCarloPoker.dir/build.make CMakeFiles/MonteCarloPoker.dir/samples.cpp.s
.PHONY : samples.cpp.s

simulator.o: simulator.cpp.o
.PHONY : simulator.o

# target to build an object file
simulator.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/MonteCarloPoker.dir/build.make CMakeFiles/MonteCarloPoker.dir/simulator.cpp.o
.PHONY : simulator.cpp.o

simulator.i: simulator.cpp.i
.PHONY : simulator.i

# target to preprocess a source file
simulator.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/MonteCarloPoker.dir/build.make CMakeFiles/MonteCarloPoker.dir/simulator.cpp.i
.PHONY : simulator.cpp.i

simulator.s: simulator.cpp.s
.PHONY : simulator.s

# target to generate assembly for a file
simulator.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/MonteCarloPoker.dir/build.make CMakeFiles/MonteCarloPoker.dir/simulator.cpp.s
.PHONY : simulator.cpp.s

tables.o: tables.cpp.o
.PHONY : tables.o

# target to build an object file
tables.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/MonteCarloPoker.dir/build.make CMakeFiles/MonteCarloPoker.dir/tables.cpp.o
.PHONY : tables.cpp.o

tables.i: tables.cpp.i
.PHONY : tables.i

# target to preprocess a source file
tables.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/MonteCarloPoker.dir/build.make CMakeFiles/MonteCarloPoker.dir/tables.cpp.i
.PHONY : tables.cpp.i

tables.s: tables.cpp.s
.PHONY : tables.s

# target to generate assembly for a file
tables.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/MonteCarloPoker.dir/build.make CMakeFiles/MonteCarloPoker.dir/tables.cpp.s
.PHONY : tables.cpp.s

tools.o: tools.cpp.o
.PHONY : tools.o

# target to build an object file
tools.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/MonteCarloPoker.dir/build.make CMakeFiles/MonteCarloPoker.dir/tools.cpp.o
.PHONY : tools.cpp.o

tools.i: tools.cpp.i
.PHONY : tools.i

# target to preprocess a source file
tools.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/MonteCarloPoker.dir/build.make CMakeFiles/MonteCarloPoker.dir/tools.cpp.i
.PHONY : tools.cpp.i

tools.s: tools.cpp.s
.PHONY : tools.s

# target to generate assembly for a file
tools.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/MonteCarloPoker.dir/build.make CMakeFiles/MonteCarloPoker.dir/tools.cpp.s
.PHONY : tools.cpp.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... edit_cache"
	@echo "... rebuild_cache"
	@echo "... MonteCarloPoker"
	@echo "... cards.o"
	@echo "... cards.i"
	@echo "... cards.s"
	@echo "... main.o"
	@echo "... main.i"
	@echo "... main.s"
	@echo "... samples.o"
	@echo "... samples.i"
	@echo "... samples.s"
	@echo "... simulator.o"
	@echo "... simulator.i"
	@echo "... simulator.s"
	@echo "... tables.o"
	@echo "... tables.i"
	@echo "... tables.s"
	@echo "... tools.o"
	@echo "... tools.i"
	@echo "... tools.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system

