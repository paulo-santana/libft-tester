#include "libft.h"
#include "libtest.h"

static int run_tests()
{
	int success = 1;
	int test_cases[10] = { 0, 3, 42, -9, -42, 3000, -31, 2147483647,
		-2147483648, 98128 };
	char *expected[10] = {"0", "3", "42", "-9", "-42", "3000", "-31",
		"2147483647", "-2147483648", "98128" };

	for (int i = 0; i < 10; i++)
	{
		int failed = 0;
		char *result = ft_itoa(test_cases[i]);
		if (!result)
		{
			warn_alloc_fail("ft_itoa");
			continue ;
		}
		if (memcmp(expected[i], result, strlen(expected[i])) != 0)
			failed = 1;
		char *format = "Testing with %d";
		char *str = malloc(sizeof(char) * strlen(format) + 12);
		if (!str)
		{
			warn_alloc_fail("malloc");
			continue ;
		}
		sprintf(str, format, test_cases[i]);
		print_success(str, !failed);
		if (failed)
		{
			explain_expected_diff(expected[i], result, strlen(expected[i]) + 1);
			success = 0;
		}
		free(str);
		free(result);
	}
	return (success);
}


int testft_itoa()
{
	int test1 = run_tests();

	return (test1);
}
