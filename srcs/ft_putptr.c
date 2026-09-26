#include "ft_printf.h"

int	ft_putptr(unsigned long ptr)
{
	char	bucket[16];
	int		i;
	int		count;

	if (!ptr)
		return (ft_putstr("(nil)"));
	count = ft_putstr("0x");
	i = 0;
	while (ptr > 0)
	{
		bucket[i++] = "0123456789abcdef"[ptr % 16];
		ptr /= 16;
	}
	while (i > 0)
		count += ft_putchar(bucket[--i]);
	return (count);
}
