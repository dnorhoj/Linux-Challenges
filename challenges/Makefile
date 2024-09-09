# Compiler
CC = gcc
# Compiler Flags
CFLAGS = -Wall

# Source directory and distribution directory
SRC_DIR = ./src
BUILD_DIR = ./build
DIST_DIR = ./dist

# Create a list of source files
ALL_FILES = $(wildcard $(SRC_DIR)/*/*) $(wildcard $(SRC_DIR)/*/.*)

SOURCES = $(wildcard $(SRC_DIR)/*/*.c)
INTERMEDIATES = $(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/%.c, $(SOURCES))

OTHERS = $(filter-out $(SOURCES), $(ALL_FILES))

# Convert the list of source files to their corresponding executables
EXECUTABLES = $(patsubst $(BUILD_DIR)/%.c, $(DIST_DIR)/%, $(INTERMEDIATES))
OTHER_TARGETS = $(patsubst $(SRC_DIR)/%, $(DIST_DIR)/%, $(OTHERS))

# Preserve intermediates
.PRECIOUS: $(INTERMEDIATES)

# Default target
all: sanity-check $(EXECUTABLES) $(OTHER_TARGETS) clean-build
debug: sanity-check $(EXECUTABLES) $(OTHER_TARGETS)

# Check common errors
sanity-check:
ifndef LINUX_USERNAME
	$(error LINUX_USERNAME environment variable is not set)
endif

# Rule to create directories
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(DIST_DIR):
	mkdir -p $(DIST_DIR)

# Substitute ${LINUX_USERNAME} with the environment variable
$(BUILD_DIR)/%.c: $(SRC_DIR)/%.c | $(BUILD_DIR)
	mkdir -p $(dir $@)
	envsubst '$$LINUX_USERNAME' < $< > $@

# Build executables
$(DIST_DIR)/%: $(BUILD_DIR)/%.c | $(DIST_DIR)
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $< -o $@

$(DIST_DIR)/%: $(SRC_DIR)/% | $(DIST_DIR)
	mkdir -p $(dir $@)
	cp -r $< $@

# Clean target to remove executables
clean-build:
	rm -rf $(BUILD_DIR)

clean: | clean-build
	rm -rf $(DIST_DIR)
