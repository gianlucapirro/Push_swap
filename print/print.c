/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: gpirro <gpirro@student.42.fr>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/17 17:32:15 by gpirro        #+#    #+#                 */
/*   Updated: 2022/01/18 12:31:41 by gpirro        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	print_action(int x)
{
	if (x == PA)
		ft_printf("pa\n");
	else if (x == PB)
		ft_printf("pb\n");
	else if (x == SA)
		ft_printf("sa\n");
	else if (x == SB)
		ft_printf("sb\n");
	else if (x == SS)
		ft_printf("ss\n");
	else if (x == RA)
		ft_printf("ra\n");
	else if (x == RB)
		ft_printf("rb\n");
	else if (x == RR)
		ft_printf("rr\n");
	else if (x == RRA)
		ft_printf("rra\n");
	else if (x == RRB)
		ft_printf("rrb\n");
	else if (x == RRR)
		ft_printf("rrr\n");
}

//TODO: klopt niet als er twee keer pa achter elkaar komt en daarna meteen pb 
static void	print_all_actions(t_list *actions)
{
	int	prev;

	prev = 0;
	while (actions)
	{
		if (actions->data < 7 && prev < 7 \
		&& (actions->data - prev + 6) % 6 == 3)
			prev = 100;
		else
		{
			print_action(prev);
			prev = actions->data;
		}
		actions = actions->next;
	}
	print_action(prev);
}

void	add_action(int nr)
{
	static t_list	*actions;

	if (actions == 0)
		actions = list_init();
	if (nr == 0)
		print_all_actions(actions);
	else
		list_add(actions, nr);
}
