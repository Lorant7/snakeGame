# # Compiler and Flags
# CXX = g++
# CXXFLAGS = -I"../include" -L"../libs" -lpdcurses

# # Target Executable
# TARGET = snakegame

# # Source Files
# SRCS = src/snakegame.cpp

# # Object Files
# OBJS = $(SRCS:.cpp=.o)

# # Build the Target
# $(TARGET): $(OBJS)
# 	$(CXX) -o $@ $(OBJS) $(CXXFLAGS)

# # Compile Source Files to Object Files
# src/%.o: src/%.cpp
# 	$(CXX) -c $< -o $@ -Iinclude

# # Clean Up
# clean:
# 	rm -f $(OBJS) $(TARGET)

CXX = g++
CXXFLAGS = -Iinclude -Wall -Wextra -std=c++17
LDFLAGS = -Llibs -lpdcurses

SRCS = src/snakegame.cpp src/snake.cpp src/bodyPart.cpp
OBJS = $(SRCS:.cpp=.o)

TARGET = snakegame

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) -o $@ $^ $(LDFLAGS)

src/%.o: src/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f src/*.o $(TARGET)

