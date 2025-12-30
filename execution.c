#include "execution.h"

void builtin_funcs_handler(char *tokens[], int NOTokens) {
	char buffer[BUFFER_SIZE];
	for (int i = 0; i < NOTokens; ++i) {
		strcat(buffer, tokens[i]);
	}

	printf("[%s]\n", buffer);
	char *argv[5] = {"sh", "-c", buffer, NULL};
	int process;
	if ((process = fork()) == 0) {
		execv("/bin/sh", argv);

		perror("execv error");
		exit(-1);
	}
	waitpid(process, NULL, 0);
}

int program_definer(char *token) {
	DIR *dir = opendir("/bin");
	struct dirent *read_dir;
	int match = 0;
	int process;

	while (read_dir = readdir(dir)) {
		if (strcmp(token, read_dir->d_name) == 0)
			match = 1;
	}

	closedir(dir);

	if (match == 0) {
		FILE *tmp_file = fopen("/tmp/compgen_b.txt", "wb+");
		int tmp_file_fd = fileno(tmp_file);

		if ((process = fork()) == 0) { 
			dup2(tmp_file_fd, STDOUT_FILENO);

			char *argv[5] = {"sh", "-c", "compgen -b", NULL};
			execv("/bin/sh", argv);

			perror("execv error");
			exit(-1);
		}

		waitpid(process, NULL, 0);

		match = 2;

		fclose(tmp_file);
	}

	return match;
}

void build_argv(char *tokens[BUFFER_SIZE], char *argv[BUFFER_SIZE], int NOTokens) {
	int PD = program_definer(tokens[0]);
	if (PD) {
		argv[0] = "Cprogram";

		if (NOTokens == 1) {
			argv[1] = NULL;
		} else {
			for (int i = 1; i < NOTokens; ++i) 
				argv[i] = tokens[i];

			argv[NOTokens] = NULL;
		}
	}
	if (PD == 2) {
		char tmp_buffer[BUFFER_SIZE];
		argv[0] = "sh";
		argv[1] = "-c";

		for (int i = 0; i < NOTokens; ++i) { 
			strcat(tmp_buffer, tokens[i]);
			if (i+1 != NOTokens)
				strcat(tmp_buffer, " ");
		}

		argv[2] = strdup(tmp_buffer);

		argv[3] = NULL;

		memset(tmp_buffer, 0, BUFFER_SIZE);
	}
}

void build_file_path(char file[BUFFER_SIZE], char *tokens[], int NOTokens) {
	int PD = program_definer(tokens[0]);
	if (PD == 1) {
		strcpy(file, "/bin/");
		strcat(file, tokens[0]);
	}
	if (PD == 2)
		strcpy(file, "/bin/sh");
}

void start() {
	char buffer[1024];
	FILE *file = fopen("menu.txt", "r");

	while (fgets(buffer, BUFFER_SIZE, file) != NULL)
		printf("%s", buffer);

	putchar('\n');

	fclose(file);
}

void exec_program(char *tokens[BUFFER_SIZE], int NOTokens, char *path) {
	char *argv[BUFFER_SIZE];
	char file[BUFFER_SIZE];

	build_argv(tokens, argv, NOTokens);
	build_file_path(file, tokens, NOTokens);

	pid_t process = fork();
	int wstatus;

	if (process == 0) {
		chdir(path);
		execv(file, argv);
		perror("Error");
		exit(-1);
	}

	waitpid(process, &wstatus, 0);
}