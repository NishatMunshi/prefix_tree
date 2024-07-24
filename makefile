# directories
HDR_DIR  = ./include
SRC_DIR  = ./src
OBJ_DIR  = ./build
EXE_DIR  = ./exec
BLD_DIRS = $(OBJ_DIR) $(EXE_DIR)
TMP_DIRS = $(OBJ_DIR)

# file extentions
HDR_EXT = h
SRC_EXT = c
OBJ_EXT = o

# files
SRCS = $(wildcard $(SRC_DIR)/*.$(SRC_EXT))
OBJS = $(patsubst $(SRC_DIR)/%.$(SRC_EXT), $(OBJ_DIR)/%.$(OBJ_EXT), $(SRCS))
HDRS = $(patsubst $(SRC_DIR)/%.$(SRC_EXT), $(HDR_DIR)/%.$(HDR_EXT), $(SRCS))

# target executable
TARGET = $(EXE_DIR)/main

# compiler info
CXX           = gcc
CXX_STD       = c17
CXX_FLAGS     = -g -Wall -Wextra -Wpedantic -std=$(CXX_STD)
INCLUDE_PATHS =

# linker stuff
LD       = $(CXX)
LD_PATHS =
LD_FLAGS =

# rules to build the target
all: build $(TARGET)

# compile
$(OBJ_DIR)/%.$(OBJ_EXT): $(SRC_DIR)/%.$(SRC_EXT) $(HDR_DIR)/%.$(HDR_EXT)
	$(CXX) $(CXX_FLAGS) -o $@ -c $< $(INCLUDE_PATHS)

# link
$(TARGET): $(OBJS)
	$(CXX) -o $(TARGET) $(OBJS) $(LD_PATHS) $(LD_FLAGS)

# rule to make build directories
build:
	mkdir -p $(BLD_DIRS)

# rule to clean the temporary directories
clean:
	rm -rf $(TMP_DIRS)

.PHONY: all build clean run