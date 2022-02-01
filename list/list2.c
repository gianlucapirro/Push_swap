/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   list2.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: gpirro <gpirro@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/07 13:26:09 by gpirro        #+#    #+#                 */
/*   Updated: 2022/01/17 13:42:36 by gpirro        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

int	pop(t_list *list)
{
	t_list	*elem;
	int		data;
	int		i;

	if (list->next == 0)
		return (0);
	elem = list->next;
	while (elem->next)
		elem = elem->next;
	data = elem->data;
	i = list_len(list);
	while ((i - 1) > 0)
	{
		list = list->next;
		i--;
	}
	list->next = 0;
	free(elem);
	return (data);
}

t_list	*get(t_list	*list, int pos)
{
	int		i;
	t_list	*elem;

	i = 0;
	elem = list;
	while (i < pos)
	{
		elem = elem->next;
		i++;
	}
	return (elem);
}

void	*pop_i(t_list **head, int i)
{
	t_list	*beforepop;
	t_list	*popped;
	t_list	*afterpop;

	if ((*head)->next == 0)
		return (0);
	afterpop = get((*head), i + 1);
	popped = get((*head), i);
	if (i == 0)
	{
		(*head) = afterpop;
		free(popped);
		return (0);
	}
	beforepop = get((*head), i - 1);
	beforepop->next = afterpop;
	free(popped);
	return (0);
}

int	insert(t_list **head, int new_data)
{
	t_list	*new_node;

	new_node = (t_list *)malloc(sizeof(t_list));
	if (!new_node)
		return (0);
	new_node->data = new_data;
	new_node->next = (*head);
	(*head) = new_node;
	return (new_node->data);
}