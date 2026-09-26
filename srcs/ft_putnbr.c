#include "ft_printf.h"

int	ft_putnbr(int nb)
{
	long	n;
	long	divisor;
	int		count;

	n = nb;
	count = 0;
	if (n < 0)
	{
		count += ft_putchar('-');
		n = -n;
	}
	divisor = 1;
	while (n / divisor >= 10)
		divisor *= 10;
	while (divisor >= 1)
	{
		count += ft_putchar((n / divisor) + '0');
		n = n % divisor;
		divisor /= 10;
	}
	return (count);
}
