#include "libft.h"
#include "libtest.h"

static int test_with_normal_conditions()
{
	int success = 1;

	char *src = "a vida e loka mano";
	char *expected = "vida";
	char *result = ft_substr(src, 2, 4);

	if (!result)
	{
		printf(YELLOW "    ft_substr: Memory allocation failed" RESET);
		exit(2);
	}
	for (int i = 0; i <= 4; i++)
		if (result[i] != expected[i])
			success = 0;
	print_success("Test with normal conditions", success);
	if (!success)
		explain_expected_diff(expected, result, 5);
	free(result);
	return (success);
}

static int test_with_size_zero()
{
	int success = 1;

	char *src = "a vida e loka mano";
	char *expected = "";
	char *result = ft_substr(src, 2, 0);

	if (!result)
	{
		printf(YELLOW "    ft_substr: Memory allocation failed" RESET);
		exit(2);
	}
	for (int i = 0; i <= 0; i++)
		if (result[i] != expected[i])
			success = 0;
	print_success("Test with size 0", success);
	if (!success)
		explain_expected_diff(expected, result, 1);
	free(result);
	return (success);
}

static int test_with_size_one()
{
	int success = 1;

	char *src = "a vida e loka mano";
	char *expected = "l";
	char *result = ft_substr(src, 9, 1);

	if (!result)
	{
		printf(YELLOW "    ft_substr: Memory allocation failed" RESET);
		exit(2);
	}
	for (int i = 0; i <= 1; i++)
		if (result[i] != expected[i])
			success = 0;
	print_success("Test with size 1", success);
	if (!success)
		explain_expected_diff(expected, result, 2);
	free(result);
	return (success);
}

static int test_with_size_two()
{
	int success = 1;

	char *src = "a vida e loka mano";
	char *expected = "lo";
	char *result = ft_substr(src, 9, 2);

	if (!result)
	{
		printf(YELLOW "    ft_substr: Memory allocation failed" RESET);
		exit(2);
	}
	for (int i = 0; i <= 2; i++)
		if (result[i] != expected[i])
			success = 0;
	print_success("Test with size 2", success);
	if (!success)
		explain_expected_diff(expected, result, 3);
	free(result);
	return (success);
}

static int test_with_size_bigger_than_src()
{
	int success = 1;

	char *src = "a vida e loka mano";
	char *expected = "loka mano";
	char *result = ft_substr(src, 9, 50);

	if (!result)
	{
		printf(YELLOW "    ft_substr: Memory allocation failed" RESET);
		exit(2);
	}
	for (int i = 0; i <= 9; i++)
		if (result[i] != expected[i])
			success = 0;
	print_success("Test with size bigger than src", success);
	if (!success)
		explain_expected_diff(expected, result, 9);
	free(result);
	return (success);
}

static int test_with_negative_size()
{
	int success = 1;

	char *src = "a vida e loka mano";
	char *expected = "loka mano";
	char *result = ft_substr(src, 9, -15);

	if (!result)
	{
		printf(YELLOW "    ft_substr: Memory allocation failed\n" RESET);
		exit(2);
	}
	for (int i = 0; i <= 9; i++)
		if (result[i] != expected[i])
			success = 0;
	print_success("Test with a negative size of -15 >:)", success);
	if (!success)
		explain_expected_diff(expected, result, 10);
	free(result);
	return (success);
}

int testft_substr()
{
	int test1 = test_with_normal_conditions();
	int test2 = test_with_size_zero();
	int test3 = test_with_size_one();
	int test4 = test_with_size_two();
	int test5 = test_with_size_bigger_than_src();
	int test6 = test_with_negative_size();

	return (test1 && test2 && test3 && test4 && test5 && test6);
}
