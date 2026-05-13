# Assignment: Forked Address Space Snapshot

## Goal
Implement one program that demonstrates:
- basic concurrent process flow with `fork()`
- parent-child synchronization with `waitpid()`
- process address-space isolation after `fork()` (global, heap, stack)

This assignment is designed for deterministic GitHub autograding with no runtime input.

## Files To Use
- starter source: `starter/src/fork_exec_lab.c`
- header: `starter/include/fork_exec_lab.h`
- local tests: `starter/scripts/test.sh`

## Student Task
Complete TODOs in `starter/src/fork_exec_lab.c`.

Required behavior:
1. Parent initializes three counters:
   - global counter = 100
   - heap counter = 200
   - stack counter = 300
2. Parent prints:
   - `parent: start g=100 h=200 s=300`
3. Program forks exactly one child.
4. Child adds `7` to each counter and prints:
   - `child: g=107 h=207 s=307 sum=621`
5. Child exits with status `621 % 256 = 109`.
6. Parent waits for that exact child with `waitpid()`.
7. Parent prints:
   - `parent: child-exit=109`
   - `parent: g=100 h=200 s=300`
   - `parent: address-space=isolated`

## Why This Is Interesting
- You get parallel execution structure (parent and child are separate processes).
- You observe copy-on-write semantics: child changes do not mutate parent values.
- You practice clean process lifecycle handling and status collection.

## Deterministic Expected Output
Exact lines expected from a correct solution:

```text
parent: start g=100 h=200 s=300
child: g=107 h=207 s=307 sum=621
parent: child-exit=109
parent: g=100 h=200 s=300
parent: address-space=isolated
```

## Minimal Autograding Strategy
Use visible checks with static pattern matching only:
- build with `-Wall -Wextra -Werror`
- run binary once
- assert each expected line appears
- fail if output contains `TODO:`

This is already encoded in `starter/scripts/test.sh`.

## Classroom Integration Notes
- Publish only starter files to students.
- Keep `starter/solutions/fork_exec_lab_solution.c` in instructor-only repository.
- In GitHub Classroom autograding, run:
  - `cd 04-multi-processes/starter`
  - `make check`
