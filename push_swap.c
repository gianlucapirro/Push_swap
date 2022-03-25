/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: gpirro <gpirro@student.42.fr>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/20 13:31:22 by gpirro        #+#    #+#                 */
/*   Updated: 2022/03/22 14:33:38 by gpirro        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort(int argc, t_stacks all)
{
	if (argc == 3)
		sort_two(&all.a);
	else if (argc == 4)
		sort_three(&all.a);
	else if (argc == 5)
		sort_four(&all.a, &all.b);
	else if (argc == 6)
		sort_five(&all.a, &all.b);
	else
		radix_sort(&all.index_bubble, &all.b);
}

void	init(int argc, char *argv[])
{
	t_stacks	all;

	(void)argv;
	init_stacks(&all.a, &all.b, argc - 1, &all);
	if (input_to_stack(argc - 1, argv, &all.a, &all) == 0)
		exit_error(STACK_ALLOCATION_FAIL, \
		"Could not fill input in stack, invalid input\n", AB, &all);
	if (check_double(&all.a) == 0)
		exit_error(DOUBLE_INTEGER, "Same integer entered twice\n", AB, &all);
	init_sorted_stack(&all.bubble, &all.a, &all);
	index_bubblesort(&all.a, &all.bubble, &all);
	if (check_sorted(all.index_bubble.stack, all.index_bubble.top))
		exit_error(SUCCES, "", ABBI, &all);
	sort(argc, all);
	exit_error(SUCCES, "", ABBI, &all);
}

int	main(int argc, char *argv[])
{
	if (argc > 1)
		init(argc, argv);
	return (0);
}
