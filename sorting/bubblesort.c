/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   bubblesort.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: gpirro <gpirro@student.42.fr>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/21 12:37:18 by gpirro        #+#    #+#                 */
/*   Updated: 2022/03/25 10:40:06 by gpirro        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_sorted(int *stack, int len)
{
	int	i;

	i = 0;
	while (i < len - 1)
	{
		if (!(stack[i] > stack[i + 1]))
			return (0);
		i++;
	}
	return (1);
}

void	bubble_sort(t_stack *stack)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < stack->top - 1)
	{
		j = 0;
		while (j < stack->top - i - 1)
		{
			if (stack->stack[j] > stack->stack[j + 1])
			{
				tmp = stack->stack[j];
				stack->stack[j] = stack->stack[j + 1];
				stack->stack[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
}

void	index_bubblesort(t_stack *a, t_stack *bubble, t_stacks *all)
{
	int		i;
	int		j;

	all->index_bubble.stack = malloc(sizeof(int) * bubble->top);
	if (!all->index_bubble.stack)
		exit_error(MALLOC_FAILED, "Could not malloc index array\n", ABB, all);
	all->index_bubble.top = bubble->top;
	i = 0;
	while (i < bubble->top)
	{
		j = 0;
		while (j < bubble->top)
		{
			if (bubble->stack[i] == a->stack[j])
			{
				all->index_bubble.stack[j] = i;
				break ;
			}
			j++;
		}
		i++;
	}
}
