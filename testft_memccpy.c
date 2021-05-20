#include "libft.h"
#include "libtest.h"

static int compare_original_memccpy ()
{
	int success = 1;
	char dest[40]    = "----------------------------------------";
	char ft_dest[40] = "----------------------------------------";
	char src[40]     = "AAAAAAAAAAAAAA_AAAAAAAAAAAAAAAAAAAAAAAAA";
	char ft_src[40]  = "AAAAAAAAAAAAAA_AAAAAAAAAAAAAAAAAAAAAAAAA";
	int	c = '_';
	int size = 10;

	memccpy(&dest[10], &src[10], c, size);
	ft_memccpy(&ft_dest[10], &ft_src[10], c, size);

	for (int i = 0; i < 40; i++)
		if (dest[i] != ft_dest[i])
			success = 0;

	print_success("Test original (c before n)", success);
	if (!success)
		explain_expected_diff(dest, ft_dest);
	return (success);
}

static int compare_original_memccpy_n()
{
	int success = 1;
	char dest[40]    = "----------------------------------------";
	char ft_dest[40] = "----------------------------------------";
	char src[40]     = "AAAAAAAAAAAAAAAAAAAAAAAAA_AAAAAAAAAAAAAB";
	char ft_src[40]  = "AAAAAAAAAAAAAAAAAAAAAAAAA_AAAAAAAAAAAAAC";
	int	c = '_';
	int size = 5;

	memccpy(&dest[10], &src[10], c, size);
	ft_memccpy(&ft_dest[10], &ft_src[10], c, size);

	for (int i = 0; i < 40; i++)
		if (dest[i] != ft_dest[i])
			success = 0;

	print_success("Test original (n before c)", success);
	if (!success)
		explain_expected_diff(dest, ft_dest);
	return (success);
}

static int test_return_pointer()
{
	int	success = 1;
	char *result;
	char *ft_result;
	char ft_dest[40];

	for (int i = 0; i < 40; i++)
		ft_dest[i] = 'A' + i;
	ft_dest[9] = '-';

	// the parameters don't matter, they just need to be valid
	result    =    memccpy(ft_dest + 8, ft_dest + 4, '-', 7);
	for (int i = 0; i < 40; i++)
		ft_dest[i] = 'A' + i;
	ft_dest[9] = '-';
	ft_result = ft_memccpy(ft_dest + 8, ft_dest + 4, '-', 7);
	if (result != ft_result)
		success = 0;

	print_success("Test return value (c before n)", success);

	if (!success)
		explain_expected_pointer(result, ft_result);
	return (success);
}

static int test_return_pointer_n()
{
	int	success = 1;
	char *result;
	char *ft_result;
	char ft_dest[40];

	for (int i = 0; i < 40; i++)
	{
		ft_dest[i] = 'A' + i;
	}
	ft_dest[9] = '-';

	// the parameters don't matter, they just need to be valid
	result    =    memccpy(ft_dest + 8, ft_dest + 4, '-', 3);
	ft_result = ft_memccpy(ft_dest + 8, ft_dest + 4, '-', 3);
	if (result != ft_result)
		success = 0;

	print_success("Test return value (n before c)", success);

	if (!success)
		explain_expected_pointer(result, ft_result);
	return (success);
}

int	testft_memccpy(void)
{
	int	original_test = compare_original_memccpy();
	int	original_test_n = compare_original_memccpy_n();
	int	return_test = test_return_pointer();
	int	return_test_n = test_return_pointer_n();

	return (original_test && original_test_n && return_test && return_test_n);
}
