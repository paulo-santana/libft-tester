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

int	main(void)
{
	int	success = 1;
	printf(BOLD YELLOW "Testing ft_strlen():" RESET "\n");
	if (!testft_strlen())
		success = 0;
	printf(BOLD YELLOW "Testing ft_memset():" RESET "\n");
	if (!testft_memset())
		success = 0;
	printf(BOLD YELLOW "Testing ft_bzero():" RESET "\n");
	if (!testft_bzero())
		success = 0;
	printf(BOLD YELLOW "Testing ft_memcpy():" RESET "\n");
	if (!testft_memcpy())
		success = 0;
	printf(BOLD YELLOW "Testing ft_memccpy():" RESET "\n");
	if (!testft_memccpy())
		success = 0;
	printf(BOLD YELLOW "Testing ft_memmove():" RESET "\n");
	if (!testft_memmove())
		success = 0;
	printf(BOLD YELLOW "Testing ft_memchr():" RESET "\n");
	if (!testft_memchr())
		success = 0;
	return (success);
}
