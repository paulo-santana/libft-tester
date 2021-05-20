#include "libft.h"
#include "libtest.h"

static int test_normal_conditions(void)
{
	int success = 1;
	char *str = "o duq.ue de ca.chi.as.   .    ";
	char c = '.';

	char *pos = strrchr(str, c);
	char *ft_pos = ft_strrchr(str, c);

	if (pos != ft_pos)
		success = 0;
	print_success("Test normal", success);
	if (!success)
		explain_expected_pointer(pos, ft_pos);
	return (success);
}
int testft_strrchr(void)
{
	int test1 = test_normal_conditions();

	return (test1);
}
