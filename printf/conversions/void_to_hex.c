/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   void_to_hex.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: gianlucapirro <gianlucapirro@student.42      +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/19 18:07:13 by gianlucapir   #+#    #+#                 */
/*   Updated: 2021/10/22 11:47:05 by gpirro        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*void_to_hex(void *ptr)
{
	char	*new;
	long	number;
	long	temp;
	int		i;

	number = (long)ptr;
	new = (char *)malloc(sizeof(char) * 12);
	if (!new)
		return (0);
	i = 0;
	if ((char *)ptr == 0)
	{
		new[0] = '0';
		new[1] = 'x';
		new[2] = '0';
		new[3] = 0;
		return (new);
	}
	while (number != 0)
	{
		temp = 0;
		temp = number % 16;
		if (temp < 10)
			new[i++] = temp + 48;
		else
			new[i++] = temp + 55;
		number /= 16;
	}
	new[i] = 'x';
	new[i + 1] = '0';
	new[i + 2] = '\0';
	ft_rev_int_tab(new, ft_strlen(new));
	return (new);
}
