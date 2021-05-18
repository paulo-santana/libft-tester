#include "libtest.h"

void	print_success(int success)
{
	if (success)
		printf(BOLD GREEN "Ok" RESET "\n");
	else
		printf(BOLD RED "KO :(" RESET "\n");
}
