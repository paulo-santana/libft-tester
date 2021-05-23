#include <stdio.h>
#include "libft.h"
#include "libtest.h"

int	testft_strlen(void);
int	testft_memset(void);
int	testft_bzero(void);
int	testft_memcpy(void);
int	testft_memccpy(void);
int testft_memmove(void);
int testft_memchr(void);
int testft_memcmp(void);
int testft_strlcpy(void);
int testft_strlcat(void);
int testft_strchr(void);
int testft_strrchr(void);
int testft_strnstr(void);
int testft_strncmp(void);
int testft_atoi(void);
int testft_isspace(void);
int testft_isalpha(void);
int testft_isdigit(void);
int testft_isascii(void);
int testft_isprint(void);
int testft_toupper(void);
int testft_tolower(void);
int testft_calloc(void);
int testft_strdup(void);

int testft_substr(void);
int testft_strjoin(void);
int testft_strtrim(void);
int testft_split(void);

int	main(void)
{
	int	failed = 0;
	printf("\n=============== " BOLD MAGENTA "Part 1:\n\n");
	printf(BOLD YELLOW "Testing ft_strlen():" RESET "\n");
	if (!testft_strlen())
		failed = 1;
	printf(BOLD YELLOW "Testing ft_memset():" RESET "\n");
	if (!testft_memset())
		failed = 1;
	printf(BOLD YELLOW "Testing ft_bzero():" RESET "\n");
	if (!testft_bzero())
		failed = 1;
	printf(BOLD YELLOW "Testing ft_memcpy():" RESET "\n");
	if (!testft_memcpy())
		failed = 1;
	printf(BOLD YELLOW "Testing ft_memccpy():" RESET "\n");
	if (!testft_memccpy())
		failed = 1;
	printf(BOLD YELLOW "Testing ft_memmove():" RESET "\n");
	if (!testft_memmove())
		failed = 1;
	printf(BOLD YELLOW "Testing ft_memchr():" RESET "\n");
	if (!testft_memchr())
		failed = 1;
	printf(BOLD YELLOW "Testing ft_memcmp():" RESET "\n");
	if (!testft_memcmp())
		failed = 1;
	printf(BOLD YELLOW "Testing ft_strlcpy():" RESET "\n");
	if (!testft_strlcpy())
		failed = 1;
	printf(BOLD YELLOW "Testing ft_strlcat():" RESET "\n");
	if (!testft_strlcat())
		failed = 1;
	printf(BOLD YELLOW "Testing ft_strchr():" RESET "\n");
	if (!testft_strchr())
		failed = 1;
	printf(BOLD YELLOW "Testing ft_strrchr():" RESET "\n");
	if (!testft_strrchr())
		failed = 1;
	printf(BOLD YELLOW "Testing ft_strnstr():" RESET "\n");
	if (!testft_strnstr())
		failed = 1;
	printf(BOLD YELLOW "Testing ft_strncmp():" RESET "\n");
	if (!testft_strncmp())
		failed = 1;
	printf(BOLD YELLOW "Testing ft_atoi():" RESET "\n");
	if (!testft_atoi())
		failed = 1;
	printf(BOLD YELLOW "Testing ft_isspace():" RESET "\n");
	if (!testft_isspace())
		failed = 1;
	printf(BOLD YELLOW "Testing ft_isalpha():" RESET "\n");
	if (!testft_isalpha())
		failed = 1;
	printf(BOLD YELLOW "Testing ft_isdigit():" RESET "\n");
	if (!testft_isdigit())
		failed = 1;
	printf(BOLD YELLOW "Testing ft_isascii():" RESET "\n");
	if (!testft_isascii())
		failed = 1;
	printf(BOLD YELLOW "Testing ft_isprint():" RESET "\n");
	if (!testft_isprint())
		failed = 1;
	printf(BOLD YELLOW "Testing ft_toupper():" RESET "\n");
	if (!testft_toupper())
		failed = 1;
	printf(BOLD YELLOW "Testing ft_tolower():" RESET "\n");
	if (!testft_tolower())
		failed = 1;
	printf(BOLD YELLOW "Testing ft_calloc():" RESET "\n");
	if (!testft_calloc())
		failed = 1;
	printf(BOLD YELLOW "Testing ft_strdup():" RESET "\n");
	if (!testft_strdup())
		failed = 1;

	printf("\n=============== " BOLD MAGENTA "Part 2:\n\n");

	printf(BOLD YELLOW "Testing ft_substr():" RESET "\n");
	if (!testft_substr())
		failed = 1;
	printf(BOLD YELLOW "Testing ft_strjoin():" RESET "\n");
	if (!testft_strjoin())
		failed = 1;
	printf(BOLD YELLOW "Testing ft_strtrim():" RESET "\n");
	if (!testft_strtrim())
		failed = 1;
	printf(BOLD YELLOW "Testing ft_split():" RESET "\n");
	if (!testft_split())
		failed = 1;

	return (failed);
}
