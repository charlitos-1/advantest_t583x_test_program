# Compiler
CXX = g++
PAT_COMPILER = touch # dummy compiler

# Compiler Flags:
# - C++11 standard, strict warnings, treat warnings as errors
# - Generate dependency files (-MMD) and add phony targets (-MP)
CXXFLAGS = -std=c++11 -Wall -Wextra -Werror -MMD -MP -pedantic

# Project Folders:
BUILD_DIR = build

PATTERN_DIR = pattern

PLATFORM_DIR = platform
INCLUDE_DIR = $(PLATFORM_DIR)/include
SRC_DIR = $(PLATFORM_DIR)/src

# Target executable name
TARGET_NAME = t583x.exe
TARGET = $(BUILD_DIR)/$(TARGET_NAME)

# Include directory for header files
CXX_INCLUDES = -I$(INCLUDE_DIR)

# Automatically find all .cpp files under platform/src (including subdirectories)
CPP_FILES := $(shell find $(SRC_DIR) -type f -name '*.cpp')

# Generate object file names
OBJECT_FILES := $(addprefix $(BUILD_DIR)/,$(CPP_FILES:.cpp=.o))

# Automatically find all .asc files under pattern (including subdirectories)
PAT_FILES := $(shell find $(PATTERN_DIR) -type f -name '*.asc')

# Generate mpa file names
MPA_FILES := $(addprefix $(BUILD_DIR)/,$(PAT_FILES:.asc=.mpa))

# Default target: build the executable
all: platform pattern

# Compile only platform files
platform: $(TARGET)

# Link object files to create the final executable
$(TARGET): $(OBJECT_FILES)
	$(CXX) $(CXXFLAGS) $(CXX_INCLUDES) -o $@ $^

# Compile each .cpp file into an object file
$(BUILD_DIR)/%.o: %.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) $(CXX_INCLUDES) -c $< -o $@

# Complile pattern files
pattern: $(MPA_FILES)

$(BUILD_DIR)/%.mpa: %.asc
	@mkdir -p $(dir $@)
	$(PAT_COMPILER) $@

# Clean all files
clean: clean_platform clean_pattern

# Clean platform files
clean_platform:
	rm -f $(OBJECT_FILES) $(TARGET) $(OBJECT_FILES:.o=.d)

# Clean pattern files
clean_pattern:
	rm -f $(MPA_FILES)

# Include generated dependency files
-include $(OBJECT_FILES:.o=.d)

# Print variables
print:
	@echo
	@echo ============================================
	@echo "------------------------------------"
	@echo "    TARGET: $(TARGET)"
	@echo "    TARGET_NAME: $(TARGET_NAME)"
	@echo "------------------------------------"
	@echo "    CXX: $(CXX)"
	@echo "    CXXFLAGS: $(CXXFLAGS)"
	@echo "    CXX_INCLUDES: $(CXX_INCLUDES)"
	@echo "------------------------------------"
	@echo "    CPP_FILES: $(CPP_FILES)"
	@echo "    OBJECT_FILES: $(OBJECT_FILES)"
	@echo "------------------------------------"
	@echo "    PAT_COMPILER: $(PAT_COMPILER)"
	@echo "------------------------------------"
	@echo "    PAT_FILES: $(PAT_FILES)"
	@echo "    MPA_FILES: $(MPA_FILES)"
	@echo "------------------------------------"
	@echo "    BUILD_DIR: $(BUILD_DIR)"
	@echo "    PATTERN_DIR: $(PATTERN_DIR)"
	@echo "    PLATFORM_DIR: $(PLATFORM_DIR)"
	@echo "    INCLUDE_DIR: $(INCLUDE_DIR)"
	@echo "    SRC_DIR: $(SRC_DIR)"
	@echo "------------------------------------"
	@echo ============================================