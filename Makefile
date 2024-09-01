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
TARGET = snake 

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
# Clean rule to remove built files
clean:
	rm -f $(TARGET) $(OBJ) $(DEPS)
	rm -rf obj

# Phony targets
.PHONY: all clean

