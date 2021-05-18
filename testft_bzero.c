#include "libft.h"
#include "libtest.h"
#include <strings.h>

int compare_original_bzero()
{
	int		success = 1;
	char	memory[40];
	char	ft_memory[40];

	for (int i = 0; i < 40; i++)
		memory[i] = '7';
	for (int i = 0; i < 40; i++)
		ft_memory[i] = '7';

	bzero(      &memory[9], 10);
	ft_bzero(&ft_memory[9], 10);

	for (int i = 0; i < 40; i++)
		if (ft_memory[i] != memory[i])
			success = (0);

	printf("    Test Original: ");
	print_success(success);
	return (success);
}

int	testft_bzero(void)
{
	int	original_test = compare_original_bzero();


	return (original_test);
}
