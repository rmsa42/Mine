/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rumachad <rumachad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 17:18:45 by rumachad          #+#    #+#             */
/*   Updated: 2023/05/03 10:59:02 by rumachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const	*s1, char const	*s2)
{
	char	*str;
	size_t	slen1;
	size_t	slen2;

	slen1 = ft_strlen(s1);
	slen2 = ft_strlen(s2);
	if (!s1 || !s2)
		return (NULL);
	str = (char *)malloc(slen1 + slen2 + 1);
	if (!str)
		return (0);
	ft_strlcpy(str, s1, slen1 + 1);
	ft_strlcat(str + (slen1), s2, slen2 + 1);
	return (str);
}

/* int main()
{
	char s1[] = "h\0hh";
	char s2[] = "\n\0";
	char *a;

	a = ft_strjoin(&s1[0], &s2[0]);
	printf("%s\n", a);
	free(a);
} */