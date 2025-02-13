#include <stdio.h>
#include <stdlib.h>

#include <readline/readline.h>
#include <readline/history.h>

void	check()
{
	system("leaks a.out");
}

int main()
{
	while (1)
	{
		char *s = readline("test> ");
		if (!s)
			break ;
		printf("%s\n", s);
		free(s);
	}
	atexit(check);
	return 0;
}