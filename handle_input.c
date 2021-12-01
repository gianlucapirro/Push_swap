/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   handle_input.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: gianlucapirro <gianlucapirro@student.42      +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/29 12:21:50 by gianlucapir   #+#    #+#                 */
/*   Updated: 2021/12/01 17:07:34 by gpirro        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int length_input(char *argv[])
{
	int i;
	
	i = 1;
	while (argv[i])
		i++;
	return (i - 1);	
}

static int	max_int_error(char	*num)
{
	int	nr;
	int	strlen;

	strlen = ft_strlen(num);
	nr = ft_atoi(num);
	if (nr == -1 && strlen > 2)
		return (-1);
	if (nr > 2147483647 || nr <= -2147483648)
		return (1);
	return (0);
}

int	input_checker(char *argv[])
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		if (max_int_error(argv[i]))
			return (write(2, "One of the arguments is bigger than an integer\n", 48));
		j = 0;
		while (argv[i][j])
		{
			if ((argv[i][j] > 57 && argv[i][j] != 45) ||\
			(argv[i][j] < 48 && argv[i][j] != 45))
				return (write(2, "Some arguments are not integers\n", 33));
			j++;
		}
		i++;
	}
	return (0);
}


t_list	*input_to_linked_list(char *argv[], t_list *a)
{
	int i;
	int	len;
	
	len = length_input(argv);
	a->data = ft_atoi(argv[1]);
	i = 1;
	while (i < len)
	{
		list_add(a, ft_atoi(argv[i + 1]));
		i++;
	}
	return (a);
}