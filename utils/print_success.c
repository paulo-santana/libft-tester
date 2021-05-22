#include "../libtest.h"

void	print_success(char *msg, int success)
{
	printf("   ");
	if (success)
		printf(BOLD GREEN " Ok" RESET);
	else
		printf(BOLD RED   "KO :(" );
	printf("  ");
	while (*msg)
	{
		if (isprint(*msg))
			printf("%c", *msg);
		else
			printf(BLUE "[char %d]" RESET, *msg);
		msg++;
	}
	printf("\n"RESET);
}
