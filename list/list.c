/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   list.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsiegers <jsiegers@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/02 17:09:12 by jsiegers      #+#    #+#                 */
/*   Updated: 2021/12/01 15:55:16 by gpirro        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

t_list	*list_init(void)
{
	t_list	*list;

	list = malloc(sizeof(t_list));
	if (list == 0)
		return (0);
	list->next = 0;
	return (list);
}

void	free_elems(t_list *elem, int free_data)
{
	if (elem->next)
		free_elems(elem->next, free_data);
	if (free_data)
		free(&(elem->data));
	free(elem);
}

void	free_list(t_list *list, int	free_data)
{
	if (list->next)
		free_elems(list->next, free_data);
	free(list);
}

void	*list_add(t_list *list, int data)
{	
	t_list	*new_elem;
	t_list	*tmp;

	new_elem = malloc(sizeof(t_list));
	if (new_elem == 0)
		return (0);
	new_elem->data = data;
	new_elem->next = 0;
	if (list->next == NULL)
		list->next = new_elem;
	else
	{
		tmp = list->next;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new_elem;
	}
	return (new_elem);
}

int	list_len(t_list	*list)
{
	int	i;

	i = 0;
	while (list->next)
	{
		i++;
		list = list->next;
	}
	return (i);
}

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
 
	new_node = (t_list*)malloc(sizeof(t_list));
	if (!new_node)
		return (0);	
    new_node->data = new_data;
    new_node->next = (*head);
 	(*head) = new_node;
	return (new_node->data);
}

// void	*insert_i(t_list *list, void *data, int i)
// {
// 	t_list	*elem;
// 	t_list	*tmp;
// 	int		p;

// 	if (list->len >= i)
// 		return (0);
// 	elem = malloc(sizeof(t_list));
// 	if (elem == 0)
// 		return (0);
// 	elem->data = data;
// 	if (list->next == 0)
// 	{
// 		elem->next = 0;
// 		elem->prev = 0;
// 		list->next = elem;
// 		return (data);
// 	}
// 	p = 0;
// 	tmp = list->next;
// 	while (p++ < i)
// 		tmp = tmp->next;
// 	elem->next = tmp;
// 	elem->prev = tmp->prev;
// 	tmp->prev = elem;
// 	if (p == 0)
// 		list->next = elem;
// 	return (data);
// }

// void	**list_to_array(t_list *list)
// {
// 	void	**res;
// 	int		i;
// 	t_list	*elem;

// 	res = malloc(sizeof(void *) * list->len);
// 	if (res == 0)
// 	{
// 		free_list(list, 1);
// 		return (0);
// 	}
// 	i = 0;
// 	elem = list->next;
// 	while (elem)
// 	{
// 		res[i] = elem->data;
// 		elem = elem->next;
// 		i++;
// 	}
// 	free_list(list, 0);
// 	return (res);
// }
