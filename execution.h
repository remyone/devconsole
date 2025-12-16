#ifndef MYHEADER_H
#define MYHEADER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <dirent.h>
#include <fcntl.h>

#define BUFFER_SIZE 1024
#define reset "\x1b[0m"
#define red "\x1b[31m"

//this function scans /bin directory and if the command is found there, then it'll launch it from /bin
//Otherwise, it'll just exec a program with pathname/filename
int program_definer(char *token);
void build_argv(char *tokens[BUFFER_SIZE], char *argv[BUFFER_SIZE], int NOTokens);
void build_file_path(char file[BUFFER_SIZE], char *token);
void exec_program(char *tokens[BUFFER_SIZE], int NOTokens);

#endif