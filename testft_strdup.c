#include "libtest.h"
#include "libft.h"

static void get_strings(char *src, char **result, char **ft_result)
{
	*result = strdup(src);
	if (!result)
	{
		printf(YELLOW "    system strdup() failed to allocate memory\n" RESET);
		exit(2);
	}
	*ft_result = ft_strdup(src);
	if (!ft_result)
	{
		printf(YELLOW "    user ft_strdup() failed to allocate memory\n");
		free(result);
		exit(2);
	}
}

static int test_with_normal_conditions()
{
	int success = 1;
	char *src = "abcdefghijklmnopqrst";
	char *result = NULL;
	char *ft_result = NULL;

	get_strings(src, &result, &ft_result);
	int src_len = strlen(src);
	for (int i = 0; i < src_len; i++)
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

	get_strings(src, &result, &ft_result);
	int src_len = strlen(src);
	for (int i = 0; i < src_len; i++)
		if (result[i] != ft_result[i])
			success = 0;
	print_success("Testing with empty src", success);
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

	return (test1 && test2);
}
