#include "libtest.h"
#include "libft.h"

static int	test_all(void)
{
	int i = 0;
	int success;
	int failed = 0;
	int result;
	int ft_result;
	char test_str[32] = "Test ";

	char *test_subjects[] = {"0", "-0", "1", "-1", "--42", "-42", "42", "1234",
							"abcd", "00123", "  - 2", "     20", "    -3",
							"123d", "\t9", "\n10", "\v11", "\f12", "\r13",
							"abc32", "32 abd", "-0000000003", "  b  -32",
							"    +32", "+33", "-+ 34", "-2147483647", "++21",
							"+-48", "-211+3", "-19281938213787", "-2147483649",
							"-2147483648",  "2147483648",  "99999999999999999999999999",
							NULL};
	while (test_subjects[i])
	{
		success = 1;
		result = atoi(test_subjects[i]);
		ft_result = ft_atoi(test_subjects[i]);
		if (result != ft_result)
			success = 0;
		test_str[5] = '\0';
		print_success(strcat(test_str, test_subjects[i]), success);
		if (!success)
		{
			explain_expected_int(result, ft_result);
			failed = 1;
		}
		i++;
	}
	return (!failed);
}


int testft_atoi()
{
	int test1 = test_all();

	return (test1);
}
