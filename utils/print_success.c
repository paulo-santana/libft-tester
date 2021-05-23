#include "../libtest.h"

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
