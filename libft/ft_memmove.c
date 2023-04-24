/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rumachad <rumachad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 12:22:56 by rumachad          #+#    #+#             */
/*   Updated: 2023/04/20 15:58:49 by rumachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	int				i;
	int				n1;

	n1 = (int)n;
	if (*(char *)(src) == '\0' || *(char *)(dest) == '\0')
		return (NULL);
	if (src < dest)
	{
		i = n1 - 1;
		while (i >= 0)
		{
			*(char *)(dest + i) = *(char *)(src + i);
			i--;
		}
	}
	else
	{
		i = 0;
		while (i < n1)
		{
			*(char *)(dest + i) = *(char *)(src + i);
			i++;
		}
	}
	return (dest);
}
