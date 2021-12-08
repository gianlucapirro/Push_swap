/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gianlucapirro <gianlucapirro@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 15:22:03 by gpirro            #+#    #+#             */
/*   Updated: 2021/12/07 17:54:36 by gianlucapir      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ACTIONS_H
# define ACTIONS_H

# include "../push_swap.h"

void	swap_top(t_list *stack, int print);
void	swap_both(t_list *a, t_list *b);
void	*push_top(t_list *stack1, t_list **stack2, int print);
void	rotate_top(t_list *stack, int print);
void	rotate_both(t_list *a, t_list *b);
void	reverse_rotate(t_list **stack, int print);

#endif