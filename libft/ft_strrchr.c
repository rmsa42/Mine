/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rumachad <rumachad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 14:43:32 by rumachad          #+#    #+#             */
/*   Updated: 2023/04/24 14:32:43 by rumachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* #include <stdio.h> */
#include "libft.h"

/* size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
} */

char	*ft_strrchr(const char *str, int c)
{
	int		i;
	char	character;
	char	*str2;

	i = ft_strlen(str);
	str2 = (char *)str;
	character = (char)c;
	while (i >= 0)
	{
		if (str2[i] == character)
		{
			return (&str2[i]);
		}
		i--;
	}
	return (NULL);
}

/* int main()
{
	char str[] = "dabcefgt";
	int a = 'd';
	printf("%s\n", ft_strrchr(&str[0], a));
} */