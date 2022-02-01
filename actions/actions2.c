/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   actions2.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: gpirro <gpirro@student.42.fr>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/07 13:24:45 by gpirro        #+#    #+#                 */
/*   Updated: 2022/01/18 11:52:03 by gpirro        ########   odam.nl         */
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
		add_action(RA);
	else if (print == 1)
		add_action(RB);
}

void	rotate_both(t_list *a, t_list *b)
{
	rotate_top(a, 2);
	rotate_top(b, 2);
	add_action(RR);
}

void	reverse_rotate(t_list **stack, int print)
{
	int	last;

	last = get((*stack), list_len((*stack)))->data;
	insert(stack, last);
	pop((*stack));
	if (print == 0)
		add_action(RRA);
	else if (print == 1)
		add_action(RRB);
	return ;
}

void	reverse_both(t_list **a, t_list **b)
{
	reverse_rotate(a, 2);
	reverse_rotate(b, 2);
	add_action(RRR);
}
