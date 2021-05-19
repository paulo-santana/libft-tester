#include "libft.h"
#include <stdio.h>
#include <string.h>
#include "libtest.h"

int	compare_original_strlen(void)
{
	char	*str;
	int		len;
	int		original_len;
	int		success = 1;

	str = "string marota";
	len = ft_strlen(str);

	original_len = strlen(str);

	if (len != original_len)
		success = 0;

	printf("    Test Original: ");
	print_success(success);
	return (success);
}

static int	test_empty()
{
	char *empty = "";
	int success = 1;

	printf("    Test \"\": ");
	int result = ft_strlen(empty);
	if (result)
		success = 0;
	print_success(success);
	return (success);
}

int	testft_strlen(void)
{
	int	original_test	= compare_original_strlen();
	int	empty_test		= test_empty();
	return (original_test && empty_test);
}
