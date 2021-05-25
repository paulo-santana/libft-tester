#include "libft.h"
#include "libtest.h"

static void run_tests()
{
	char *msg = "    Expected output: ";
	write(1, msg, strlen(msg));
	for (int i = 32; i < 128; i++)
		write(1, &i, 1);
	write(1, "\n", 1);
	msg = "    Result:          ";
	write(1, msg, strlen(msg));
	for (int i = 32; i < 128; i++)
		ft_putchar_fd(i, 1);
	write(1, "\n", 1);
}

void testft_putchar_fd()
{
	run_tests();
}

