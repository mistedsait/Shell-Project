// To compile: gcc forkwaitexec.c -o forkwaitexec
// To run: ./forkwaitexec.c
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    int child;

    child = fork();
    printf("Fork process completed with result: %d\n", child);

    if (child < 0) // Fork failed
    {
        printf("Error: Forking process failed.\n");
        exit(1);
    }
    else if (child == 0) // Child process
    {
        printf("Child process (PID: %d) reporting in!\n", (int)getpid());
        
        // Execute 'date' command to print current date and time
        char *args[] = {"date", NULL};
        execvp(args[0], args); // Replace child process with 'date' command
    }
    else // Parent process
    {
        printf("Parent process (PID: %d) awaiting child's return...\n", (int)getpid());
        
        // Parent waits for child to finish execution
        wait(NULL);
        
        printf("Parent process: Child has successfully completed its task.\n");
    } 
    return 0;
}

