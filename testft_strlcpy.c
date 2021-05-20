#include "libft.h"
#include "libtest.h"

static int test_with_size_zero()
{
	int success = 1;
	char dest[40];
	char src[] = "o rato roeu a roupa";
	char ft_dest[40];
	char ft_src[] = "o rato roeu a roupa";

	for (int i = 0; i < 40; i++)
	{
		dest[i] = '-';
		ft_dest[i] = '-';
	}

	int size = 0;

	strlcpy(dest + 11, src, size);
	ft_strlcpy(ft_dest + 11, ft_src, size);
	if (ft_memcmp(dest, ft_dest, 40) != 0)
		success = 0;
	print_success("Test with size 0", success);
	if (!success)
		explain_expected_diff(dest, ft_dest);
	return (success);
}

static int test_with_size_four()
{
	int success = 1;
	char dest[40];
	char src[] = "o rato roeu a roupa";
	char ft_dest[40];
	char ft_src[] = "o rato roeu a roupa";

	for (int i = 0; i < 40; i++)
	{
		dest[i] = '-';
		ft_dest[i] = '-';
	}

	int size = 4;

	strlcpy(dest + 11, src, size);
	ft_strlcpy(ft_dest + 11, ft_src, size);
	if (memcmp(dest, ft_dest, 40) != 0)
		success = 0;
	print_success("Test with size 4", success);
	if (!success)
		explain_expected_diff(dest, ft_dest);
	return (success);
}

static int test_with_string_smaller_than_size()
{
	int success = 1;
	char dest[40];
	char src[] = "o rato roeu a roupa";
	char ft_dest[40];
	char ft_src[] = "o rato roeu a roupa";

	for (int i = 0; i < 40; i++)
	{
		dest[i] = '-';
		ft_dest[i] = '-';
	}

	int size = 30;

	strlcpy(dest + 11, src, size);
	ft_strlcpy(ft_dest + 11, ft_src, size);
	if (ft_memcmp(dest, ft_dest, 40) != 0)
		success = 0;
	print_success("Test with string smaller than size", success);
	if (!success)
		explain_expected_diff(dest, ft_dest);
	return (success);
}

static int test_returned_size_with_size_zero()
{
	int success = 1;
	char dest[40];
	char src[] = "o rato roeu a roupa";
	char ft_dest[40];
	char ft_src[] = "o rato roeu a roupa";

	for (int i = 0; i < 40; i++)
	{
		dest[i] = '-';
		ft_dest[i] = '-';
	}

	int size = 0;
	int result;
	int ft_result;

	result = strlcpy(dest + 11, src, size);
	ft_result = ft_strlcpy(ft_dest + 11, ft_src, size);
	if (result != ft_result)
		success = 0;
	print_success("Test returned size with size 0", success);
	if (!success)
		explain_expected_int(result, ft_result);
	return (success);
}

static int test_returned_size_with_size_four()
{
	int success = 1;
	char dest[40];
	char src[] = "o rato roeu a roupa";
	char ft_dest[40];
	char ft_src[] = "o rato roeu a roupa";

	for (int i = 0; i < 40; i++)
	{
		dest[i] = '-';
		ft_dest[i] = '-';
	}

	int size = 4;
	int result;
	int ft_result;

	result = strlcpy(dest + 11, src, size);
	ft_result = ft_strlcpy(ft_dest + 11, ft_src, size);
	if (result != ft_result)
		success = 0;
	print_success("Test returned size with size 4", success);
	if (!success)
		explain_expected_int(result, ft_result);
	return (success);
}

static int test_returned_size_with_string_smaller_than_size()
{
	int success = 1;
	char dest[40];
	char src[] = "o rato roeu a roupa";
	char ft_dest[40];
	char ft_src[] = "o rato roeu a roupa";

	for (int i = 0; i < 40; i++)
	{
		dest[i] = '-';
		ft_dest[i] = '-';
	}

	int size = 30;
	int result;
	int ft_result;

	result = strlcpy(dest + 11, src, size);
	ft_result = ft_strlcpy(ft_dest + 11, ft_src, size);
	if (result != ft_result)
		success = 0;
	print_success("Test returned size with string smaller than size", success);
	if (!success)
		explain_expected_int(result, ft_result);
	return (success);
}

int testft_strlcpy()
{
	int test1 = test_with_size_zero();
	int test2 = test_with_size_four();
	int test3 = test_with_string_smaller_than_size();
	int test4 = test_returned_size_with_size_zero();
	int test5 = test_returned_size_with_size_four();
	int test6 = test_returned_size_with_string_smaller_than_size();

	return (test1 && test2 && test3 && test4 && test5 && test6);
}
