#include "libft.h"
#include "libtest.h"

static char *get_success_msg(char *format, char *test_str)
{

	char *msg = malloc(sizeof(char) * (strlen(format) + strlen(test_str) + 1));
	if (!msg)
	{
		warn_alloc_fail("malloc");
		return (0);
	}
		
	sprintf(msg, format, test_str);
	return (msg);
}

static int test_trimming_spaces()
{
	int success = 1;
	char *test_str = "      qqqqqqqq    ";
	char set[] = {' ', '\0'};
	char *expected = "qqqqqqqq";

	(void)expected;
	char *result = ft_strtrim(test_str, set);
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
	char *format = "Test trimming spaces from string \"%s\"";
	char *msg = get_success_msg(format, test_str);
	if (!msg)
		return (0);
	print_success(msg, success);
	free(msg);
	if (!success)
		explain_expected_diff(expected, result, len + 1);
	free(result);
	return (success);
}

static int test_trimming_two_characteres()
{
	int success = 1;
	char *test_str = " a  a qqqqqqqq aaa";
	char set[] = {' ', 'a', '\0'};
	char *expected = "qqqqqqqq";

	(void)expected;
	char *result = ft_strtrim(test_str, set);
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
	char *format = "Test trimming \" a\" from string \"%s\"";
	char *msg = get_success_msg(format, test_str);
	if (!msg)
		return (0);
	print_success(msg, success);
	free(msg);
	if (!success)
		explain_expected_diff(expected, result, len + 1);
	free(result);
	return (success);
}

static int test_trimming_three_characteres()
{
	int success = 1;
	char *test_str = " a bba b  a qqqqqqqq aab a";
	char set[] = {'b', ' ', 'a', '\0'};
	char *expected = "qqqqqqqq";

	(void)expected;
	char *result = ft_strtrim(test_str, set);
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
	char *format = "Test trimming \"b a\" from string \"%s\"";
	char *msg = get_success_msg(format, test_str);
	if (!msg)
		return (0);
	print_success(msg, success);
	free(msg);
	if (!success)
		explain_expected_diff(expected, result, len + 1);
	free(result);
	return (success);
}

static int test_trimming_all_characters()
{
	int success = 1;
	char *test_str = " a bba b  a qqqqqqqq aab a";
	char set[] = {'b', ' ', 'q', 'a', '\0'};
	char *expected = "";

	(void)expected;
	char *result = ft_strtrim(test_str, set);
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
	char *format = "Test trimming \"b qa\" from string \"%s\"";
	char *msg = get_success_msg(format, test_str);
	if (!msg)
		return (0);
	print_success(msg, success);
	free(msg);
	if (!success)
		explain_expected_diff(expected, result, len + 1);
	free(result);
	return (success);
}

static int test_with_characteres_that_arent_there()
{
	int success = 1;
	char *test_str = " a bba b  a qqqqqqqq aab a";
	char set[] = {'c', 'g', 'm', 'g', '\0'};
	char *expected = " a bba b  a qqqqqqqq aab a";

	(void)expected;
	char *result = ft_strtrim(test_str, set);
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
	char *format = "Test trimming \"cgmb\" from string \"%s\"";
	char *msg = get_success_msg(format, test_str);
	if (!msg)
		return (0);
	print_success(msg, success);
	free(msg);
	if (!success)
		explain_expected_diff(expected, result, len + 1);
	free(result);
	return (success);
}

int testft_strtrim()
{
	int test1 = test_trimming_spaces();
	int test2 = test_trimming_two_characteres();
	int test3 = test_trimming_three_characteres();
	int test4 = test_trimming_all_characters();
	int test5 = test_with_characteres_that_arent_there();

	return (test1 && test2 && test3 && test4 && test5);
}
