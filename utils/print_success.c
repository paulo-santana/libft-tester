#include "../libtest.h"

void	print_success(char *msg, int success)
{
	printf("   ");
	if (success)
		printf(BOLD GREEN " Ok" RESET);
	else
		printf(BOLD RED   "KO :(" );
	printf("  %s\n" RESET, msg);
}
