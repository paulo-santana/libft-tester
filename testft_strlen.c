#include "libft.h"
#include <stdio.h>
#include "libtest.h"

void	explain_expected(int expected, int result)
{
	printf("        Expected: %d\n", expected);
	printf("        Got:      " BOLD RED "%d" RESET "\n", result);
}

int	compare_original_strlen(void)
{
	char	*str;
	int		ft_len;
	int		original_len;
	int		success = 1;

	str = "string marota";
	ft_len = ft_strlen(str);

	original_len = strlen(str);

	if (ft_len != original_len)
		success = 0;

	print_success("Test Original", success);
	if (!success)
		explain_expected(original_len, ft_len);
	return (success);
}

static int	test_empty()
{
	char *empty = "";
	int success = 1;

	int result = ft_strlen(empty);
	if (result)
		success = 0;
	print_success("Test \"\"", success);
	if (!success)
		explain_expected(0, result);
	return (success);
}

int	testft_strlen(void)
{
	int	original_test	= compare_original_strlen();
	int	empty_test		= test_empty();
	return (original_test && empty_test);
}
