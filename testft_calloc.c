#include "libtest.h"
#include "libft.h"

static int run_tests()
{
	int success = 1;
	int failed;
	int *arr;
	int *ft_arr;

	for (int i = 1; i < 189; i += 13)
	{
		failed = 0;
		arr = calloc(i, sizeof(int));
		if (!arr)
		{
			printf("system calloc(%d, 4) failed.\n", i);
			continue;
		}
		ft_arr = ft_calloc(i, sizeof(int));
		if (!ft_arr)
		{
			free(arr);
			printf("user ft_calloc(%d, 4) failed.\n", i);
			continue ;
		}
		for (int j = 0; j < i; j++)
			if (arr[j] != ft_arr[j])
				failed = 1;
		char *format = "Testing with %d";
		char *msg = malloc(sizeof(char) * (strlen(format) + 10));
		sprintf(msg, format, i);
		print_success(msg, success);
		free(msg);
		if (failed)
		{
			success = 0;
			explain_expected_diff((void *)arr, (void *)ft_arr, i * sizeof(int));
		}
		free(arr);
		free(ft_arr);
	}
	return (success);
}

int testft_calloc()
{
	int test1 = run_tests();

	return test1;
}
