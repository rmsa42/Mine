/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_strat2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rumachad <rumachad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 15:36:22 by rumachad          #+#    #+#             */
/*   Updated: 2023/07/05 15:12:44 by rumachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

int	mv_calc1(int rotations_a, int rotations_b, int size_a, int size_b)
{
	int	nbr_m;

	nbr_m = 0;
	if ((size_a - rotations_a) < (size_b - rotations_b))
		nbr_m = size_b - rotations_b;
	else if ((size_b - rotations_b) < (size_a - rotations_a))
		nbr_m = size_a - rotations_a;
	else
		nbr_m = size_a - rotations_a;
	return (nbr_m);
}

int	mv_calc2(int rotations_a, int rotations_b)
{
	int	nbr_m;

	nbr_m = 0;
	if (rotations_a < rotations_b)
		nbr_m = rotations_b;
	else if (rotations_b < rotations_a)
		nbr_m = rotations_a;
	else
		nbr_m = rotations_a;
	return (nbr_m);
}

int	mv_calc3(int rotations_b, int size_b)
{
	int	nbr_m;

	nbr_m = 0;
	if (rotations_b > size_b / 2)
		nbr_m = (size_b - rotations_b);
	else
		nbr_m = rotations_b;
	return (nbr_m);
}

int	mv_calc4(int rotations_a, int size_a)
{
	int	nbr_m;

	nbr_m = 0;
	if (rotations_a > size_a / 2)
		nbr_m = (size_a - rotations_a);
	else
		nbr_m = rotations_a;
	return (nbr_m);
}

int	mv_calcs(int rotations_a, int rotations_b, int size_a, int size_b)
{
	int	nbr_m;

	nbr_m = 0;
	if (rotations_a > 0 && rotations_b > 0)
	{
		if ((rotations_a >= size_a / 2 && rotations_b >= size_b / 2)
			|| (rotations_a > size_a / 2 && size_b == 2))
			nbr_m = mv_calc1(rotations_a, rotations_b, size_a, size_b);
		else if (rotations_a == rotations_b)
			nbr_m = rotations_a;
		else if (rotations_a > size_a / 2 && rotations_b < size_b / 2)
			nbr_m = (size_a - rotations_a) + rotations_b;
		else if (rotations_b > size_b / 2 && rotations_a < size_a / 2)
			nbr_m = (size_b - rotations_b) + rotations_a ;
		else if (rotations_a <= size_a / 2 && rotations_b <= size_b / 2)
			nbr_m = mv_calc2(rotations_a, rotations_b);
	}
	else
	{
		if (rotations_a == 0)
			nbr_m = mv_calc3(rotations_b, size_b);
		else if (rotations_b == 0)
			nbr_m = mv_calc4(rotations_a, size_a);
	}
	return (++nbr_m);
}
