/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 17:14:55 by hanmpark          #+#    #+#             */
/*   Updated: 2022/12/21 22:50:01 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <stdio.h>
// FLAGS ARE : - 0 . WITH WIDTH FOR STRINGS
void	treat_precision(t_toprint *tab, size_t len, char *str)
{
	size_t	i;

	i = 0;
	while (i < tab->width && i < len)
	{
		tab->len += write(1, &str[i], 1);
		i++;
	}
}

void	treat_justify(t_toprint *tab, char *str, int from_left, int pad_zero)
{
	size_t	i;
	size_t	len;
	int		space;

	i = 0;
	len = ft_strlen(str);
	space = tab->width - (int)len;
	if (from_left)
	{
		while (space-- > 0)
		{
			if (pad_zero)
				tab->len += write(1, "0", 1);
			else
				tab->len += write(1, " ", 1);
		}
	}
	ft_putstr_fd(str, 1);
	tab->len += len;
	if (!from_left)
	{
		while (space-- > 0)
			tab->len += write(1, " ", 1);
	}
}
