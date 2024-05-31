# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -Iinclude -std=c++11 -Wall

# Executable name
TARGET = MagnoliaRPG

# Source and header files
SRCS = $(wildcard src/*.cpp)
HEADERS = $(wildcard include/*.h)

# Object files
OBJS = $(SRCS:.cpp=.o)

# Default target
all: $(TARGET)

# Rule to build the executable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Rule to build object files
%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean target to remove built files
clean:
	del /Q $(subst /,\,$(OBJS)) $(subst /,\,$(TARGET))

.PHONY: all clean
