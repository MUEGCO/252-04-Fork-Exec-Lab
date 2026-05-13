# System Programming Lab: fork() and Program Address Space

## 1. Learning Objectives
By the end of this lab, you should be able to:
- create a child process with `fork()`
- explain what parts of program memory are copied on `fork()`
- wait for a child process with `waitpid()`
- report child exit status correctly
- handle system call failures safely

## 2. Repository Layout
- `src/`: source files for this lab
- `include/`: headers and function prototypes
- `scripts/`: helper scripts for grading or local checks
- `tests/`: notes about the visible checks
- `samples/`: sample command arguments

## 3. What You Need To Implement
Complete the TODO sections in `src/fork_exec_lab.c`.

Required behavior:
1. create exactly one child process with `fork()`
2. initialize values as:
   - global: `100`
   - heap: `200`
   - stack: `300`
3. in the child, add `7` to each value and print the child snapshot
4. child exits with status `(global + heap + stack) % 256`
5. in the parent, wait for the specific child with `waitpid()`
6. print child exit status and parent snapshot
7. print `parent: address-space=isolated` when parent values remain unchanged
5. return a non-zero exit code on failure

Rules:
- do not change the function signatures in `include/fork_exec_lab.h`
- keep the output labels `parent:` and `child:`
- check every system call return value

## 4. Build
```bash
make
```

## 5. Run
```bash
./bin/fork_exec_lab
```
