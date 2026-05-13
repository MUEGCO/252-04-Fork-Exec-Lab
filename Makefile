CC = gcc
CFLAGS = -Wall -Wextra -Werror -g -Iinclude
BIN_DIR = bin

all: $(BIN_DIR)/fork_exec_lab

check: all
	./scripts/check.sh

grade: all
	./scripts/grade.sh

$(BIN_DIR):
	mkdir -p $(BIN_DIR)

$(BIN_DIR)/fork_exec_lab: src/fork_exec_lab.c include/fork_exec_lab.h | $(BIN_DIR)
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f $(BIN_DIR)/fork_exec_lab

.PHONY: all check grade clean
