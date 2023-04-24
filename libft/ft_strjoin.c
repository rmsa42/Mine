/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rumachad <rumachad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 17:18:45 by rumachad          #+#    #+#             */
/*   Updated: 2023/04/20 13:04:35 by rumachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
/* #include <stdio.h> */
#include "libft.h"

char	*ft_strncat(char *dest, const char *src, size_t n)
{
	unsigned int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[n + i] = src[i];
		i++;
	}
	dest[n + i] = '\0';
	return (dest);
}

char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	unsigned int	i;

	i = 0;
	while (i < n)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

/* size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
} */

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*join;
	char	lens1;
	char	lens2;

	lens1 = ft_strlen(s1);
	lens2 = ft_strlen(s2);
	join = (char *)malloc((lens1 + lens2 + 1) * sizeof(char));
	if (join == NULL)
		return (NULL);
	ft_strncpy(join, s1, lens1);
	ft_strncat(join, s2, lens1);
	return (join);
}

/* int main()
{
	char s1[] = "";
	char s2[] = "a";
	char *a;

	a = ft_strjoin(&s1[0], &s2[0]);
	printf("%s\n", a);
	free(a);
} */