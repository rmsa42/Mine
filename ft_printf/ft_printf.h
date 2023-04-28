/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rumachad <rumachad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 13:17:58 by rumachad          #+#    #+#             */
/*   Updated: 2023/04/28 16:34:47 by rumachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

int		ft_prinft(const char *format, ...);
void	ft_putstr(char *s);
void	ft_putchar(char c);
void	ft_printhexa(int nbr);
void	ft_putnbr(int n);
char	*ft_itoa(int n);

#endif