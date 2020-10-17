int	is_alpha(char c)
{
	if (c >= 'a' && c <= 'h')
		return (1);
	if (c >= 'A' && c <= 'H')
		return (2);
	return (0);
}

int	is_num(char c)
{
	if (c >= '1' && c <= '8')
		return (1);
	return (0);
}

int	ft_abs(int num)
{
	if (num < 0)
		return (-num);
	return (num);
}