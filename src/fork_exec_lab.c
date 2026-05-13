#include "fork_exec_lab.h"

#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int g_counter = 100;

pid_t spawn_child(void) {
    return fork();
}

int run_child_process(int *heap_counter, int stack_counter) {
    int child_sum;

    /* TODO(student): Update all three counters in the child by +7. */
    /* TODO(student): Compute child_sum as the sum of the updated counters. */
    /* TODO(student): Print exactly: child: g=<g> h=<h> s=<s> sum=<sum> */
    /* TODO(student): Return child_sum % 256. */

    (void)heap_counter;
    (void)stack_counter;
    (void)child_sum;
    fprintf(stderr, "TODO: child address-space logic not implemented\n");
    return 1;
}

int wait_for_child(pid_t child_pid, int *heap_counter, int stack_counter) {
    int status = 0;
    int child_code;

    if (waitpid(child_pid, &status, 0) == -1) {
        perror("waitpid");
        return 1;
    }

    if (!WIFEXITED(status)) {
        fprintf(stderr, "parent: child terminated abnormally\n");
        return 1;
    }

    child_code = WEXITSTATUS(status);

    /* TODO(student): Print exactly: parent: child-exit=<code> */
    /* TODO(student): Print exactly: parent: g=<g> h=<h> s=<s> */
    /* TODO(student): If parent values are 100, 200, 300 print:
       parent: address-space=isolated
       Otherwise print:
       parent: address-space=unexpected */
    /* TODO(student): Return 0 only if child_code is 109 and parent values are unchanged. */

    (void)status;
    (void)child_code;
    (void)heap_counter;
    (void)stack_counter;
    fprintf(stderr, "TODO: parent reporting not implemented\n");
    return 1;
}
