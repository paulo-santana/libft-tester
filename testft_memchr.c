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

static int test_non_findable()
{

	int success = 1;
	char str[40] = "aaaaaaaaaaaaaaa";

	int size = 10;

	int *index = memchr(str, '-', size);
	int *ft_index = ft_memchr(str, '-', size);
	if (ft_index != index)
		success = 0;

	print_success("Test non findable", success);
	if (!success)
		explain_expected_pointer(index, ft_index);
	return (success);
}

int testft_memchr(void)
{
	int	original_test = compare_original_memchr();
	int	not_found_test = test_non_findable();

	return (original_test && not_found_test);
}
