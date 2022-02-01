/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   handle_input.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: gpirro <gpirro@student.42.fr>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/29 12:21:50 by gianlucapir   #+#    #+#                 */
/*   Updated: 2022/01/28 12:12:24 by gpirro        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	length_input(char *argv[])
{
	int	i;

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
	nr = ft_atoi(num, &nr);
	if (nr == -1)
		return (-1);
	return (0);
}

int	input_checker(char *argv[])
{
	int	i;
	int	j;

	i = 1;
	if (argv == "")
		return (write(2, "Error\n", 6));
	while (argv[i])
	{
		if (max_int_error(argv[i]))
			return (write(2, "Error\n", 6));
		j = 0;
		while (argv[i][j])
		{
			if ((argv[i][j] > 57 && argv[i][j] != 45) || \
			(argv[i][j] < 48 && argv[i][j] != 45))
				return (write(2, "Error\n", 6));
			j++;
		}
		i++;
	}
	return (0);
}

int	*bubblesort(int *input, int len)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < len)
	{
		j = 0;
		while (j < len - 1)
		{
			if (input[j] > input[j + 1])
			{
				tmp = input[j];
				input[j] = input[j + 1];
				input[j + 1] = tmp;
			}
			j++;
		}
		i ++;
	}
	return (input);
}

t_list	*input_to_linked_list(char *argv[], t_list *a)
{
	int	i;
	int	len;
	int	nr;

	len = length_input(argv);
	ft_atoi(argv[1], &(a->data));
	i = 1;
	while (i < len)
	{
		ft_atoi(argv[i + 1], &nr);
		list_add(a, nr);
		i++;
	}
	return (a);
}

t_list	*array_to_linked_list(int *sorted, t_list *a, int len)
{
	int	i;

	i = 1;
	a->data = sorted[0];
	while (i < len)
	{
		list_add(a, sorted[i]);
		i++;
	}
	return (a);
}
