/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gianlucapirro <gianlucapirro@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 18:07:52 by gianlucapir       #+#    #+#             */
/*   Updated: 2021/12/07 21:33:43 by gianlucapir      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// static int	check_if_biggest(t_list *stack)
// {
// 	int	first;

// 	first = stack->data;
// 	while (stack->next)
// 	{
// 		if (stack->data > first)
// 			return (0);		
// 		stack = stack->next;
// 	}
// 	return (1);
// }

int	check_sorted(t_list *a)
{
	while (a->next)
	{
		if (a->data > a->next->data)
			return (0);
		a = a->next;
	}
	return (1);
}

void	*sort_three(t_list *a)
{
	while (check_sorted(a) != 1)
	{
		if (a->data > a->next->data)
			swap_top(a, 0);
		else if (a->data > a->next->next->data)
			reverse_rotate(&a, 0);
		else if (a->next->data > a->next->next->data)
		{
			swap_top(a, 0);
			reverse_rotate(&a, 0);
			return (a);
		}
	}
	return (a);
}

void	*sort_four(t_list *a, t_list *b)
{
	(void)b;
	if (check_sorted(a))
		return (a);
	a = push_top(a, &b, 1);
	a = sort_three(a);
	return (a);
}
