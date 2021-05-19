#include "libft.h"
#include "libtest.h"

void	explain_failure(char dest[42], char ft_dest[42])
{
	printf("        Expected: [");
	for (int i = 0; i < 42; i++)
		printf("%c", dest[i]);
	printf("]\n        Got:    : [");
	for (int i = 0; i < 42; i++)
		printf("%c", ft_dest[i]);
	printf("]\n");
}

int	compare_original_memcpy()
{
	int	success = 1;
	char dest[42];
	char src[42];
	char ft_dest[42];
	char ft_src[42];
	int size = 10;

	for (int i = 0; i < 42; i++)
	{
		src[i]		= 'a';
		dest[i]		= '-';
		ft_src[i]	= 'a';
		ft_dest[i]	= '-';
	}

	memcpy(&dest[9], src, size);
	ft_memcpy(&ft_dest[9], ft_src, size);

	for (int i = 0; i < 42; i++)
		if (dest[i] != ft_dest[i])
			success = 0;

	printf("    Test Original: ");
	print_success(success);
	if (!success)
		explain_failure(dest, ft_dest);
	return (success);
}

int	testft_memcpy(void)
{
	int	original_test = compare_original_memcpy();

	return (original_test);
}
