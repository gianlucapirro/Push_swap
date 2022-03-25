/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   actions.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: gpirro <gpirro@student.42.fr>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/21 14:41:33 by gpirro        #+#    #+#                 */
/*   Updated: 2022/03/22 13:21:29 by gpirro        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	swap(t_stack *s, int print)
{
	int	tmp;

	if (s->top > 0)
	{
		tmp = s->stack[s->top - 1];
		s->stack[s->top - 1] = s->stack[s->top - 2];
		s->stack[s->top - 2] = tmp;
		if (print == SA)
			ft_putstr_fd("sa\n", 1);
		else if (print == SB)
			ft_putstr_fd("sb\n", 1);
	}
	return (1);
}

int	r_rotate(t_stack *s, int print)
{
	int	tmp;
	int	i;

	if (s->top > 1)
	{
		i = 0;
		tmp = s->stack[0];
		while (i < s->top - 1)
		{
			s->stack[i] = s->stack[i + 1];
			i++;
		}
		s->stack[s->top - 1] = tmp;
		if (print == RRA)
			ft_putstr_fd("rra\n", 1);
		else if (print == RRB)
			ft_putstr_fd("rrb\n", 1);
		return (1);
	}
	return (0);
}

int	rotate(t_stack *s, int print)
{
	int	tmp;
	int	i;

	if (s->top > 1)
	{
		i = s->top - 1;
		tmp = s->stack[s->top - 1];
		while (i > 0)
		{
			s->stack[i] = s->stack[i - 1];
			i--;
		}
		s->stack[0] = tmp;
		if (print == RA)
			ft_putstr_fd("ra\n", 1);
		else if (print == RB)
			ft_putstr_fd("rb\n", 1);
		return (1);
	}
	return (0);
}

int	push(t_stack *from, t_stack *to, int print)
{
	if (from->top > 0)
	{
		to->top++;
		to->stack[to->top - 1] = from->stack[from->top - 1];
		from->top--;
		if (print == PA)
			ft_putstr_fd("pa\n", 1);
		else if (print == PB)
			ft_putstr_fd("pb\n", 1);
		return (1);
	}
	return (0);
}
