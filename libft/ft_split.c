/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rumachad <rumachad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 16:38:26 by rumachad          #+#    #+#             */
/*   Updated: 2023/04/20 13:03:03 by rumachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* #include "libft.h"

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

char	**ft_split(char const *s, char c)
{
	int				i;
	int				k;
	unsigned int	len;
	char			*str;
	char			**fstr;

	i = 0;
	k = 0;
	len = ft_strlen(s);
	while (s[i] != '\0')
	{
		if (s[i] == c)
			k++;
	}
	str = (char *)malloc((len - k + 1) * sizeof(char));
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
			str[i] = s[i];
		i++;
	}
	fstr = &str;
	return (fstr);
}

int main()
{
	char str[] = "Hello,Hey";
	char **a;

	a = ft_split(&str[0], ',');
	printf("%s\n", *a);
	free(a);
} */