/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gianlucapirro <gianlucapirro@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 12:21:50 by gianlucapir       #+#    #+#             */
/*   Updated: 2021/11/29 13:14:48 by gianlucapir      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	length_input(char *argv[])
{
	int i;
	
	i = 1;
	while (argv[i])
		i++;
	return (i - 1);	
}

int	input_checker(char *argv[])
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (argv[i][j] > 57 || argv[i][j] < 48)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	*input_to_int_array(char *argv[])
{
	int i;
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