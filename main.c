#include "execution.h"

int main(void) {
	char buffer[BUFFER_SIZE];
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
		exec_program(tokens, t);

		t = 0;
		memset(&tokens, 0, BUFFER_SIZE);
		memset(buffer, 0, BUFFER_SIZE);
	}

	return 0;
}