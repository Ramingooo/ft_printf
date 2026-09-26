#include "ft_printf.h"

int	ft_putstr(char *str)
{
	int	i;
	int	count;

	if (!str)
		return (write(1, "(null)", 6));
	i = 0;
	count = 0;
	while (str[i])
	{
		count += ft_putchar(str[i]);
		i++;
	}
	return (count);
}
