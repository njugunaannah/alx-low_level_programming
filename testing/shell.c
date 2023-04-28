#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

void read_command(char cmd[], char *par[]) {
    char line[1024];
    int count = 0, i = 0, j = 0;
    char *array[100], *pch;

    for (;;) {
        int c = fgetc(stdin);
        line[count++] = (char) c;
        if (c == '\n' || count > 1023) {
            break;
        }
    }
    line[count] = '\0';

    pch = strtok(line, " \n");

    while (pch != NULL && i < 19) {
        array[i++] = strdup(pch);
        pch = strtok(NULL, " \n");
    }

    strcpy(cmd, array[0]);

    for (j = 0; j < i; j++) {
        par[j] = array[j];
    }
    par[j] = NULL;
}

void type_prompt() {
    static int first_time = 1;
    if (first_time) {
        const char* CLEAR_SCREEN_ANSI = "\e[1;1H\e[2J";
        write(STDERR_FILENO, CLEAR_SCREEN_ANSI, 12);
        first_time = 0;
    }
    printf("# ");
}

int main() {
    char cmd[100], command[100], *parameters[20];

    char *envp[] = { (char *) "PATH=C:\\Windows\\System32", NULL };
    while (1) {
        type_prompt();
        read_command(command, parameters);
        if (strcmp(command, "exit") == 0) {
            break;
        }
        if (fork() != 0) {
            wait(NULL);
        } else {
            execvp(command, parameters);
            printf("Unknown command: %s\n", command);
            exit(1);
        }
    }
    return 0;
}
