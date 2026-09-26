#include "ft_printf.h"

int	ft_putunbr(unsigned int nb)
{
	unsigned long	n;
	unsigned long	divisor;
	int				count;

	n = nb;
	count = 0;
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
