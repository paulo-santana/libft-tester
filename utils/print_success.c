#include "../libtest.h"

char *get_success_msg(char *format, char *test_str)
{

	char *msg = malloc(sizeof(char) * (strlen(format) + strlen(test_str) + 1));
	if (!msg)
	{
		warn_alloc_fail("malloc");
		return (0);
	}
		
	sprintf(msg, format, test_str);
	return (msg);
}

void	print_success(char *msg, int success)
{
	printf("   ");
	if (success)
		printf(BOLD GREEN " Ok" RESET);
	else
		printf(BOLD RED   "KO :(" );
	printf("  ");
	int inside_quotes = 0;
	while (*msg)
	{
		if (*msg == '"')
		{
			if (inside_quotes && inside_quotes--)
				printf("\"" RESET);
			else if (++inside_quotes)
				printf(MAGENTA "\"");
		}
		else if (isprint(*msg))
			printf("%c", *msg);
		else
			printf("[char %d]", *msg);
		msg++;
	}
	printf("\n"RESET);
}
