#include "libtest.h"
#include "libft.h"

int compare_original_memmove(void)
{
	int success = 1;
	char dest[40];
	char *src = &dest[20];
	char ft_dest[40];
	char *ft_src = &ft_dest[20];
	size_t size = 7;
	
	for (int i = 0; i < 20; i++)
	{
		dest[i] = '-';
		src[i] = '8';
		ft_dest[i] = '-';
		ft_src[i] = '8';
	}

	memmove(dest + 3, src, size);
	ft_memmove(ft_dest + 3, ft_src, size);
	for (int i = 0; i < 40; i++)
		if (dest[i] != ft_dest[i])
			success = 0;

	if (!success)
		explain_expected_diff(dest, ft_dest);
	print_success("Test Original", success);
	return (success);
}

int test_dest_overlap_src()
{
	int success = 1;
	char dest[40];
	char *src = &dest[20];
	char ft_dest[40];
	char *ft_src = &ft_dest[20];
	size_t size = 7;
	
	for (int i = 0; i < 20; i++)
	{
		dest[i] = '-';
		src[i] = 'a' + i;
		ft_dest[i] = '-';
		ft_src[i] = 'a' + i;
	}

	memmove(dest + 17, src, size);
	ft_memmove(ft_dest + 17, ft_src, size);
	for (int i = 0; i < 40; i++)
		if (dest[i] != ft_dest[i])
			success = 0;

	print_success("Test dest overlaping src", success);
	if (!success)
		explain_expected_diff(dest, ft_dest);
	return (success);
}

int testft_memmove(void)
{
	int original_test = compare_original_memmove();
	int result_dest_overlap_src = test_dest_overlap_src();
	return (original_test && result_dest_overlap_src);
}
