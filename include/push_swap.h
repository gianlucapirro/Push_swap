/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: gpirro <gpirro@student.42.fr>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/20 13:30:24 by gpirro        #+#    #+#                 */
/*   Updated: 2022/03/22 13:30:26 by gpirro        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>

typedef struct s_stack
{
	int	*stack;
	int	top;
}	t_stack;

typedef struct s_stacks
{
	t_stack	a;
	t_stack	b;
	t_stack	bubble;
	t_stack	index_bubble;
}	t_stacks;

typedef enum e_error
{
	MALLOC_FAILED,
	INT_OVERFLOW,
	STACK_ALLOCATION_FAIL,
	DOUBLE_INTEGER,
	SUCCES
}	t_error;

typedef enum e_free_stacks{
	A,
	B,
	AB,
	ABB,
	ABBI
}	t_free_stacks;

typedef enum e_actions{
	SA,
	SB,
	PA,
	PB,
	RA,
	RB,
	RRA,
	RRB
}	t_actions;

void	exit_error(int exitcode, char *errormsg, \
int stack_to_free, t_stacks *all);
void	init_stacks(t_stack *a, t_stack *b, int len, t_stacks *all);
int		input_to_stack(int len, char *argv[], t_stack *a, t_stacks *all);
int		check_double(t_stack *a);
int		*copy_stack(t_stack *a, int len);
void	bubble_sort(t_stack *stack);
void	init_sorted_stack(t_stack *bubblesort, t_stack *a, t_stacks *all);
void	index_bubblesort(t_stack *a, t_stack *bubble, t_stacks *all);
int		check_sorted(int *stack, int len);
int		swap(t_stack *s, int print);
int		push(t_stack *from, t_stack *to, int print);
int		rotate(t_stack *s, int print);
int		r_rotate(t_stack *s, int print);
void	sort_two(t_stack *a);
void	sort_three(t_stack *a);
void	sort_four(t_stack *a, t_stack *b);
void	sort_five(t_stack *a, t_stack *b);
void	sort_five(t_stack *a, t_stack *b);
void	radix_sort(t_stack *a, t_stack *b);

#endif