/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   radix.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: gpirro <gpirro@student.42.fr>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/22 13:23:23 by gpirro        #+#    #+#                 */
/*   Updated: 2022/03/25 10:40:17 by gpirro        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_empty(t_stack *s)
{
	if (s->top == 0)
		return (1);
	return (0);
}

void	radix_sort(t_stack *a, t_stack *b)
{
	int	i;
	int	j;
	int	len;

	j = 0;
	len = a->top;
	while (!check_sorted(a->stack, a->top))
	{
		i = 0;
		while (i < len)
		{
			if ((a->stack[a->top - 1] >> j) % 2 == 0)
				push(a, b, PB);
			else
				rotate(a, RA);
			i++;
		}
		i = 0;
		while (b->top > 0)
			push(b, a, PA);
		j++;
	}
}
