# Variables
CC = gcc
CFLAGS = -std=c17 -Wall -Wextra

# Directories
SRC_DIR = rough-work/src
INCLUDE_DIR = rough-work/include
BIN_DIR = rough-work/bin
BUILD_DIR = rough-work/build

# Find all project directories
PROJECTS = $(shell find . -maxdepth 1 -type d -name 'project*')

# Rules to build all projects
all: $(PROJECTS)

$(PROJECTS):
	$(MAKE) -C $@ CC=$(CC) CFLAGS="$(CFLAGS) -I$@/$(INCLUDE_DIR)" SRC_DIR=$(SRC_DIR) BIN_DIR=$(BIN_DIR) BUILD_DIR=$(BUILD_DIR)

# Build specific project in rough-work/src/
rough-work: $(BIN_DIR)/rough_work

# Specify the target and the dependencies
$(BIN_DIR)/rough_work: $(wildcard $(SRC_DIR)/*.c) | $(BIN_DIR)
	$(CC) $(CFLAGS) -I$(INCLUDE_DIR) $(wildcard $(SRC_DIR)/*.c) -o $(BIN_DIR)/rough_work

# Create the bin directory if it doesn't exist
$(BIN_DIR):
	mkdir -p $(BIN_DIR)

# Clean rule for all projects
clean:
	@for dir in $(PROJECTS); do \
	    $(MAKE) -C $$dir clean; \
	done
	rm -f $(BIN_DIR)/*
