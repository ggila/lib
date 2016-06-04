char	ft_islowercase(char c)
{
	return (c >= 'a' && c <= 'z');
}

char	ft_isuppercase(char c)
{
	return (c >= 'A' && c <= 'Z');
}

char	ft_isdigit(char c)
{
	return (c >= '0' && c <= '9');
}

char	ft_isletter(char c)
{
	return (ft_islowercase(c) || ft_isuppercase(c));
}

char	ft_isalnum(char c)
{
	return (ft_isletter(c) || ft_isdigit(c));
}
