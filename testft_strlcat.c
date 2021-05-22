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
	dest[15] = '\0';
	ft_dest[15] = '\0';

	strlcat(dest + 11, src, size);
	ft_strlcat(ft_dest + 11, ft_src, size);
	if (ft_memcmp(dest, ft_dest, 40) != 0)
		success = 0;
	print_success("Test with size 0", success);
	if (!success)
		explain_expected_diff(dest, ft_dest, 40);
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
	dest[15] = '\0';
	ft_dest[15] = '\0';

	strlcat(dest + 11, src, size);
	ft_strlcat(ft_dest + 11, ft_src, size);
	if (memcmp(dest, ft_dest, 40) != 0)
		success = 0;
	print_success("Test with size 4", success);
	if (!success)
		explain_expected_diff(dest, ft_dest, 40);
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
	dest[15] = '\0';
	ft_dest[15] = '\0';

	strlcat(dest + 11, src, size);
	ft_strlcat(ft_dest + 11, ft_src, size);
	if (ft_memcmp(dest, ft_dest, 40) != 0)
		success = 0;
	print_success("Test with string smaller than size", success);
	if (!success)
		explain_expected_diff(dest, ft_dest, 40);
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
	dest[15] = '\0';
	ft_dest[15] = '\0';
	int result;
	int ft_result;

	result = strlcat(dest + 11, src, size);
	ft_result = ft_strlcat(ft_dest + 11, ft_src, size);
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
	dest[15] = '\0';
	ft_dest[15] = '\0';
	int result;
	int ft_result;

	result = strlcat(dest + 11, src, size);
	ft_result = ft_strlcat(ft_dest + 11, ft_src, size);
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
	dest[15] = '\0';
	ft_dest[15] = '\0';
	int result;
	int ft_result;

	result = strlcat(dest + 11, src, size);
	ft_result = ft_strlcat(ft_dest + 11, ft_src, size);
	if (result != ft_result)
		success = 0;
	print_success("Test returned size with string smaller than size", success);
	if (!success)
		explain_expected_int(result, ft_result);
	return (success);
}

static int test_with_clean_dest()
{
	int success = 1;
	char dest[40];
	char src[] = "o rato roeu a roupa";
	char ft_dest[40];
	char ft_src[] = "o rato roeu a roupa";

	for (int i = 0; i < 40; i++)
	{
		dest[i] = '\0';
		ft_dest[i] = '\0';
	}

	int size = 20;
	dest[15] = '\0';
	ft_dest[15] = '\0';

	strlcat(dest, src, size);
	ft_strlcat(ft_dest, ft_src, size);
	if (ft_memcmp(dest, ft_dest, 40) != 0)
		success = 0;
	print_success("Test with dest filled with \\0s", success);
	if (!success)
		explain_expected_diff(dest, ft_dest, 40);
	return (success);
}

static int test_with_empty_src()
{
	int success = 1;
	char dest[40];
	char src[] = "";
	char ft_dest[40];
	char ft_src[] = "";

	for (int i = 0; i < 40; i++)
	{
		dest[i] = '-';
		ft_dest[i] = '-';
	}

	int size = 20;
	dest[15] = '\0';
	ft_dest[15] = '\0';

	strlcat(dest + 11, src, size);
	ft_strlcat(ft_dest + 11, ft_src, size);
	if (ft_memcmp(dest, ft_dest, 40) != 0)
		success = 0;
	print_success("Test with empty source", success);
	if (!success)
		explain_expected_diff(dest, ft_dest, 40);
	return (success);
}

static int test_returned_size_with_clean_dest()
{
	int success = 1;
	char dest[40];
	char src[] = "o rato roeu a roupa";
	char ft_dest[40];
	char ft_src[] = "o rato roeu a roupa";

	for (int i = 0; i < 40; i++)
	{
		dest[i] = '\0';
		ft_dest[i] = '\0';
	}

	int size = 20;
	dest[15] = '\0';
	ft_dest[15] = '\0';
	int result;
	int ft_result;

	result = strlcat(dest, src, size);
	ft_result = ft_strlcat(ft_dest, ft_src, size);
	if (result != ft_result)
		success = 0;
	print_success("Test returned size with dest filled with \\0s", success);
	if (!success)
		explain_expected_int(result, ft_result);
	return (success);
}

static int test_returned_size_with_empty_src()
{
	int success = 1;
	char dest[40];
	char src[] = "";
	char ft_dest[40];
	char ft_src[] = "";

	for (int i = 0; i < 40; i++)
	{
		dest[i] = '-';
		ft_dest[i] = '-';
	}

	int size = 20;
	dest[13] = '\0';
	ft_dest[13] = '\0';
	int result;
	int ft_result;

	result = strlcat(dest, src, size);
	ft_result = ft_strlcat(ft_dest, ft_src, size);
	if (result != ft_result)
		success = 0;
	print_success("Test returned size with empty source", success);
	if (!success)
		explain_expected_int(result, ft_result);
	return (success);
}

static int test_with_both_empty()
{
	int success = 1;
	char dest[40];
	char src[] = "";
	char ft_dest[40];
	char ft_src[] = "";

	for (int i = 0; i < 40; i++)
	{
		dest[i] = '\0';
		ft_dest[i] = '\0';
	}

	int size = 20;

	strlcat(dest, src, size);
	ft_strlcat(ft_dest, ft_src, size);
	if (memcmp(dest, ft_dest, 40))
		success = 0;
	print_success("Test with both strings empty", success);
	if (!success)
		explain_expected_diff(dest, ft_dest, 40);
	return (success);
}

static int test_returned_size_with_both_empty()
{
	int success = 1;
	char dest[40];
	char src[] = "";
	char ft_dest[40];
	char ft_src[] = "";

	for (int i = 0; i < 40; i++)
	{
		dest[i] = '\0';
		ft_dest[i] = '\0';
	}

	int size = 20;
	int result;
	int ft_result;

	result = strlcat(dest, src, size);
	ft_result = ft_strlcat(ft_dest, ft_src, size);
	if (result != ft_result)
		success = 0;
	print_success("Test returned size with both strings empty", success);
	if (!success)
		explain_expected_int(result, ft_result);
	return (success);
}

int testft_strlcat()
{
	int test1 = test_with_size_zero();
	int test2 = test_with_size_four();
	int test3 = test_with_string_smaller_than_size();
	int test4 = test_returned_size_with_size_zero();
	int test5 = test_returned_size_with_size_four();
	int test6 = test_returned_size_with_string_smaller_than_size();
	int test7 = test_with_clean_dest();
	int test8 = test_with_empty_src();
	int test9 = test_returned_size_with_clean_dest();
	int test10 = test_returned_size_with_empty_src();
	int test11 = test_with_both_empty();
	int test12 = test_returned_size_with_both_empty();

	return (test1 && test2 && test3 && test4 && test10 && test11 && test12
			&& test5 && test6 && test7 && test8 && test9);
}
