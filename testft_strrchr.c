#include "libft.h"
#include "libtest.h"

static int test_normal_conditions(void)
{
	int success = 1;
	char *str = "o duq.ue de ca.chi.as.   .    ";
	char c = '.';

	char *pos = strrchr(str, c);
	char *ft_pos = ft_strrchr(str, c);

	if (pos != ft_pos)
		success = 0;
	print_success("Test normal", success);
	if (!success)
		explain_expected_pointer(pos, ft_pos);
	return (success);
}

static int test_searching_the_nul()
{
	int success = 1;
	char *str = "o duq.ue de ca.chi.as.   .    ";
	char c = '\0';

	char *pos = strrchr(str, c);
	char *ft_pos = ft_strrchr(str, c);

	if (pos != ft_pos)
		success = 0;
	print_success("Test searching the '\\0' character", success);
	if (!success)
		explain_expected_pointer(pos, ft_pos);
	return (success);
}

static int test_non_existing(void)
{
	int success = 1;
	char *str = "o duq.ue de ca.chi.as.   .    ";
	char c = '\\';

	char *pos = strrchr(str, c);
	char *ft_pos = ft_strrchr(str, c);

	if (pos != ft_pos)
		success = 0;
	print_success("Test searching a non existing character", success);
	if (!success)
		explain_expected_pointer(pos, ft_pos);
	return (success);
}

static int test_only_one_match(void)
{
	int success = 1;
	char *str = "o duq.ue de ca.chi.as.   .    ";
	char c = 'q';

	char *pos = strrchr(str, c);
	char *ft_pos = ft_strrchr(str, c);

	if (pos != ft_pos)
		success = 0;
	print_success("Test with only one valid match", success);
	if (!success)
		explain_expected_pointer(pos, ft_pos);
	return (success);
}

static int test_a_match_in_the_beginning(void)
{
	int success = 1;
	char *str = "1o duq.ue de ca.chi.as.   .    ";
	char c = '1';

	char *pos = strrchr(str, c);
	char *ft_pos = ft_strrchr(str, c);

	if (pos != ft_pos)
		success = 0;
	print_success("Test a char that matches in the beginning", success);
	if (!success)
		explain_expected_pointer(pos, ft_pos);
	return (success);
}

static int test_if_dude_is_trying_to_compare_the_begining_with_chars(void)
{
	int success = 1;
	char *str = "1 qqq \\ dahora 1o duq.ue de ca.chi.as.   .    ";
	char c = '\\';

	char *pos = strrchr(str, c);
	char *ft_pos = ft_strrchr(str, c);

	if (pos != ft_pos)
		success = 0;
	print_success("Check if dude is trying to stop looping by comparing the first char of the string", success);
	if (!success)
		explain_expected_pointer(pos, ft_pos);
	return (success);
}

int testft_strrchr(void)
{
	int test1 = test_normal_conditions();
	int test2 = test_searching_the_nul();
	int test3 = test_non_existing();
	int test4 = test_only_one_match();
	int test5 = test_a_match_in_the_beginning();
	int test6 = test_if_dude_is_trying_to_compare_the_begining_with_chars();

	return (test1 && test2 && test3 && test4 && test5 && test6);
}
