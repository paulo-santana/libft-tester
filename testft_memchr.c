#include "libft.h"
#include "libtest.h"

int compare_original_memchr(void)
{
	int success = 1;
	char str[40] = "aaaa-aaaabbbbbb";

	int size = 10;

	int *index = memchr(str, '-', size);
	int *ft_index = ft_memchr(str, '-', size);
	if (ft_index != index)
		success = 0;

	print_success("Test Original", success);
	if (!success)
		explain_expected_pointer(index, ft_index);
	return (success);
}

static int test_not_foundable()
{

	int success = 1;
	char str[40] = "aaaaaaaaaaaaaaa";

	int size = 10;

	int *index = memchr(str, '-', size);
	int *ft_index = ft_memchr(str, '-', size);
	if (ft_index != index)
		success = 0;

	print_success("Test not foundable", success);
	if (!success)
		explain_expected_pointer(index, ft_index);
	return (success);
}

int testft_memchr(void)
{
	int	original_test = compare_original_memchr();
	int	not_found_test = test_not_foundable();

	return (original_test && not_found_test);
}
