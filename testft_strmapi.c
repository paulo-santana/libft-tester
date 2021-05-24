#include "libft.h"

#include "libtest.h"

static char toogle_case(unsigned int i, char c)
{
	(void)i;
	return (islower(c) ? toupper(c) : tolower(c));
}

static char shift(unsigned int i, char c)
{
	(void)i;
	return (c + 1);
}

static int test_normal_conditions()
{
	int success = 1;
	char *str = "Alo galera de cowboy";
	char *expected = "aLO GALERA DE COWBOY";

	char *result = ft_strmapi(str, &toogle_case);
	if (!result)
	{
		warn_alloc_fail("ft_strmapi");
		return (0);
	}
	if (memcmp(expected, result, strlen(expected) + 1) != 0)
		success = 0;
	print_success("Test toggling case", success);
	if (!success)
		explain_expected_diff(expected, result, strlen(expected) + 1);
	free(result);
	return (success);
}

static int test_with_empty_string()
{
	int success = 1;
	char *str = "";
	char *expected = "";

	char *result = ft_strmapi(str, &toogle_case);
	if (!result)
	{
		warn_alloc_fail("ft_strmapi");
		return (0);
	}
	if (memcmp(expected, result, strlen(expected) + 1) != 0)
		success = 0;
	print_success("Test with an empty string", success);
	if (!success)
		explain_expected_diff(expected, result, strlen(expected) + 1);
	free(result);
	return (success);
}

static int test_with_another_function()
{
	int success = 1;
	char *str = "kk daora po";
	char *expected = "ll!ebpsb!qp";

	char *result = ft_strmapi(str, &shift);
	if (!result)
	{
		warn_alloc_fail("ft_strmapi");
		return (0);
	}
	if (memcmp(expected, result, strlen(expected) + 1) != 0)
		success = 0;
	print_success("Test with another function", success);
	if (!success)
		explain_expected_diff(expected, result, strlen(expected) + 1);
	free(result);
	return (success);
}

int testft_strmapi()
{
	int test1 = test_normal_conditions();
	int test2 = test_with_empty_string();
	int test3 = test_with_another_function();

	return (test1 && test2 && test3);
}
