/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rumachad <rumachad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 11:37:12 by rumachad          #+#    #+#             */
/*   Updated: 2023/04/28 16:44:47 by rumachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	formats(const char format, va_list args)
{
	if (format == 'c')
		ft_putchar(va_arg(args, int));
	if (format == 's')
		ft_putstr(va_arg(args, char *));
	if (format == 'd')
		ft_putnbr(va_arg(args, int));
	if (format == 'i')
		ft_putnbr(va_arg(args, int));
	if (format == 'x')
		ft_printhexa(va_arg(args, int));
}

int	ft_printf(const	char *format, ...)
{
	int		i;
	va_list	args;

	i = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			formats(format[i], args);
		}
		else
		{
			ft_putchar(format[i]);
		}
		i++;
	}
	va_end(args);
	return (1);
}

int	main(void)
{
	/* char	r = 'r'; */
	/* char	*str = "Hello"; */
	/* int		n = 111; */
	
	ft_printf("%x", n);
	printf("\n");
}
