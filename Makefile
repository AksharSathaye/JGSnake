#Copyright 2024 Akshar Sathaye
#This file is part of JGSnake.
#JGSnake is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
#JGSnake is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
#You should have received a copy of the GNU General Public License along with JGSnake. If not, see <https://www.gnu.org/licenses/>. 

# Compiler and Linker
CXX = g++
CXXFLAGS = -std=c++20 -Wall -Wextra -I /usr/include -I ./headers # Include directory

# Linker flags
LDFLAGS = -L /usr/lib -l sfml-graphics -l sfml-window -l sfml-system # Linker library path and library name

# Source and Object Files
SRC = $(wildcard src/*.cpp)
OBJ = $(SRC:src/%.cpp=obj/%.o)
DEPS = $(SRC:src/%.cpp=deps/%.d)
#HED = $(headers/*.hpp)
# Executable
TARGET = jgsnake 

# Default rule
all: $(TARGET)

# Rule to link the executable
$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

# Rule to compile source files into object files
obj/%.o: src/%.cpp
	mkdir -p obj
	$(CXX) $(CXXFLAGS) -MMD -MP -c $< -o $@

-include $(DEPS)
#TODO: Get Makefile to re-compile dependencies of header files when the header files are modified.
# Clean rule to remove built files
clean:
	rm -f $(TARGET) $(OBJ) $(DEPS)
	rm -rf obj

# Phony targets
.PHONY: all clean

