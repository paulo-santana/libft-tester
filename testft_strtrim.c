#include "libft.h"
#include "libtest.h"

static int test_trimming_spaces()
{
	int success = 1;
	char *str = "      qqqqqqqq    ";
	char set[] = {' ', '\0'};
	char *expected = "qqqqqqqq";

	(void)expected;
	char *result = ft_strtrim(str, set);
	if (!result)
	{
		warn_alloc_fail("ft_strtrim");
		return (0);
	}
	int len = strlen(expected);
	int ft_len = strlen(result);
	len = (len < ft_len) ? len : ft_len;
	for (int i = 0; i <= len; i++)
		if (expected[i] != result[i])
			success = 0;
	print_success("Test trimming spaces", success);
	if (!success)
		explain_expected_diff(expected, result, len + 1);
	free(result);
	return (success);
}

int testft_strtrim()
{
	int test1 = test_trimming_spaces();

	return (test1);
}
