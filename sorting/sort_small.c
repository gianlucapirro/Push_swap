/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_small.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: gpirro <gpirro@student.42.fr>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/01 18:07:52 by gianlucapir   #+#    #+#                 */
/*   Updated: 2022/01/18 13:26:23 by gpirro        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	*sort_two(t_list *a)
{
	if (!check_sorted(a))
		swap_top(a, A);
	return (a);
}

void	*sort_three(t_list *a)
{
	const int	v1 = a->data;
	const int	v2 = a->next->data;
	const int	v3 = a->next->next->data;

	if (v1 < v2 && v2 < v3)
		return (a);
	else if (v1 < v3 && v3 < v2)
	{
		reverse_rotate(&a, A);
		swap_top(a, A);
	}
	else if (v2 < v1 && v1 < v3)
		swap_top(a, A);
	else if (v3 < v1 && v1 < v2)
		reverse_rotate(&a, A);
	else if (v2 < v3 && v3 < v1)
		rotate_top(a, A);
	else
	{
		swap_top(a, A);
		reverse_rotate(&a, A);
	}
	return (a);
}

t_list	*sort_four(t_list *a, t_list *b)
{
	int first_item;

	if (check_sorted(a))
		return (a);
	a = push_top(a, &b, B);
	first_item = b->data;
	a = sort_three(a);
	push_top(b, &a, A);
	while (!check_sorted(a))
	{
		if (first_item < a->next->next->data)
			swap_top(a, A);
		else if (first_item < a->next->next->next->data)
		{
			reverse_rotate(&a, A);
			swap_top(a, A);
			rotate_top(a, A);
			rotate_top(a, A);
		}
		else
			rotate_top(a, A);
	}
	return (a);
}

static int	find_lowest(t_list *stack, int *i)
{
	int	lowest;
	int	p;

	*i = 0;
	p = 0;
	lowest = stack->data;
	while (stack)
	{
		if (lowest > stack->data)
		{
			lowest = stack->data;
			(*i) = p;
		}
		stack = stack->next;
		p++;
	}
	return (lowest);
}

t_list	*sort_five(t_list *a, t_list *b)
{
	int	lowest;
	int	i;

	lowest = find_lowest(a, &i);
	if (check_sorted(a))
		return (a);
	while (a->data != lowest)
	{
		if (i > 2)
			reverse_rotate(&a, A);
		else
			rotate_top(a, A);
	}
	a = push_top(a, &b, B);
	a = sort_four(a, b);
	push_top(b, &a, A);
	return (a);
}
