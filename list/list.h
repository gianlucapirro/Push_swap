#ifndef LIST_H
# define LIST_H

# include <stddef.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <stdarg.h>
# include "../libft/libft.h"

typedef struct s_list {
	struct s_list	*next;
	int				data;
}	t_list;

int		list_len(t_list	*list);
t_list	*list_init(void);
void	free_list(t_list *list, int free_data);
void	*list_add(t_list *list, int data);
int		pop(t_list *list);
void	*pop_i(t_list **head, int i);
t_list	*get(t_list	*list, int pos);
int		insert(t_list **head, int new_data);
void	*insert_i(t_list *list, void *data, int i);
t_list	*str_array_to_list(char **array);
t_list	*list_atoi(t_list *list);
int		*list_to_int_array(t_list *list);
void	**list_to_array(t_list *list);

#endif
