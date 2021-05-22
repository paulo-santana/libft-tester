#include "libtest.h"
#include "libft.h"

static int test_everything()
{
	int success = 1;

	for (int i = -450; i <= 450; i++)
	{
		int result = isalpha(i) != 0;
		int ft_result = ft_isalpha(i) != 0;
		if (result != ft_result)
		{
			printf("%d != %d\n", result, ft_result);
			if (result)
				printf("c[%d] is alpha\n", i);
			else
				printf("c[%d] is not alpha\n", i);
			success = 0;
		}
	}

	print_success("Test characters from 0 to 127", success);
	return (success);
}


int testft_isalpha()
{
	int test1 = test_everything();

	return (test1);
}
