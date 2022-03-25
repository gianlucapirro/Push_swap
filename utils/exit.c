/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   exit.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: gpirro <gpirro@student.42.fr>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/20 13:45:32 by gpirro        #+#    #+#                 */
/*   Updated: 2022/03/25 10:40:39 by gpirro        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	exit_error(int exitcode, char *errormsg, \
int stack_to_free, t_stacks *all)
{
	if (ft_strncmp("", errormsg, 1) != 0)
		ft_putstr_fd(errormsg, 2);
	if (stack_to_free == A)
		free(all->a.stack);
	else if (stack_to_free == AB)
	{
		free(all->a.stack);
		free(all->b.stack);
	}
	else if (stack_to_free == ABB)
	{
		free(all->a.stack);
		free(all->b.stack);
		free(all->bubble.stack);
	}
	else if (stack_to_free == ABBI)
	{
		free(all->a.stack);
		free(all->b.stack);
		free(all->bubble.stack);
		free(all->index_bubble.stack);
	}
	exit(exitcode);
}
