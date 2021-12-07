/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   actions2.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: gpirro <gpirro@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/07 13:24:45 by gpirro        #+#    #+#                 */
/*   Updated: 2021/12/07 13:25:08 by gpirro        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "actions.h"

void	rotate_top(t_list *stack)
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
}

void	rotate_both(t_list *a, t_list *b)
{
	rotate_top(a);
	rotate_top(b);
}

void	reverse_rotate(t_list **stack)
{
	int	last;

	last = get((*stack), list_len((*stack)))->data;
	insert(stack, last);
	pop((*stack));
}

void	reverse_both(t_list **a, t_list **b)
{
	reverse_rotate(a);
	reverse_rotate(b);
}
