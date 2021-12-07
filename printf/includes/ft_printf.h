/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gianlucapirro <gianlucapirro@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 17:36:28 by gianlucapir       #+#    #+#             */
/*   Updated: 2021/12/03 12:08:11 by gianlucapir      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include "../../push_swap.h"

int				ft_printf(const char *format, ...);
int				ft_putstr(char *str, int should_i_free);
int				ft_putchar(int c);
int				ft_putnbr(int nb, int i);
int				ft_putnbru(int nb, int i);
void			ft_rev_int_tab(char *tab, int size);
char			*strlowcase(char *str);
char			*void_to_hex(void *string);
char			*int_to_hex(int number);

#endif