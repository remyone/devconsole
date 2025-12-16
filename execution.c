#include "execution.h"

int program_definer(char *token) {
	DIR *dir = opendir("/bin");
	struct dirent *read_dir;
	int match = 0;

	char buffer[BUFFER_SIZE * 2];
	int length = 0, process;
	memset(buffer, 0, BUFFER_SIZE * 2);

	while (read_dir = readdir(dir)) {
		if (strcmp(token, read_dir->d_name) == 0)
			match = 1;
	}


	closedir(dir);

	if (match == 0) {
		if ((process = fork()) == 0) { 
			char *argv[5] = {"sh", "-c", "compgen -b", NULL};
			execv("/bin/sh", argv);

			int x = open( (char *) STDOUT_FILENO, O_RDONLY);
			
			if (x == -1) 
				printf("FILE Open Error!\n");

			length = read(x, &buffer, BUFFER_SIZE * 2);

			close(x);
			/*perror("Error");
			exit(-1);*/
		}
		waitpid(process, NULL, 0);
	}

	printf("[%d]", length);

	return match;
}

void build_argv(char *tokens[BUFFER_SIZE], char *argv[BUFFER_SIZE], int NOTokens) {
	argv[0] = "Cprogram";

	if (NOTokens == 1) {
		argv[1] = NULL;
	} else {
		for (int i = 1; i < NOTokens; ++i) 
			argv[i] = tokens[i];

		argv[NOTokens] = NULL;
	}
}

void build_file_path(char file[BUFFER_SIZE], char *token) {
	if (program_definer(token)) {
		strcpy(file, "/bin/");
		strcat(file, token);
	} else 
		strcpy(file, token);
}

void exec_program(char *tokens[BUFFER_SIZE], int NOTokens) {
	char *argv[BUFFER_SIZE];
	char file[BUFFER_SIZE];
	
	build_argv(tokens, argv, NOTokens);
	build_file_path(file, tokens[0]);

	pid_t process = fork();
	int wstatus;

	if (process == 0) {
		execv(file, argv);
		perror("Error");
		exit(-1);
	}

	waitpid(process, &wstatus, 0);
}