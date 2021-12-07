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

void	*push_top(t_list *stack1, t_list **stack2)
{
	if (stack1->next == 0)
		return (NULL);
	insert(stack2, stack1->data);
	pop_i(&stack1, 0);
	return (stack1);
}
