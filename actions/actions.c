#include "actions.h"

void	swap_top(t_list *stack)
{
	int	tmpdata;

	tmpdata = stack->data;
	stack->data = stack->next->data;
	stack->next->data = tmpdata;
}

void	swap_both(t_list *a, t_list *b)
{
	swap_top(a);
	swap_top(b);
}

void	*push_top(t_list *stack1, t_list *stack2)
{
	if (stack2->next == 0)
		return (NULL);
	insert(&stack2, stack1->data);
	pop_i(&stack1, 0);
	return (NULL);
}

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
