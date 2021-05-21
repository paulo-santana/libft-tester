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

static int test_searching_the_nul()
{
	int success = 1;
	char *str = "o duq.ue de ca.chi.as.   .    ";
	char c = '\0';

	char *pos = strrchr(str, c);
	char *ft_pos = ft_strrchr(str, c);

	if (pos != ft_pos)
		success = 0;
	print_success("Test searching the '\\0' character", success);
	if (!success)
		explain_expected_pointer(pos, ft_pos);
	return (success);
}

static int test_non_existing(void)
{
	int success = 1;
	char *str = "o duq.ue de ca.chi.as.   .    ";
	char c = '\\';

	char *pos = strrchr(str, c);
	char *ft_pos = ft_strrchr(str, c);

	if (pos != ft_pos)
		success = 0;
	print_success("Test searching a non existing character", success);
	if (!success)
		explain_expected_pointer(pos, ft_pos);
	return (success);
}


int testft_strrchr(void)
{
	int test1 = test_normal_conditions();
	int test2 = test_searching_the_nul();
	int test3 = test_non_existing();

	return (test1 && test2 && test3);
}
