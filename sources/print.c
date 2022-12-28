/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 23:40:18 by hanmpark          #+#    #+#             */
/*   Updated: 2022/12/28 21:40:31 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <stdio.h>

void	pad_zero(t_parseflags *tab, char *str, size_t len)
{
	int	toprint;

	if (tab->check_precision == FALSE)
	{
		toprint = tab->width - (int)len;
		if (toprint <= 0)
		{
			ft_putstr_fd(str, 1);
			tab->len += (int)len;
			return ;
		}
	}
	else
		toprint = tab->width - tab->precision;
	while (toprint--)
		tab->len += write(1, "0", 1);
	ft_putstr_fd(str, 1);
	tab->len += (int)len;
}

void	left_justify(t_parseflags *tab, char *str, size_t len)
{
	int	toprint;

	if (tab->check_precision == FALSE)
	{
		toprint = tab->width - (int)len;
		if (toprint <= 0)
		{
			ft_putstr_fd(str, 1);
			tab->len += (int)len;
			return ;
		}
	}
	else
	{
		if (tab->precision > tab->width)
		{
			
		}
	}
	while (tab->precision--)
	{
		ft_putchar_fd(*str++, 1);
		tab->len++;
	}
	while (toprint--)
		tab->len += write(1, " ", 1);
}

void	print_wflags(t_parseflags *tab, char *str, size_t len)
{
	if (tab->check_zerojustify == '0')
		pad_zero(tab, str, len);
	else if (tab->check_zerojustify == '-')
		left_justify(tab, str, len);
	else
	{
		ft_putstr_fd(str, 1);
		tab->len += (int)len;
	}
}

void	print_str(t_parseflags *tab)
{
	char	*str;
	size_t	len;

	str = va_arg(tab->args, char *);
	if (!str)
	{
		ft_putstr_fd("(null)", 1);
		tab->len += 6;
	}
	else
	{
		len = ft_strlen(str);
		print_wflags(tab, str, len);
	}
}