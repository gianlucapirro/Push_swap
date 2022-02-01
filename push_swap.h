/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: gpirro <gpirro@student.42.fr>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/29 12:20:25 by gianlucapir   #+#    #+#                 */
/*   Updated: 2022/01/28 12:08:46 by gpirro        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define A 0
# define B 1

# define PA 1
# define RA 2
# define RB 3
# define PB 4
# define RRA 5
# define RRB 6
# define SA 7
# define SB 8
# define SS 9
# define RR 10
# define RRR 11

# include <stdio.h>
# include "libft/libft.h"
# include "list/list.h"
# include "actions/actions.h"
# include "printf/includes/ft_printf.h"

int		input_checker(char *argv[]);
t_list	*input_to_linked_list(char *argv[], t_list *a);
int		*input_to_int_array(char *argv[]);
int		check_sorted(t_list *a);
void	*sort_three(t_list *a);
t_list	*sort_four(t_list *a, t_list *b);
t_list	*sort_five(t_list *a, t_list *b);
void	printlist(t_list *l);
void	*sort_two(t_list *a);
void	add_action(int nr);
void	sort_big(t_list *a, t_list *b);
int		*bubblesort(int *input, int len);
int		length_input(char *argv[]);
int		*return_index_of_countsort(int *unsorted, int *sorted, int len);
int		*copy_array(int *array, int len);
t_list	*array_to_linked_list(int *sorted, t_list *a, int len);

#endif
