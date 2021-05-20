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

int	main(void)
{
	int	success = 0;
	printf(BOLD YELLOW "Testing ft_strlen():" RESET "\n");
	if (!testft_strlen())
		success = 1;
	printf(BOLD YELLOW "Testing ft_memset():" RESET "\n");
	if (!testft_memset())
		success = 1;
	printf(BOLD YELLOW "Testing ft_bzero():" RESET "\n");
	if (!testft_bzero())
		success = 1;
	printf(BOLD YELLOW "Testing ft_memcpy():" RESET "\n");
	if (!testft_memcpy())
		success = 1;
	printf(BOLD YELLOW "Testing ft_memccpy():" RESET "\n");
	if (!testft_memccpy())
		success = 1;
	printf(BOLD YELLOW "Testing ft_memmove():" RESET "\n");
	if (!testft_memmove())
		success = 1;
	printf(BOLD YELLOW "Testing ft_memchr():" RESET "\n");
	if (!testft_memchr())
		success = 1;
	printf(BOLD YELLOW "Testing ft_memcmp():" RESET "\n");
	if (!testft_memcmp())
		success = 1;
	printf(BOLD YELLOW "Testing ft_strlcpy():" RESET "\n");
	if (!testft_strlcpy())
		success = 1;
	return (success);
}
