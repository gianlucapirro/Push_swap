#include "actions.h"

void	swap_top(t_list *stack, int print)
{
	int	tmpdata;

	tmpdata = stack->data;
	stack->data = stack->next->data;
	stack->next->data = tmpdata;
	if (print == 0)
		add_action(SA);
	else if (print == 1)
		add_action(SB);
}

void	swap_both(t_list *a, t_list *b)
{
	swap_top(a, 2);
	swap_top(b, 2);
	add_action(SS);
}

t_list	*push_top(t_list *stack1, t_list **stack2, int print)
{
	if (stack1->next == 0)
		return (stack1);
	insert(stack2, stack1->data);
	pop_i(&stack1, 0);
	if (print == 0)
		add_action(PA);
	else if (print == 1)
		add_action(PB);
	return (stack1);
}
