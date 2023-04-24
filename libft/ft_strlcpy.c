/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rumachad <rumachad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 11:05:38 by rumachad          #+#    #+#             */
/*   Updated: 2023/04/20 13:03:30 by rumachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* #include <stdio.h> */
#include "libft.h"

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

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	unsigned int	i;
	int				lensrc;

	i = 0;
	lensrc = ft_strlen(src);
	if (size == 0)
		return (lensrc);
	while ((i < size - 1) && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (lensrc);
}

/* int main()
{
	char src[] = "Hello5";
	char dest[] = "Hey";

	printf("%ld\n", ft_strlcpy(&dest[0], &src[0], 0));
} */