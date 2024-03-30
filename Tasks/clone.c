// To compile: gcc clone.c -o clone
// To run: ./clone
#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <sched.h>
#include <unistd.h>

// Function serving as the entry point for the child thread
int child_func(void *arg) {
    printf("Child thread\n"); // Print a message indicating this is the child thread
    return 0; // Return 0 to indicate successful completion of the thread
}

// Main function of the program
int main() {
    // Allocate memory for the child thread's stack
    char *stack = malloc(4096);

    // Define flags specifying the behavior of the child thread
    int flags = CLONE_VM | CLONE_FS | CLONE_FILES | CLONE_SIGHAND | CLONE_THREAD; 
    
    // Create a child thread using the clone() system call
    // Parameters: child_func - function to execute in the child thread
    //             stack + 4096 - pointer to the top of the child thread's stack
    //             flags - flags specifying behavior of the child thread
    //             NULL - argument to pass to the child function (not used in this example)
    int ret = clone(child_func, stack + 4096, flags, NULL);

    // Check if clone() call succeeds
    if (ret == -1) {
        perror("Clone failed"); // Print an error message if clone() fails
        exit(1); // Exit the program with an error code
    }

    printf("Parent thread\n"); // Print a message indicating this is the parent thread
    sleep(1); // Wait for 1 second to allow the child thread to complete its execution
    return 0; // Exit the program with a success code
}
