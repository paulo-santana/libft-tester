#include "libft.h"
#include "libtest.h"

int compare_original_memcmp_equal()
{
	int success = 1;
	char memA[] = "bcdgefhgzb";
	char memB[] = "bcdgefhgzbc";
	int size = 7;
	int result;
	int ft_result;

	result = memcmp(memA, memB, size);
	ft_result = ft_memcmp(memA, memB, size);

	if (result != ft_result)
		success = 0;
	print_success("Test Original with equal strings", success);
	if (!success)
		explain_expected_int(result, ft_result);
	return (success);
}

int test_diff_positive()
{
	int success = 1;
	char memA[] = "55595555555";
	char memB[] = "55555555555";
	int size = 7;
	int ft_result;

	ft_result = ft_memcmp(memA, memB, size);

	if (!(ft_result > 0))
		success = 0;
	print_success("Test Original with memA bigger", success);
	return (success);
}

int test_diff_negative()
{
	int success = 1;
	char memA[] = "55555555555";
	char memB[] = "55595555555";
	int size = 7;
	int ft_result;

	ft_result = ft_memcmp(memA, memB, size);

	if (!(ft_result < 0))
		success = 0;
	print_success("Test Original with memA smaller", success);
	return (success);
}


static int test_n_before_diff()
{
	int success = 1;
	char memA[] = "abcdefghijk";
	char memB[] = "abcdefghi-k";
	int size = 7;
	int result;
	int ft_result;

	result = memcmp(memA, memB, size);
	ft_result = ft_memcmp(memA, memB, size);

	if (result != ft_result)
		success = 0;
	print_success("Test with difference after n", success);
	if (!success)
		explain_expected_int(result, ft_result);
	return (success);
}

static int test_with_n_zero()
{
	int success = 1;
	char memA[] = "abcdefghijk";
	char memB[] = "abcdefghi-k";
	int size = 0;
	int result;
	int ft_result;

	result = memcmp(memA, memB, size);
	ft_result = ft_memcmp(memA, memB, size);

	if (result != ft_result)
		success = 0;
	print_success("Test with n = 0", success);
	if (!success)
		explain_expected_int(result, ft_result);
	return (success);
}

int testft_memcmp(void)
{
	int	original_equal_test = compare_original_memcmp_equal();
	int	n_before_diff_result = test_n_before_diff();
	int	n_zero = test_with_n_zero();
	int positive_result = test_diff_positive();
	int negative_result = test_diff_negative();

	return (original_equal_test && n_before_diff_result &&
			n_zero && positive_result && negative_result);
}
