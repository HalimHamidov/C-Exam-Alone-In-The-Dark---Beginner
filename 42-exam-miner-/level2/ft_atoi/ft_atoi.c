int	ft_atoi(const char *str)
{
	int i = 0;
	int sign = 1;
	int nb = 0;

	while ((str[i] != 0) && (str[i] == '\t' || str[i] == '\n' || str[i] == '\v' || str[i] == '\f' || str[i] == '\r' || str[i] == ' '))
		i++;
	if ((str[i] != 0) && (str[i] == '-' || str[i] == '+'))
	{
		if (str[i++] == '-')
			sign = -1;
	}
	while ( str[i] != 0 && str[i] >= '0' && str[i] <= '9')
	{
		nb = nb * 10 + str[i] - '0';
		i++;
	}
	return (nb * sign);
}

int main (void)
{
	printf("The integer value from atoi function is %d\n", ft_atoi("123456789"));
	return (0);
}
