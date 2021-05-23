#include "libft.h"
#include "libtest.h"

static void free_result(char **result)
{
	int i = 0;

	while (result[i])
		free(result[i++]);
	free(result);
}

static int test_with_space()
{
	int success = 1;
	char *test_str = "Opa, blz mano? Kk daora";
	char **result;
	char *expected[] = {"Opa,", "blz", "mano?", "Kk", "daora", 0};

	result = ft_split(test_str, ' ');

	if (!result)
	{
		warn_alloc_fail("ft_split");
		return (0);
	}
	int i = 0;
	while (expected[i])
	{
		if (strcmp(result[i], expected[i]) != 0)
			success = 0;
		i++;
	}
	char *msg = get_success_msg("Test splitting spaces with string \"%s\"", test_str);
	if (!msg)
	{
		warn_alloc_fail("get_success_msg");
		free_result(result);
		return (0);
	}
	print_success(msg, success);
	if (!success)
	{
		i = 0;
		while (result[i])
		{
			int len = strlen(expected[i]) + 1;
			explain_expected_diff(expected[i], result[i], len);
			i++;
		}
	}
	free(msg);
	free_result(result);
	return (success);
}

int testft_split()
{
	int test1 = test_with_space();

	return (test1);
}
