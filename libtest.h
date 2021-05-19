#ifndef LIBTEST_H
# define LIBTEST_H
# include <stdio.h>
# include <string.h>
# include <strings.h>

# define BOLD		"\x1b[1m"
# define RED		"\x1b[31m"
# define GREEN 		"\x1b[32m"
# define YELLOW		"\x1b[33m"
# define BLUE		"\x1b[34m"
# define MAGENTA	"\x1b[35m"
# define CYAN		"\x1b[36m"
# define RESET		"\x1b[0m"

void	print_success(char *msg, int success);
void	explain_expected_diff(char expected[40], char result[40]);

#endif
