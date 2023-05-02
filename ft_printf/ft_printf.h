/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rumachad <rumachad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 13:17:58 by rumachad          #+#    #+#             */
/*   Updated: 2023/05/02 15:22:24 by rumachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

int		ft_printf(const char *format, ...);
int		ft_putstr(char *s);
int		ft_putchar(char c);
int		ft_printpointer(unsigned long nbr);
int		ft_printpointer_start(unsigned long nbr);
int		ft_printhexa(unsigned int nbr);
int		ft_printhexa_upp(unsigned int nbr);
int		ft_putnbr(int n);
int		ft_put_unsi_nbr(unsigned int n);
char	*ft_itoa(int n);

#endif