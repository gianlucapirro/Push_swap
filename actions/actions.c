#include "actions.h"

void	swap_top(t_list *stack, int print)
{
	int	tmpdata;

	tmpdata = stack->data;
	stack->data = stack->next->data;
	stack->next->data = tmpdata;
	if (print == 0)
		ft_printf("SA\n");
	else if (print == 1)
		ft_printf("SB\n");
}

void	swap_both(t_list *a, t_list *b)
{
	swap_top(a, 2);
	swap_top(b, 2);
	ft_printf("SS\n");
}

void	*push_top(t_list *stack1, t_list **stack2, int print)
{
	if (stack1->next == 0)
		return (NULL);
	insert(stack2, stack1->data);
	pop_i(&stack1, 0);
	if (print == 0)
		ft_printf("PA\n");
	else if (print == 1)
		ft_printf("PB\n");
	return (stack1);
}
