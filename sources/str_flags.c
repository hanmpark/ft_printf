/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 17:43:57 by hanmpark          #+#    #+#             */
/*   Updated: 2022/12/29 17:53:04 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <stdio.h>

void	pad_zero(t_parseflags *tab, char *str, size_t len)
{
	int	toprint;

	if (tab->check_precision == TRUE)
	{
		if (tab->precision > (int)len)
			tab->precision = len;
		toprint = tab->width - tab->precision;
		while (toprint-- > 0)
			tab->len += write(1, "0", 1);
		while (*str && tab->precision--)
			tab->len += write(1, &*str++, 1);
	}
	else
	{
		toprint = tab->width - (int)len;
		while (toprint-- > 0)
			tab->len += write(1, "0", 1);
		ft_putstr_fd(str, 1);
		tab->len += len;
	}
}

void	left_justify(t_parseflags *tab, char *str, size_t len)
{
	int	toprint;

	if (tab->check_precision == TRUE)
	{
		if (tab->precision > (int)len)
			tab->precision = len;
		toprint = tab->width - tab->precision;
		while (*str && tab->precision--)
			tab->len += write(1, &*str++, 1);
		while (toprint-- > 0)
			tab->len += write(1, " ", 1);
	}
	else
	{
		toprint = tab->width - (int)len;
		ft_putstr_fd(str, 1);
		tab->len += len;
		while (toprint-- > 0)
			tab->len += write(1, " ", 1);
	}
}

void	precision_str(t_parseflags *tab, char *str, size_t len)
{
	if (tab->precision > (int)len)
		tab->precision = len;
	while (*str && tab->precision--)
		tab->len += write(1, &*str++, 1);
}

void	width(t_parseflags *tab, char *str, size_t len)
{
	int	toprint;

	toprint = tab->width - (int)len;
	while (toprint-- > 0)
		tab->len += write(1, " ", 1);
	ft_putstr_fd(str, 1);
}

void	str_wflags(t_parseflags *tab, char *str, size_t len)
{
	if (tab->check_zerojustify == '0')
		pad_zero(tab, str, len);
	else if (tab->check_zerojustify == '-')
		left_justify(tab, str, len);
	else if (tab->check_precision == TRUE)
		precision_str(tab, str, len);
	else if (tab->check_width == TRUE)
		width(tab, str, len);
	else
	{
		ft_putstr_fd(str, 1);
		tab->len += len;
	}
}
