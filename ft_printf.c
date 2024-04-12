#include "minitalk.h"

void	ft_putchar(char c, int *result)
{
	write(1, &c, 1);
	*result += 1;
}

void	ft_putstr(char *s, int *result)
{
	int	i;

	i = 0;
	if (!s)
	{
		ft_putstr("(null)", result);
		result += 6;
		return ;
	}
	while (s[i])
	{
		ft_putchar(s[i], result);
		i++;
	}
}

void	ft_putnbr(int n, int *result)
{
	if (n == -2147483648)
	{
		ft_putstr("-2147483648", result);
		return ;
	}
	if (n < 0)
	{
		ft_putchar('-', result);
		n *= -1;
	}
	if (n >= 10)
	{
		ft_putnbr(n / 10, result);
		ft_putnbr(n % 10, result);
	}
	if (n < 10)
		ft_putchar(n + 48, result);
}

void	ft_checker(va_list *p, char c, int *result)
{
	if (c == 'c')
		ft_putchar(va_arg(*p, int), result);
	if (c == 's')
		ft_putstr(va_arg(*p, char *), result);
	if (c == 'd' || c == 'i')
		ft_putnbr(va_arg(*p, int), result);
}

int	ft_printf(const char *s, ...)
{
	int		result;
	int		i;
	va_list	p;

	i = 0;
	result = 0;
	va_start(p, s);
	while (s[i])
	{
		if (s[i] == '%' && s[i + 1])
			ft_checker(&p, s[++i], &result);
		else if (s[i] != '%')
			ft_putchar(s[i], &result);
		i++;
	}
	va_end(p);
	return (result);
}
