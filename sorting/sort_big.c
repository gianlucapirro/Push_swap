/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_big.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: gpirro <gpirro@student.42.fr>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/25 12:41:52 by gpirro        #+#    #+#                 */
/*   Updated: 2022/01/26 17:23:09 by gpirro        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	find_len(t_list *stack)
{
	int	len;

	len = 0;
	while (stack->next)
	{
		len ++;
		stack = stack->next;
	}
	return (len + 1);
}

int	*return_index_of_countsort(int *unsorted, int *sorted, int len)
{
	int	i;
	int	j;
	int	*index_unsorted;

	i = 0;
	j = 0;
	index_unsorted = malloc(sizeof(int) * len);
	while (i < len)
	{
		if (unsorted[i] == sorted[j])
		{
			index_unsorted[i] = j;
			j = 0;
			i++;
		}
		else
			j++;
	}
	return (index_unsorted);
}

void	sort_big(t_list *a, t_list *b)
{
	int	i;
	int	j;
	int	len;

	j = 0;
	len = find_len(a);
	while (check_sorted(a) != 1)
	{
		i = 0;
		while (i < len)
		{
			if ((a->data >> j) % 2 == 0)
				a = push_top(a, &b, B);
			else
				rotate_top(a, A);
			i++;
		}
		i = 0;
		while (i < find_len(a))
		{
			b = push_top(b, &a, A);
			i++;
		}
		j++;
	}
}
