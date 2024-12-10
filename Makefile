# Compiler and Flags
CXX = g++
CXXFLAGS = -I"../include" -L"../libs" -lpdcurses

# Target Executable
TARGET = snakegame

# Source Files
SRCS = src/snakegame.cpp

# Object Files
OBJS = $(SRCS:.cpp=.o)

# Build the Target
$(TARGET): $(OBJS)
	$(CXX) -o $@ $(OBJS) $(CXXFLAGS)

# Compile Source Files to Object Files
src/%.o: src/%.cpp
	$(CXX) -c $< -o $@ -Iinclude

# Clean Up
clean:
	rm -f $(OBJS) $(TARGET)
