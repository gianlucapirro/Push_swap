/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parsing.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: gpirro <gpirro@student.42.fr>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/20 13:44:08 by gpirro        #+#    #+#                 */
/*   Updated: 2022/03/25 10:39:42 by gpirro        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*copy_stack(t_stack *a, int len)
{
	int	*new;
	int	i;

	new = (int *)malloc(sizeof(int) * len);
	if (!new)
		return (NULL);
	i = 0;
	while (i < len)
	{
		new[i] = a->stack[i];
		i++;
	}
	return (new);
}

void	init_stacks(t_stack *a, t_stack *b, int len, t_stacks *all)
{
	a->top = 0;
	b->top = 0;
	a->stack = malloc(sizeof(int) * len);
	if (!a->stack)
		exit_error(MALLOC_FAILED, "Could not malloc stack A\n", 0, all);
	b->stack = malloc(sizeof(int) * len);
	if (!b->stack)
		exit_error(MALLOC_FAILED, "Could not malloc stack B\n", A, all);
}

int	input_to_stack(int len, char *argv[], t_stack *a, t_stacks *all)
{
	int		i;
	char	*nr;

	i = 0;
	while (len > 0)
	{
		while (argv[len][i])
		{
			if (argv[len][0] == '-' || ft_isdigit(argv[len][i]))
				i++;
			else
				return (0);
		}
		nr = ft_itoa(ft_atoi(argv[len]));
		if (ft_strncmp(nr, argv[len], ft_strlen(argv[len])) == 0)
			a->stack[a->top] = ft_atoi(argv[len]);
		else
			exit_error(INT_OVERFLOW, "Input bigger than integer\n", AB, all);
		free(nr);
		i = 0;
		a->top++;
		len--;
	}
	return (1);
}

int	check_double(t_stack *a)
{
	int	nr_to_check;
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < a->top)
	{
		nr_to_check = a->stack[i];
		while (j < a->top)
		{
			if (nr_to_check == a->stack[j] && j != i)
				return (0);
			j++;
		}
		j = 0;
		i++;
	}
	return (1);
}

void	init_sorted_stack(t_stack *bubblesort, t_stack *a, t_stacks *all)
{
	bubblesort->stack = copy_stack(a, a->top);
	if (!bubblesort)
		exit_error(MALLOC_FAILED, "Malloc failed for bubblesort", AB, all);
	bubblesort->top = a->top;
	bubble_sort(bubblesort);
}
