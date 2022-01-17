/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gianlucapirro <gianlucapirro@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 18:07:52 by gianlucapir       #+#    #+#             */
/*   Updated: 2022/01/14 11:17:57 by gianlucapir      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_sorted(t_list *a)
{
	while (a->next)
	{
		if (a->data > a->next->data)
			return (0);
		a = a->next;
	}
	return (1);
}

void	*sort_three(t_list *a)
{
	while (!check_sorted(a))
	{
		if (a->data > a->next->data && a->data > a->next->next->data)
			rotate_top(a, 0);
		else if (a->data > a->next->data)
			swap_top(a, 0);
		else
		{
			swap_top(a, 0);
			reverse_rotate(&a, 0);
			reverse_rotate(&a, 0);
		}
	}
	return (a);
}

t_list	*sort_four(t_list *a, t_list *b)
{
	int first_item;

	if (check_sorted(a))
		return (a);
	a = push_top(a, &b, 0);
	first_item = b->data;
	printf("VANAF HIER\n");
	while (b->next)
	{
		printf("%i\n", b->data);
		b = b->next;
	}
	printf("%i\n", b->data);
	printf("TOT HIER\n");
	a = sort_three(a);
	push_top(b, &a, 1);
	while (!check_sorted(a))
	{
		if (first_item < a->next->next->data)
			swap_top(a, 0);
		else if (first_item < a->next->next->next->data)
		{
			reverse_rotate(&a, 0);
			swap_top(a, 0);
			rotate_top(a, 0);
			rotate_top(a, 0);
		}
		else
			rotate_top(a, 0);
	}
	return (a);
}

void	five(int first_item, t_list *a)
{
	if (first_item < a->next->next->data)
		swap_top(a, 0);
	else if (first_item < a->next->next->next->data)
	{
		swap_top(a, 0);
		rotate_top(a, 0);
		swap_top(a, 0);
		reverse_rotate(&a, 0);
	}
	else if (first_item < a->next->next->next->next->data)
	{
		reverse_rotate(&a, 0);
		swap_top(a, 0);
		rotate_top(a, 0);
		rotate_top(a, 0);
	}
	else
		rotate_top(a, 0);
}

t_list *sort_five(t_list *a, t_list *b)
{
	int first_item;

	if (check_sorted(a))
		return (a);
	a = push_top(a, &b, 0);
	first_item = b->data;
	a = sort_four(a, b);
	push_top(b, &a, 1);
	while (!check_sorted(a))
		five(first_item, a);
	return (a);
}
