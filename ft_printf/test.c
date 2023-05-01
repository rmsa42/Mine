/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rui <rui@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 14:50:43 by rumachad          #+#    #+#             */
/*   Updated: 2023/05/01 23:14:20 by rui              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	main(void)
{
	char	r = 'r';
 	char	*str = "Hello";
	int		n = 16;
	int		m = -1;
	
	
/* 	ft_printf("%i\n", ft_printf("%c\n", r));
	printf("%i\n", printf("%c\n", r));
	ft_printf("\n");
	ft_printf("%i\n", ft_printf("%s\n", str));
	printf("%i\n", printf("%s\n", str));
	ft_printf("\n");
	ft_printf("%i\n", ft_printf("%i\n", n));
	printf("%i\n", printf("%i\n", n));
	ft_printf("\n");
	ft_printf("%i\n", ft_printf("%d\n", n));
	printf("%i\n", printf("%d\n", n));
	ft_printf("\n");
	ft_printf("%i\n", ft_printf("%x\n", n));
	printf("%i\n", printf("%x\n", n));
	ft_printf("\n");
	ft_printf("%i\n", ft_printf("%X\n", n));
	printf("%i\n", printf("%X\n", n));
	ft_printf("\n");
	ft_printf("%i\n", ft_printf("%%\n"));
	printf("%i\n", printf("%%\n"));
	ft_printf("\n");
	ft_printf("%i\n", ft_printf("   "));
	printf("%i\n", printf("   "));
	ft_printf("\n");
	ft_printf("%i\n", ft_printf("%u\n", m));
	printf("%i\n", printf("%u\n", m));
	ft_printf("\n"); */
	ft_printf("%i\n", ft_printf("%p\n", str));
	printf("%i\n", printf("%p\n", str));
	/* ft_printf("%i\n", ft_printf("%u\n", m));
	printf("%i\n", printf("%u\n", m)); */
}