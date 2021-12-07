/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   list.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsiegers <jsiegers@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/02 17:09:12 by jsiegers      #+#    #+#                 */
/*   Updated: 2021/12/07 13:26:04 by gpirro        ########   odam.nl         */
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
