#include "../libtest.h"

void	warn_alloc_fail(char *failed_func)
{
	printf(YELLOW "    [%s]: memory allocation failed\n" RESET, failed_func);
}
