/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_to_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gianlucapirro <gianlucapirro@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 18:07:13 by gianlucapir       #+#    #+#             */
/*   Updated: 2021/10/20 13:44:26 by gianlucapir      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*int_to_hex(int number)
{
	char	*new;
	int		temp;
	int		i;

	new = (char *)malloc(sizeof(char) * 10);
	if (!new)
		return (0);
	i = 0;
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
	ft_rev_int_tab(new, ft_strlen(new));
	return (new);
}
