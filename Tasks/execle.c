// To compile: gcc execle.c -o execle
// To run: ./execle.c
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> 

int main() {
    // Define an environment variable to be passed to the executed command
    char *env[] = {"VAR=works", NULL}; // Custom environment variable 

    // Define the command and its arguments to be executed
    char *args[] = {"printenv", NULL}; // Command to print environment variables

    // Execute the specified command with custom environment using execle()
    execle("/usr/bin/printenv", args[0], NULL, env);  // The command is located in the "bin" directory

    // If execle() succeeds, this line won't be reached
    printf("This line won't be displayed because execle() has replaced the current process.\n");


    // If execle() fails, print an error message
    perror("Execle() failed");
    exit(1);
    
    // Retrieve and print the value of the custom environment variable
    char *var = getenv("VAR");  
    printf("The value of VAR is: %s\n", var);
}
