// To compile: gcc shell.c -o shell
// To run: ./shell.c
// In order to run cmatrix: sudo apt install cmatrix
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#define MAX_COMMAND_LENGTH 1024

// ANSI escape codes for colors
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_RESET   "\x1b[0m"

char *get_prompt() {
    char machine_name[128];
    char *username = getlogin();
    gethostname(machine_name, sizeof(machine_name));
    static char prompt[256];
    snprintf(prompt, sizeof(prompt), "%s%s@%s%s:%s~$ ", ANSI_COLOR_CYAN, machine_name, ANSI_COLOR_GREEN, username, ANSI_COLOR_RESET);
    return prompt;
}

void execute_command(char *command) {
    char *args[MAX_COMMAND_LENGTH];
    char *token;
    int i = 0;

    token = strtok(command, " ");
    while (token != NULL) {
        args[i++] = token;
        token = strtok(NULL, " ");
    }
    args[i] = NULL;

    // Check for redirecting output to a text file
    int redirect_index = -1;
    for (int j = 0; j < i; j++) {
        if (strcmp(args[j], ">") == 0) {
            redirect_index = j;
            break;
        }
    }

    int pid;
    int fd;

    if (redirect_index != -1) {
        // Redirect output to a text file
        char *filename = args[redirect_index + 1];
        args[redirect_index] = NULL;
        fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0666);
        if (fd < 0) {
            perror("open failed");
            return;
        }
    }

    pid = fork();

    if (pid == 0) {
        // Child process: Execute the command
        if (redirect_index != -1) {
            dup2(fd, STDOUT_FILENO);
            close(fd);
        }
        execvp(args[0], args);
        perror("execvp failed"); // Print error if execvp fails
        exit(EXIT_FAILURE);
    } else if (pid < 0) {
        // Fork failed
        perror("fork failed");
    } else {
        // Parent process: Wait for the child process to finish
        wait(NULL);
    }
}

int main() {
    char command[MAX_COMMAND_LENGTH];

    while (1) {
        printf("%s", get_prompt());
        fgets(command, MAX_COMMAND_LENGTH, stdin);
        command[strcspn(command, "\n")] = '\0'; // Remove trailing newline

        if (strcmp(command, "exit") == 0) {
            break;
        } else if (strcmp(command, "clear") == 0) {
            system("clear");
        } else if (strcmp(command, "cmatrix") == 0) {
            system("cmatrix");
        } else if (strcmp(command, "wc") == 0) {
            system("wc");
        } else if (strcmp(command, "grep") == 0) {
            system("grep");
        } else if (strcmp(command, "df") == 0) {
            system("df");
        } else {
            execute_command(command);
        }
    }

    return 0;
}
