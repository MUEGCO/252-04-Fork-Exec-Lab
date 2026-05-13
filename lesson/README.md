# System Programming Lab: Processes with fork() and exec()

## 1. Learning Objectives
By the end of this lab, students should be able to:
- create a child process with `fork()`
- replace a process image with an `exec()` call
- distinguish parent and child execution paths
- wait for child termination with `waitpid()`
- handle process errors and exit codes correctly

## 2. What Is In This Folder
- `multi-processes.md`: lecture notes for the topic
- `forkDemo.c`, `execlDemo.c`, `execvDemo.c`, `zombieDemo.c`: instructor demos
- `print.c`: helper used by some demos
- `starter/`: GitHub Classroom starter template for students

## 3. GitHub Classroom Starter
The starter assignment lives in `starter/` so you can use this module as course material and still give students a clean repository layout.

Recommended workflow:
1. Copy `04-multi-processes/starter/` into a dedicated template repository.
2. Use that repository as the GitHub Classroom starter repository.
3. Keep student repositories private.

## 4. Assignment Summary
Students complete a small program that:
1. forks one child process
2. executes a helper program in the child with `execv()`
3. waits for the child in the parent with `waitpid()`
4. reports whether the child exited normally

## 5. Suggested Instructor Notes
- Keep the helper program unchanged so grading stays deterministic.
- Ask students to check every system call return value.
- Require `-Wall -Wextra -Werror -g` during compilation.
- Encourage students to compare their solution against the demo files only after they attempt the TODOs.