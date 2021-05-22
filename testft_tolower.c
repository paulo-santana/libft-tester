#include "libtest.h"
#include "libft.h"

static int test_everything()
{
	int success = 1;
	char buffer[128];
	char ft_buffer[128];

	for (int i = 1; i < 128; i++)
	{
		buffer[i - 1] = tolower(i);
		ft_buffer[i - 1] = ft_tolower(i);
	}

	buffer[127] = '\0';
	ft_buffer[127] = '\0';
	for (int i = 0; i < 128; i++)
		if (buffer[i] != ft_buffer[i])
			success = 0;

	print_success("Test characters from 0 to 127", success);
	if (!success)
		explain_expected_diff(buffer, ft_buffer, 127);
	return (success);
}


int testft_tolower()
{
	int test1 = test_everything();

	return (test1);
}
