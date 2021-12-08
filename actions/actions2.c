/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gianlucapirro <gianlucapirro@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 13:24:45 by gpirro            #+#    #+#             */
/*   Updated: 2021/12/07 19:47:39 by gianlucapir      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "actions.h"

void	rotate_top(t_list *stack, int print)
{
	t_list	*orig;
	int		first;
	int		last;

	orig = get(stack, 0);
	first = stack->data;
	last = get(stack, 0)->data;
	stack->data = last;
	while (stack->next)
	{
		stack->data = orig->next->data;
		stack = stack->next;
		orig = orig->next;
	}
	stack->data = first;
	if (print == 0)
		ft_printf("RA\n");
	else if (print == 1)
		ft_printf("RB\n");
}

void	rotate_both(t_list *a, t_list *b)
{
	rotate_top(a, 2);
	rotate_top(b, 2);
	ft_printf("RR\n");
}

void	reverse_rotate(t_list **stack, int print)
{
	int	last;

	last = get((*stack), list_len((*stack)))->data;
	insert(stack, last);
	pop((*stack));
	if (print == 0)
		ft_printf("RRA\n");
	else if (print == 1)
		ft_printf("RRB\n");
	return ;
}

void	reverse_both(t_list **a, t_list **b)
{
	reverse_rotate(a, 2);
	reverse_rotate(b, 2);
	ft_printf("RRR\n");
}
