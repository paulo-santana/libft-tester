#include "libft.h"
#include "libtest.h"

static int test_both_equal()
{
	int success = 1;
	char strA[] = "kk eae men";
	char strB[] = "kk eae men";
	int size = 10;

	int result = strncmp(strA, strB, size);
	int ft_result = ft_strncmp(strA, strB, size);

	if (result != ft_result)
		success = 0;
	print_success("Test equal strings and size is their len", success);
	if (!success)
		explain_expected_int(result, ft_result);
	return (success);
}

static int test_a_less_than_b()
{
	int success = 1;
	char strA[] = "kk eae man";
	char strB[] = "kk eae men";
	int size = 10;

	int result = strncmp(strA, strB, size);
	int ft_result = ft_strncmp(strA, strB, size);

	if (result != ft_result)
		success = 0;
	print_success("Test where strA is less than B", success);
	if (!success)
		explain_expected_int(result, ft_result);
	return (success);
}

static int test_a_greater_than_b()
{
	int success = 1;
	char strA[] = "kk eae men";
	char strB[] = "kk eaa men";
	int size = 10;

	int result = strncmp(strA, strB, size);
	int ft_result = ft_strncmp(strA, strB, size);

	if (result != ft_result)
		success = 0;
	print_success("Test where strA is greater than B", success);
	if (!success)
		explain_expected_int(result, ft_result);
	return (success);
}

static int test_difference_after_nul()
{
	int success = 1;
	char strA[] = "kk e\0ae-men";
	char strB[] = "kk e\0ae men";
	int size = 10;

	int result = strncmp(strA, strB, size);
	int ft_result = ft_strncmp(strA, strB, size);

	if (result != ft_result)
		success = 0;
	print_success("Test where the difference comes after the '\\0'", success);
	if (!success)
		explain_expected_int(result, ft_result);
	return (success);
}

static int test_unsigned_char()
{
	int success = 1;
	char strA[] = "kk e\200ae-men";
	char strB[] = "kk e\0ae men";
	int size = 10;

	int result = strncmp(strA, strB, size);
	int ft_result = ft_strncmp(strA, strB, size);

	if (result != ft_result)
		success = 0;
	print_success("Test where there's a \\200 vs \\0 comparison", success);
	if (!success)
		explain_expected_int(result, ft_result);
	return (success);
}

int	testft_strncmp()
{
	int test1 = test_both_equal();
	int test2 = test_a_less_than_b();
	int test3 = test_a_greater_than_b();
	int test4 = test_difference_after_nul();
	int test5 = test_unsigned_char();

	return (test1 && test2 && test3 && test4 && test5);
}
