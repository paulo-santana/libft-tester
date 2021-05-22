#include "libtest.h"
#include "libft.h"

static int test_everything()
{
	int success = 1;

	for (int i = -400; i <= 400; i++)
	{
		int result = isascii(i) != 0;
		int ft_result = ft_isascii(i) != 0;
		if (result != ft_result)
		{
			printf("%d != %d\n", result, ft_result);
			if (result)
				printf("c[%d] is ascii\n", i);
			else
				printf("c[%d] is not ascii\n", i);
			success = 0;
		}
	}

	print_success("Test characters from -400 to 400", success);
	return (success);
}


int testft_isascii()
{
	int test1 = test_everything();

	return (test1);
}
