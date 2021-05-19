#include "libft.h"
#include "libtest.h"

static int	compare_original_memcpy()
{
	int	success = 1;
	char dest[40];
	char src[40];
	char ft_dest[40];
	char ft_src[40];
	int size = 10;

	for (int i = 0; i < 40; i++)
	{
		src[i]		= 'a';
		dest[i]		= '-';
		ft_src[i]	= 'a';
		ft_dest[i]	= '-';
	}

	memcpy(&dest[9], src, size);
	ft_memcpy(&ft_dest[9], ft_src, size);

	for (int i = 0; i < 40; i++)
		if (dest[i] != ft_dest[i])
			success = 0;

	printf("    Test Original: ");
	print_success(success);
	if (!success)
		explain_expected_diff(dest, ft_dest);
	return (success);
}

static int test_return_pointer()
{
	int success = 1;
	char dest[40];
	int size = 10;

	for (int i = 0; i < 40; i++)
		dest[i]		= i + '0';

	char *result = ft_memcpy(&dest[9], &dest[0], size);
	if (result != &dest[9])
		success = 0;
	printf("    Test return value: ");
	print_success(success);
	return (success);
}

int	testft_memcpy(void)
{
	int	original_test = compare_original_memcpy();
	int	return_test = test_return_pointer();

	return (original_test && return_test);
}
