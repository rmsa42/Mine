/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhexa_upp.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rui <rui@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 20:36:57 by rui               #+#    #+#             */
/*   Updated: 2023/04/28 20:37:10 by rui              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printhexa_upp(int nbr)
{
	char	*hexa;

	hexa = "0123456789ABCDEF";
	if (nbr < 16)
		ft_putchar(*(hexa + nbr));
	else
	{
		ft_printhexa_upp(nbr / 16);
		ft_printhexa_upp(nbr % 16);
	}
}
