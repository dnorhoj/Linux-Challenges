# Compiler
CC = gcc
# Compiler Flags
CFLAGS = -Wall

# Source directory and distribution directory
SRC_DIR = ./src
DIST_DIR = ./dist

# Create a list of source files
ALL_FILES = $(wildcard $(SRC_DIR)/level_*/*)

SOURCES = $(wildcard $(SRC_DIR)/level_*/level_*.c)
OTHERS = $(filter-out $(SOURCES), $(ALL_FILES))

# Convert the list of source files to their corresponding executables
EXECUTABLES = $(patsubst $(SRC_DIR)/%.c, $(DIST_DIR)/%, $(SOURCES))
OTHER_TARGETS = $(patsubst $(SRC_DIR)/%, $(DIST_DIR)/%, $(OTHERS))

# Default target
all: $(EXECUTABLES) $(OTHER_TARGETS)

# Rule to create directories
$(DIST_DIR):
	mkdir -p $(DIST_DIR)

# Pattern rule for building executables
$(DIST_DIR)/%: $(SRC_DIR)/%.c | $(DIST_DIR)
	echo $(OTHER_TARGETS)
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $< -o $@

$(DIST_DIR)/%: $(SRC_DIR)/% | $(DIST_DIR)
	mkdir -p $(dir $@)
	cp $< $@

# Clean target to remove executables
clean:
	rm -rf $(DIST_DIR)