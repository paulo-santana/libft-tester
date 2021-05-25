#include "libft.h"
#include "libtest.h"

static int test_trimming_spaces()
{
	int success = 1;
	char *test_str = "      qqqqqqqq    ";
	char set[] = {' ', '\0'};
	char *expected = "qqqqqqqq";

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
	char set[] = "b a";
	char *test_str = " a bba b  a --- a-   b----- aab a";
	char *expected =             "--- a-   b-----";

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

static int test_with_len_1_but_untrimmable()
{
	int success = 1;
	char *test_str = "a";
	char set[] = {'c', 'g', 'm', 'g', '\0'};
	char *expected = "a";

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

static int test_with_len_1_and_trimmable()
{
	int success = 1;
	char *test_str = "a";
	char set[] = {'c', 'a', 'm', 'g', '\0'};
	char *expected = "";

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
	char *format = "Test trimming \"camb\" from string \"%s\"";
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

static int test_with_empty_set()
{
	int success = 1;
	char *test_str = "abcd kkk opa    ";
	char set[] = "";
	char *expected = "abcd kkk opa    ";

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
	char *format = "Test trimming \"\" from string \"%s\"";
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
	int test6 = test_with_len_1_but_untrimmable();
	int test7 = test_with_len_1_and_trimmable();
	int test8 = test_with_empty_set();

	return (test1 && test2 && test3 && test4 && test5 && test6
			&& test7 && test8);
}
