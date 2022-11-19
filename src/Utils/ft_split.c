#include<stdlib.h>

char	**ft_bigfree(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (NULL);
}

static int	ft_len_w(char *str, char charset)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != charset)
		i++;
	return (i);
}

static int	ft_nbr_w(char *str, char charset)
{
	int	count;
	int	i;

	count = 0;
	while (*str)
	{
		while (*str && *str == charset)
			str++;
		i = ft_len_w(str, charset);
		str += i;
		if (i)
			count++;
	}
	return (count);
}

static char	*ft_copy(char *src, int n)
{
	char	*res;

	res = malloc((n + 1) * sizeof(char));
	if (!res)
		return (NULL);
	res[n] = '\0';
	while (n--)
		res[n] = src[n];
	return (res);
}

char	**ft_split(char *str, char charset)
{
	int		size;
	int		i;
	int		n;
	char	**tab;

	if (!str)
		return (NULL);
	size = ft_nbr_w(str, charset);
	tab = malloc(sizeof(char *) * (size + 1));
	if (!tab)
		return (NULL);
	i = -1;
	while (++i < size)
	{
		while (*str && *str == charset)
			str++;
		n = ft_len_w(str, charset);
		tab[i] = ft_copy(str, n);
		if (!tab[i])
			return (ft_bigfree(tab));
		str += n;
	}
	tab[size] = 0;
	return (tab);
}