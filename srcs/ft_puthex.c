#include "ft_printf.h"

int	ft_puthex(unsigned int nb, char format)
{
	char	bucket[16];
	int		i;
	int		count;
	char	*base;

	if (nb == 0)
		return (ft_putchar('0'));
	if (format == 'x')
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	i = 0;
	while (nb > 0)
	{
		bucket[i++] = base[nb % 16];
		nb /= 16;
	}
	count = 0;
	while (i > 0)
		count += ft_putchar(bucket[--i]);
	return (count);
}
