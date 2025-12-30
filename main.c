#include "execution.h"

int main(void) {
	start();

	char buffer[BUFFER_SIZE], path[BUFFER_SIZE] = "/home";
	char *tokens[BUFFER_SIZE];
	char *token;
	int t = 0;
	while (1) {
		printf("$ ");
		fgets(buffer, BUFFER_SIZE, stdin);
		token = strtok(buffer, " \n");

		while (token != NULL) {
			tokens[t] = token;
			token = strtok(NULL, " \n");
			++t;
		}

		if (strstr(tokens[0], "cd") != 0) {
			chdir(tokens[1]);
			strcpy(path, tokens[1]);
		}
		else
			exec_program(tokens, t, path);

		t = 0;
		memset(&tokens, 0, BUFFER_SIZE);
		memset(buffer, 0, BUFFER_SIZE);
	}
	return 0;
}