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
int testft_itoa(void);
int testft_strmapi(void);
int testft_putchar_fd(void);

static int test_part1()
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
	return (failed);
}

static int test_part2()
{
	int	failed = 0;
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
	printf(BOLD YELLOW "Testing ft_itoa():" RESET "\n");
	if (!testft_itoa())
		failed = 1;
	printf(BOLD YELLOW "Testing ft_strmapi():" RESET "\n");
	if (!testft_strmapi())
		failed = 1;
	printf(BOLD YELLOW "Testing ft_putchar_fd():" RESET "\n");
	if (!testft_putchar_fd())
		failed = 1;
	return (failed);
}

static int test_bonus()
{
	return (1);
}

static int test_all()
{
	int test1 = test_part1();
	int test2 = test_part2();
	int test3 = test_bonus();

	return (test1 && test2 && test3);
}

int	main(int argc, char *argv[])
{
	if (argc == 1)
		return (test_all());
	if (argc == 2)
	{
		char *option = argv[1];
		if (strcmp("all", option) == 0)
			return test_all();
		else if (strcmp("part1", option) == 0)
			return (test_part1());
		else if (strcmp("part2", option) == 0)
			return (test_part2());
		else if (strcmp("bonus", option) == 0)
			return (test_bonus());
	}
	printf(
			"Usage: ./%s [SET]; where [SET] is optional and can"
			"either be \"all\", \"part1\", \"part2\" or \"bonus\"",
			argv[0]);

}
