#include <string.h>
#include "libft.h"
#include "libtest.h"

int compare_original_memset(void)
{
	char	memory[40];
	char	ft_memory[40];
	int		success = 1;

	for (int i = 0; i < 40; i++)
		memory[i] = '5';
	for (int i = 0; i < 40; i++)
		ft_memory[i] = '5';

	ft_memset(ft_memory, '-', 10);

	memset(memory, '-', 10);
	for (int i = 0; i < 40; i++)
		if (ft_memory[i] != memory[i])
			success = 0;

	printf("    Test Original: ");
	print_success(success);
	return (success);
}

int	test_with_zero(void)
{
	int success = 1;
	char	ft_memory[40];

	for (int i = 0; i < 40; i++)
		ft_memory[i] = '5';

	ft_memset(ft_memory, '-', 0);
	for (int i = 0; i < 40; i++)
		if (ft_memory[i] != '5')
			success = 0;

	printf("    Test " BOLD BLUE "ft_memset(buffer, '-', 0)" RESET ": ");
	print_success(success);
	return (success);
}

int	test_return()
{
	int		success = 1;
	char	*result;
	char	ft_memory[40];

	result = ft_memset(ft_memory, '-', 20);
	if (result != ft_memory)
		success = 0;
	printf("    Test return value: ");
	print_success(success);
	return (success);
}

int	testft_memset(void)
{
	int original_test	= compare_original_memset();
	int test_zero		= test_with_zero();
	int return_pointer	= test_return();
	return (original_test && test_zero && return_pointer);
}
