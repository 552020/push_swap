#include <stdio.h>

int main(int argc, char **argv)
{
	printf("argc: %d\n", argc);
	while (*argv)
	{
		printf("argv: %s\n", *argv);
		argv++;
	}

	return (0);
}