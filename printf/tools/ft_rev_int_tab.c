/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gianlucapirro <gianlucapirro@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 13:58:30 by gpirro            #+#    #+#             */
/*   Updated: 2021/10/19 18:02:25 by gianlucapir      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_swap(char *a, char *b)
{
	int	swap;

	swap = *a;
	*a = *b;
	*b = swap;
}

void	ft_rev_int_tab(char *tab, int size)
{
	int	count;

	count = 0;
	while (count < size)
	{
		ft_swap(&tab[count], &tab[size - 1]);
		count ++;
		size --;
	}
}
