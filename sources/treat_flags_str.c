/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_flags_str.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 17:14:55 by hanmpark          #+#    #+#             */
/*   Updated: 2022/12/22 15:13:14 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <stdio.h>
// FLAGS ARE : - 0 . WIDTH FOR STRINGS
int	treat_precision(t_toprint *tab, size_t len, char *str)
{
	size_t	i;

	i = 0;
	while (i < tab->width && i < len)
	{
		tab->len += write(1, &str[i], 1);
		i++;
	}
	return (1);
}

int	treat_justify(t_toprint *tab, char *str, int from_left, int pad_zero)
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
	return (1);
}

void	reset_flags(t_toprint *tab)
{
	tab->left_justify = 0;
	tab->pad_zero = 0;
	tab->precision = 0;
	tab->width = 0;
}

int	treat_flags_str(t_toprint *tab, char *str)
{
	size_t	len;
	int		done;

	len = ft_strlen(str);
	done = 0;
	if (tab->precision)

	if (tab->pad_zero && !tab->left_justify)
		done = treat_justify(tab, str, 1, 1);
	else if (tab->left_justify)
		done = treat_justify(tab, str, 0, 0);
	else if (tab->width)
		done = treat_justify(tab, str, 1, 0);
	reset_flags(tab);
	return (done);
}