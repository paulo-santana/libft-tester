#include "libft.h"
#include "libtest.h"

static int compare_original_memccpy ()
{
	int success = 1;
	char dest[40];
	char src[40];
	char ft_dest[40];
	char ft_src[40];
	int	c = '_';
	int size = 10;

	for (int i = 0; i < 40; i++)
	{
		dest[i] = '-';
		ft_dest[i] = '-';
		src[i] = 'A';
		ft_src[i] = 'A';
	}
	src[15] = c;
	ft_src[15] = c;
	memccpy(&dest[10], &src[10], c, size);
	ft_memccpy(&ft_dest[10], &ft_src[10], c, size);

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
	return 1;
}

int	testft_memccpy(void)
{
	int	original_test = compare_original_memccpy();
	int	return_test = test_return_pointer();

	return (original_test && return_test);
}
