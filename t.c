#include <libc.h>
#include <stdlib.h>
#include <string.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <sys/stat.h>

int main() {
	char *input;

	while (1) {
		input = readline("Input> ");
		if (!input)
			break;
		if (*input)
			add_history(input);
		if (strcmp(input, "cwd") == 0) {
			printf("%s\n", getcwd(NULL, 0));
		} else if (!strcmp(input, "cd")) {
			chdir("/tmp");
		} else {
			printf("You entered: %s\n", input);
		}
		free(input);
	}
	return 0;
}