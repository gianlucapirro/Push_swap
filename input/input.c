/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   input.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: gpirro <gpirro@student.42.fr>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/29 12:21:50 by gianlucapir   #+#    #+#                 */
/*   Updated: 2022/01/26 14:02:40 by gpirro        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"


int	*copy_array(int *array, int len)
{
	int	*new;
	int	i;

	i = 0;
	new = malloc(sizeof(int) * len);
	while (i < len)
	{
		new[i] = array[i];
		i++;
	}
	return (new);
}

int	*input_to_int_array(char *argv[])
{
	int	i;
	int	len;
	int	*a;

	len = length_input(argv);
	a = (int *)malloc(sizeof(int) * len);
	if (!a)
		return (NULL);
	i = 0;
	while (i < len)
	{
		a[i] = ft_atoi(argv[i + 1]);
		i++;
	}
	return (a);
}
