#include "libtest.h"
#include "libft.h"

static int compare_original_memmove(void)
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
		explain_expected_diff(dest, ft_dest, 40);
	print_success("Test Original", success);
	return (success);
}

static int test_dest_overlap_src()
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
		explain_expected_diff(dest, ft_dest, 40);
	return (success);
}

static int test_src_overlap_dest()
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

	memmove(src, dest + 17, size);
	ft_memmove(ft_src, ft_dest + 17, size);
	for (int i = 0; i < 40; i++)
		if (dest[i] != ft_dest[i])
			success = 0;

	print_success("Test src overlaping dest", success);
	if (!success)
		explain_expected_diff(dest, ft_dest, 40);
	return (success);
}

static int	test_return_pointer_dest_over_src(void)
{
	int success = 1;
	char ft_dest[20] = "eurqwrioqripqyriq";
	void *result;

	result = ft_memmove(ft_dest, ft_dest + 4, 7);
	if (result != ft_dest)
		success = 0;
	print_success("Test returned pointer (dest overlaping src)", success);
	if (!success)
		explain_expected_pointer(ft_dest, result);
	return (success);
}

int test_return_pointer_src_over_dest()
{
	int success = 1;
	char ft_dest[20] = "192381932987";
	void *result;

	void *expected = ft_dest + 4;
	result = ft_memmove(expected, ft_dest, 7);
	if (result != expected)
		success = 0;
	print_success("Test returned pointer (src overlaping dest)", success);
	if (!success)
		explain_expected_pointer(ft_dest, result);
	return (success);
}

int testft_memmove(void)
{
	int original_test = compare_original_memmove();
	int result_dest_overlap_src = test_dest_overlap_src();
	int result_src_overlap_dest = test_src_overlap_dest();
	int returned_pointer_dest_overlap_src = test_return_pointer_dest_over_src();
	int returned_pointer_src_overlap_dest = test_return_pointer_src_over_dest();

	return (original_test && result_dest_overlap_src
			&& result_src_overlap_dest && returned_pointer_dest_overlap_src
			&& returned_pointer_src_overlap_dest);
}
