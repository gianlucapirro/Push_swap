/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   actions.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: gpirro <gpirro@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/30 15:22:03 by gpirro        #+#    #+#                 */
/*   Updated: 2021/12/01 16:45:01 by gpirro        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef ACTIONS_H
# define ACTIONS_H

# include "../push_swap.h"

void	swap_top(t_list *stack);
void	swap_both(t_list *a, t_list *b);
void	rotate_top(t_list *stack);
void	rotate_both(t_list *a, t_list *b);
void	reverse_rotate(t_list **stack);


#endif