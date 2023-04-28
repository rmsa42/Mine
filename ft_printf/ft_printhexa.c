/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhexa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rumachad <rumachad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 12:29:03 by rumachad          #+#    #+#             */
/*   Updated: 2023/04/28 16:40:06 by rumachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printhexa(int nbr)
{
	char	*hexa;

	hexa = "0123456789abcdef";
	if (nbr < 16)
		ft_putchar(*(hexa + nbr));
	else
	{
		ft_printhexa(nbr / 16);
		ft_printhexa(nbr % 16);
	}
}
