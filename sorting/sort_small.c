/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_small.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: gpirro <gpirro@student.42.fr>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/22 10:08:05 by gianlucapir   #+#    #+#                 */
/*   Updated: 2022/03/22 15:45:39 by gpirro        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_stack *a)
{
	if (!check_sorted(a->stack, a->top))
		swap(a, SA);
}

void	sort_three(t_stack *a)
{
	const int	v1 = a->stack[a->top - 1];
	const int	v2 = a->stack[a->top - 2];
	const int	v3 = a->stack[a->top - 3];

	if (!check_sorted(a->stack, a->top))
	{
		if (v1 < v3 && v3 < v2)
		{
			r_rotate(a, RRA);
			swap(a, SA);
		}
		else if (v2 < v1 && v1 < v3)
			swap(a, SA);
		else if (v3 < v1 && v1 < v2)
			r_rotate(a, RRA);
		else if (v2 < v3 && v3 < v1)
			rotate(a, RA);
		else
		{
			swap(a, SA);
			r_rotate(a, RRA);
		}
	}
}

static int	find_lowest(t_stack *a, int *ind)
{
	int	lowest;
	int	i;

	i = a->top - 1;
	lowest = a->stack[0];
	while (i > 0)
	{
		if (lowest > a->stack[i])
		{
			lowest = a->stack[i];
			(*ind) = i;
		}
		i--;
	}
	return (lowest);
}

void	sort_four(t_stack *a, t_stack *b)
{
	int	lowest;
	int	i;

	i = 0;
	lowest = find_lowest(a, &i);
	while (lowest != a->stack[a->top - 1])
	{
		if (i < 2)
			r_rotate(a, RRA);
		else
			rotate(a, RA);
	}
	if (!check_sorted(a->stack, a->top - 1))
	{
		push(a, b, PB);
		sort_three(a);
		push(b, a, PA);
	}
}

void	sort_five(t_stack *a, t_stack *b)
{
	int	lowest;
	int	i;

	lowest = find_lowest(a, &i);
	while (a->stack[a->top - 1] != lowest)
	{
		if (i > 2)
			r_rotate(a, RRA);
		else
			rotate(a, RA);
	}
	if (!check_sorted(a->stack, a->top))
	{
		push(a, b, PB);
		sort_four(a, b);
		push(b, a, PA);
	}
}
