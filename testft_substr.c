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

int testft_substr()
{
	int test1 = test_with_normal_conditions();
	int test2 = test_with_size_zero();
	int test3 = test_with_size_one();

	return (test1 && test2 && test3);
}
