/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rumachad <rumachad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 11:42:59 by rumachad          #+#    #+#             */
/*   Updated: 2023/04/20 14:07:40 by rumachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	unsigned int	i;
	unsigned int	lendest;
	unsigned int	lendsrc;

	i = 0;
	lendest = ft_strlen(dest);
	lendsrc = ft_strlen(src);
	if (size == 0 || size <= lendest)
	{
		lendest = size;
		return (lendsrc + lendest);
	}
	while ((i < size - lendest - 1) && src[i] != '\0')
	{
		dest[lendest + i] = src[i];
		i++;
	}
	dest[lendest + i] = '\0';
	return (lendsrc + lendest);
}

/* int main()
{
	char src[] = "lorem ipsum dolor sit amet";
	char dst[15] = "rrrrrrrrrrrrrrr";

	printf("%ld\n", ft_strlcat(&dst[0], &src[0], 5));
} */