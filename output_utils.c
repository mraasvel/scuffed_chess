#include <unistd.h>

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i] != 0)
		i++;
	return (i);
}

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i] != 0)
	{
		write(1, &str[i], 1);
		i++;
	}
}

void	ft_putint_recurse(int n)
{
	char c;

	if (n == 0)
		return ;
	c = n % 10 + '0';
	ft_putint_recurse(n / 10);
	write(1, &c, 1);
}

void	ft_putint(int n)
{
	if (n == 0)
		write(1, "0", 1);
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (n < 0 )
		n = -n;
	ft_putint_recurse(n);
}

