#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void print_message(void);

int main() {
    pid_t pid;

    // Fork the process to create a new child process.
    pid = fork();

    if (pid < 0) {
        printf("Fork failed\n");
        exit(1);
    }

    if (pid == 0) {
        // Child process.
        print_message();
    } else {
        // Parent process.
        print_message();
    }

    return 0;
}

void print_message(void) {
    printf("Hello from the new process!\n");
}

