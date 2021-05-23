#include "libtest.h"
#include "libft.h"

static int get_strings(char *src, char **result, char **ft_result)
{
	*result = strdup(src);
	if (!result)
	{
		warn_alloc_fail("strdup");
		return (0);
	}
	*ft_result = ft_strdup(src);
	if (!ft_result)
	{
		warn_alloc_fail("ft_strdup");
		free(*result);
		return (0);
	}
	return (1);
}

static int test_with_normal_conditions()
{
	int success = 1;
	char *src = "abcdefghijklmnopqrst";
	char *result = NULL;
	char *ft_result = NULL;

	if (!get_strings(src, &result, &ft_result))
		return (0);
	int src_len = strlen(src);
	for (int i = 0; i <= src_len; i++)
		if (result[i] != ft_result[i])
			success = 0;
	print_success("Testing with normal conditions", success);
	if (!success)
		explain_expected_diff(result, ft_result, src_len);
	free(result);
	free(ft_result);
	return (success);
}

static int test_with_empty_src()
{
	int success = 1;
	char *src = "";
	char *result = NULL;
	char *ft_result = NULL;

	if (!get_strings(src, &result, &ft_result))
		return (0);
	int src_len = strlen(src);
	for (int i = 0; i <= src_len; i++)
		if (result[i] != ft_result[i])
			success = 0;
	print_success("Testing with empty src", success);
	if (!success)
		explain_expected_diff(result, ft_result, src_len);
	free(result);
	free(ft_result);
	return (success);
}

static int test_with_src_1_len()
{
	int success = 1;
	char *src = "q";
	char *result = NULL;
	char *ft_result = NULL;

	if (!get_strings(src, &result, &ft_result))
		return (0);
	int src_len = strlen(src);
	for (int i = 0; i <= src_len; i++)
		if (result[i] != ft_result[i])
			success = 0;
	print_success("Testing with src \"q\"", success);
	if (!success)
		explain_expected_diff(result, ft_result, src_len);
	free(result);
	free(ft_result);
	return (success);
}

int testft_strdup()
{
	int test1 = test_with_normal_conditions();
	int test2 = test_with_empty_src();
	int test3 = test_with_src_1_len();

	return (test1 && test2 && test3);
}
