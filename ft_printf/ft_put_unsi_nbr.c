/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_unsi_nbr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rumachad <rumachad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 13:16:06 by rumachad          #+#    #+#             */
/*   Updated: 2023/05/01 14:20:00 by rumachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	len(unsigned int num)
{
	int	i;

	i = 0;
	while (num != 0)
	{
		num = num / 10;
		i++;
	}
	return (i);
}

int	ft_put_unsi_nbr(unsigned int n)
{
	if (n < 10)
	{
		n = n + '0';
		ft_putchar(n);
	}
	else
	{
		ft_put_unsi_nbr(n / 10);
		ft_put_unsi_nbr(n % 10);
	}
	return (len(n));
}
