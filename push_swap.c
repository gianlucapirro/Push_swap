/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gianlucapirro <gianlucapirro@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 12:21:31 by gianlucapir       #+#    #+#             */
/*   Updated: 2021/12/03 12:36:52 by gianlucapir      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//returns error message when one occurs
static int	handle_errors(int argc, char *argv[])
{
	if (argc <= 1)
		return (write(2, "Please enter a stack to be sorted\n", 35));	
	if (input_checker(argv))
		return (1);
	return (0);
}

int main(int argc, char *argv[])
{
	t_list	*a;

	if (handle_errors(argc, argv))
		exit (0);	
	a = list_init();
	handle_errors(argc, argv);
	input_to_linked_list(argv, a);
	sort_three(a);
}