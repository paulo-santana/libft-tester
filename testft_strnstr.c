#include "libft.h"
#include "libtest.h"

static int test_normal_conditions(void)
{
	int success = 1;
	char *str = "A vida e loka";
	char *target = "vida";

	char *result = strnstr(str, target, strlen(str));
	char *ft_result = ft_strnstr(str, target, ft_strlen(str));
	
	if (result != ft_result)
		success = 0;
	print_success("Test with normal conditions", success);
	if (!success)
		explain_expected_pointer(result, ft_result);
	return (success);
}

static int test_unfindable(void)
{
	int success = 1;
	char *str = "A vida e loka";
	char *target = "pppp";

	char *result = strnstr(str, target, strlen(str));
	char *ft_result = ft_strnstr(str, target, ft_strlen(str));
	
	if (result != ft_result)
		success = 0;
	print_success("Test with a string that isn't there", success);
	if (!success)
		explain_expected_pointer(result, ft_result);
	return (success);
}

static int test_almost_findable(void)
{
	int success = 1;
	char *str = "A vida e loka";
	char *target = "vidu";

	char *result = strnstr(str, target, strlen(str));
	char *ft_result = ft_strnstr(str, target, ft_strlen(str));
	
	if (result != ft_result)
		success = 0;
	print_success("Test with a string that is almost findable", success);
	if (!success)
		explain_expected_pointer(result, ft_result);
	return (success);
}

static int test_empty_target(void)
{
	int success = 1;
	char *str = "A vida e loka";
	char *target = "";

	char *result = strnstr(str, target, strlen(str));
	char *ft_result = ft_strnstr(str, target, ft_strlen(str));
	
	if (result != ft_result)
		success = 0;
	print_success("Test with an empty target", success);
	if (!success)
		explain_expected_pointer(result, ft_result);
	return (success);
}

static int test_both_equal(void)
{
	int success = 1;
	char *str = "A vida e loka";
	char *target = "A vida e loka";

	char *result = strnstr(str, target, strlen(str));
	char *ft_result = ft_strnstr(str, target, ft_strlen(str));
	
	if (result != ft_result)
		success = 0;
	print_success("Test with identical strings", success);
	if (!success)
		explain_expected_pointer(result, ft_result);
	return (success);
}

static int test_match_end(void)
{
	int success = 1;
	char *str = "A vida e loka";
	char *target = "loka";

	char *result = strnstr(str, target, strlen(str));
	char *ft_result = ft_strnstr(str, target, ft_strlen(str));
	
	if (result != ft_result)
		success = 0;
	print_success("Test matching the end", success);
	if (!success)
		explain_expected_pointer(result, ft_result);
	return (success);
}

static int test_target_longer_than_str(void)
{
	int success = 1;
	char *str = "A vida e loka";
	char *target = "loka!#aA";

	char *result = strnstr(str, target, strlen(str));
	char *ft_result = ft_strnstr(str, target, ft_strlen(str));
	
	if (result != ft_result)
		success = 0;
	print_success("Test with a target longer than str", success);
	if (!success)
		explain_expected_pointer(result, ft_result);
	return (success);
}

static int test_a_match_after_n(void)
{
	int success = 1;
	char *str = "A vida e loka";
	char *target = "loka";

	char *result = strnstr(str, target, 7);
	char *ft_result = ft_strnstr(str, target, 7);
	
	if (result != ft_result)
		success = 0;
	print_success("Test with a matching string that comes after n", success);
	if (!success)
		explain_expected_pointer(result, ft_result);
	return (success);
}

static int test_with_an_empty_string(void)
{
	int success = 1;
	char *str = "";
	char *target = "loka";

	char *result = strnstr(str, target, 7);
	char *ft_result = ft_strnstr(str, target, 7);
	
	if (result != ft_result)
		success = 0;
	print_success("Test with an empty string", success);
	if (!success)
		explain_expected_pointer(result, ft_result);
	return (success);
}

int testft_strnstr(void)
{
	int test1 = test_normal_conditions();
	int test2 = test_unfindable();
	int test3 = test_almost_findable();
	int test4 = test_empty_target();
	int test5 = test_both_equal();
	int test6 = test_match_end();
	int test7 = test_target_longer_than_str();
	int test8 = test_a_match_after_n();
	int test9 = test_with_an_empty_string();

	return (test1 && test2 && test3 && test4 
			&& test5 && test6 && test7 && test8 && test9);
}
