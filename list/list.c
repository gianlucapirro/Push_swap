/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   list.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: gpirro <gpirro@student.42.fr>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/02 17:09:12 by jsiegers      #+#    #+#                 */
/*   Updated: 2022/01/26 17:04:23 by gpirro        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

t_list	*list_init(void)
{
	t_list	*list;

	list = ft_calloc(sizeof(t_list), 1);
	if (list == 0)
		return (0);
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
