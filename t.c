#include <libc.h>
#include <stdlib.h>
#include <string.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <sys/ioctl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>

#include <stdio.h>
#include <term.h>
#include <curses.h>

int main() {
	struct dirent
	char s[1000];
	printf("%s\n", getcwd(s, 1000));
	printf("%s\n", s);
}
