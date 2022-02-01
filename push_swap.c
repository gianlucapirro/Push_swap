/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: gpirro <gpirro@student.42.fr>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/29 12:21:31 by gianlucapir   #+#    #+#                 */
/*   Updated: 2022/01/28 12:07:40 by gpirro        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//returns error message when one occurs
static int	handle_errors(int argc, char *argv[])
{
	if (argc <= 1)
		return (write(2, "Error\n", 6));
	if (input_checker(argv))
		return (1);
	return (0);
}

int	check_sorted(t_list *a)
{
	while (a->next)
	{
		if (a->data > a->next->data)
			return (0);
		a = a->next;
	}
	return (1);
}

void	sort(t_list *a, t_list *b, int argc, t_list *a_small)
{
	int	len;

	len = argc - 1;
	if (len == 1)
		return ;
	else if (len == 2)
		sort_two(a_small);
	else if (len == 3)
		sort_three(a_small);
	else if (len == 4)
		sort_four(a_small, b);
	else if (len == 5)
		sort_five(a_small, b);
	else
		sort_big(a, b);
}

int	main(int argc, char *argv[])
{
	t_list	*a;
	t_list	*b;
	int		*unsorted;
	int		*sorted;
	int		*index_unsorted;

	if (handle_errors(argc, argv))
		exit (0);
	a = list_init();
	b = list_init();
	handle_errors(argc, argv);
	unsorted = input_to_int_array(argv);
	sorted = copy_array(unsorted, length_input(argv));
	sorted = bubblesort(sorted, length_input(argv));
	index_unsorted = return_index_of_countsort(unsorted, sorted, \
	length_input(argv));
	a = array_to_linked_list(index_unsorted, a, length_input(argv));
	sort(a, b, argc, input_to_linked_list(argv, list_init()));
	add_action(0);
}
