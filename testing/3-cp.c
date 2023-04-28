#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

#define BUFFER_SIZE 4096

void error(char *msg);
void copy_file(char *src, char *dest);

/**
 * error - Prints an error message and exits the program with an error code.
 * @msg: The error message to print.
 */
void error(char *msg)
{
    fprintf(stderr, "Error: %s\n", msg);
    exit(EXIT_FAILURE);
}

/**
 * copy_file - Copies the contents of one file to another.
 * @src: The path to the source file.
 * @dest: The path to the destination file.
 */
void copy_file(char *src, char *dest)
{
    int fd_in, fd_out, n;
    char buffer[BUFFER_SIZE];

    /* Check that the source and destination files are different*/
    if (strcmp(src, dest) == 0) {
        error("Source and destination files are the same");
    }

    // Open input file
    fd_in = open(src, O_RDONLY);
    if (fd_in < 0) {
        error(strerror(errno));
    }

    // Open output file
    fd_out = open(dest, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd_out < 0) {
        error(strerror(errno));
    }

    // Copy file contents
    while ((n = read(fd_in, buffer, BUFFER_SIZE)) > 0) {
        if (write(fd_out, buffer, n) != n) {
            error(strerror(errno));
        }
    }

    // Check for errors during copy
    if (n < 0) {
        error(strerror(errno));
    }

    // Close files
    if (close(fd_in) < 0 || close(fd_out) < 0) {
        error(strerror(errno));
    }
}

/**
 * main - Entry point.
 * @argc: The number of command-line arguments.
 * @argv: An array of command-line argument strings.
 *
 * Return: 0 on success, or an error code on failure.
 */
int main(int argc, char *argv[])
{
    if (argc != 3) {
        error("Usage: cp source_file destination_file");
    }

    copy_file(argv[1], argv[2]);

    return 0;
}

