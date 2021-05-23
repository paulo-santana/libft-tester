#include "libft.h"
#include "libtest.h"

static int test_normal_conditions()
{
	int success = 1;
	char *str1 = "sabia que o sabia";
	char *str2 = " nao sabia assobiar?";
	char *expected = "sabia que o sabia nao sabia assobiar?";

	char *result = ft_strjoin(str1, str2);
	if (!result)
	{
		warn_alloc_fail("ft_strjoin");
		return (0);
	}
	int len = strlen(expected);
	for (int i = 0; i <= len; i++)
		if (result[i] != expected[i])
			success = 0;
	print_success("Test with normal conditions", success);
	if (!success)
		explain_expected_diff(expected, result, len + 1);
	free(result);
	return (success);
}

static int test_empty_s1()
{
	int success = 1;
	char *str1 = "";
	char *str2 = " faca uma limonada";
	char *expected = " faca uma limonada";

	char *result = ft_strjoin(str1, str2);
	if (!result)
	{
		warn_alloc_fail("ft_strjoin");
		return (0);
	}
	int len = strlen(expected);
	for (int i = 0; i <= len; i++)
		if (result[i] != expected[i])
			success = 0;
	print_success("Test with str1 being empty", success);
	if (!success)
		explain_expected_diff(expected, result, len + 1);
	free(result);
	return (success);
}

static int test_empty_s2()
{
	int success = 1;
	char *str1 = "Se a vida te der limoes,";
	char *str2 = "";
	char *expected = "Se a vida te der limoes,";

	char *result = ft_strjoin(str1, str2);
	if (!result)
	{
		printf(YELLOW "    ft_strjoin(): memory allocation failed\n" RESET);
		return (0);
	}
	int len = strlen(expected);
	for (int i = 0; i <= len; i++)
		if (result[i] != expected[i])
			success = 0;
	print_success("Test with str2 being empty", success);
	if (!success)
		explain_expected_diff(expected, result, len + 1);
	free(result);
	return (success);
}

static int test_with_both_empty()
{
	int success = 1;
	char *str1 = "";
	char *str2 = "";
	char *expected = "";

	char *result = ft_strjoin(str1, str2);
	if (!result)
	{
		printf(YELLOW "    ft_strjoin(): memory allocation failed\n" RESET);
		exit(2);
	}
	int len = strlen(expected);
	for (int i = 0; i <= len; i++)
		if (result[i] != expected[i])
			success = 0;
	print_success("Test with both strings empty", success);
	if (!success)
		explain_expected_diff(expected, result, len + 1);
	free(result);
	return (success);
}

int testft_strjoin()
{
	int test1 = test_normal_conditions();
	int test2 = test_empty_s1();
	int test3 = test_empty_s2();
	int test4 = test_with_both_empty();

	return (test1 && test2 && test3 && test4);
}
