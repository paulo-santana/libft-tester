#ifndef LIBTEST_H
# define LIBTEST_H

# include <ctype.h>
#ifdef __linux__
# include <bsd/string.h>
# include <bsd/stdlib.h>
# include <stdio.h>
# endif
#ifdef __APPLE__
# include <string.h>
# include <stdlib.h>
# include <stdio.h>

#endif

# define BOLD		"\x1b[1m"
# define RED		"\x1b[31m"
# define GREEN 		"\x1b[32m"
# define YELLOW		"\x1b[33m"
# define BLUE		"\x1b[34m"
# define MAGENTA	"\x1b[35m"
# define CYAN		"\x1b[36m"
# define RESET		"\x1b[0m"

void	print_success(char *msg, int success);
void	warn_alloc_fail(char *failed_func);
void	explain_expected_diff(char expected[], char result[], unsigned int size);
void	explain_expected_pointer(void *expected, void *result);
void	explain_expected_int(int expected, int result);

#endif
