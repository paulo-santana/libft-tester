#include "../libtest.h"

void	explain_expected_diff(char expected[40], char result[40])
{
	int is_red_already = 0;

	printf("        Expected: ");
	for (int i = 0; i < 40; i++)
		printf("%c", expected[i]);

	printf("\n        Got:      ");
	for (int i = 0; i < 40; i++)
	{
		if (expected[i] != result[i] && !is_red_already)
		{
			is_red_already = 1;
			printf(BOLD RED);
		}
		else if (expected[i] == result[i])
		{
			printf(RESET);
			is_red_already = 0;
		}
		printf("%c", result[i]);
	}
	printf(RESET "\n");
}

void	explain_expected_pointer(void *expected, void *result)
{
	printf("        Expected: ");
	printf("%p\n", expected);
	printf("        got:      ");
	printf(BOLD RED "%p" RESET "\n", result);
}

void	explain_expected_int(int expected, int result)
{
	printf("        Expected: ");
	printf("%i\n", expected);
	printf("        got:      ");
	printf(BOLD RED "%i" RESET "\n", result);
}
