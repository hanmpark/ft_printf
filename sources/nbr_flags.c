/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nbr_flags.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 17:54:49 by hanmpark          #+#    #+#             */
/*   Updated: 2022/12/31 17:40:08 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <stdio.h>

int	count_precision(t_parseflags *tab, char *str)
{
	int		i;
	int		toprint;

	i = 0;
	toprint = tab->precision - (int)ft_strlen(str);
	while (i++ < toprint)
		tab->len += write(1, "0", 1);
	if (toprint <= 0)
	{
		ft_putstr_fd(str, 1);
		tab->len += (int)ft_strlen(str);
	}
	return (toprint);
}

void	precision_nbr(t_parseflags *tab, char *str, int sign)
{
	int	toprint;
	int	len;

	len = (int)ft_strlen(str);
	if (sign == TRUE || (sign == FALSE && tab->check_nbrflags == '+')
		|| (sign == FALSE && tab->check_nbrflags == ' '))
		len++;
	toprint = tab->precision - len;
	if (toprint < 0)
		toprint = 0;
	if (tab->precision > len)
		width(tab, (size_t)tab->precision);
	while (toprint--)
		tab->len += write(1, "0", 1);
	if (toprint <= 0)
	{
		ft_putstr_fd(str, 1);
		tab->len += (int)ft_strlen(str);
	}
}

void	pad_zero(t_parseflags *tab, char *str, int sign)
{
	int		toprint;
	int		len;

	len = 0;
	if (sign == TRUE || (sign == FALSE && tab->check_nbrflags == '+')
		|| (sign == FALSE && tab->check_nbrflags == ' '))
		len = 1;
	else if (tab->check_nbrflags == '#')
		len = 2;
	len += (int)ft_strlen(str);
	if (tab->check_precision == TRUE)
		len += count_precision(tab, str);
	toprint = tab->width - len;
	if (tab->check_nbrflags == '#')
		tab->len += write(1, "0x", 2);
	while (toprint-- > 0)
		tab->len += write(1, "0", 1);
	ft_putstr_fd(str, 1);
	tab->len += (int)ft_strlen(str);
}

void	left_justifynbr(t_parseflags *tab, char *str, int sign)
{
	int		toprint;
	int		len;

	len = 0;
	if (sign == TRUE || (sign == FALSE && tab->check_nbrflags == '+')
		|| (sign == FALSE && tab->check_nbrflags == ' '))
		len = 1;
	else if (tab->check_nbrflags == '#')
		len = 2;
	len += (int)ft_strlen(str);
	if (tab->check_nbrflags == '#')
		tab->len += write(1, "0x", 2);
	if (tab->check_precision == TRUE)
		len += count_precision(tab, str);
	toprint = tab->width - len;
	ft_putstr_fd(str, 1);
	tab->len += (int)ft_strlen(str);
	while (toprint-- > 0)
		tab->len += write(1, " ", 1);
}

void	nbr_wflags(t_parseflags *tab, char *str, int sign)
{
	if (sign == FALSE && tab->check_nbrflags == '+')
		tab->len += write(1, "+", 1);
	else if (sign == FALSE && tab->check_nbrflags == ' ')
		tab->len += write(1, " ", 1);
	else if (sign == TRUE)
		tab->len += write(1, "-", 1);
	if (tab->check_zerojustify == '0' && tab->check_precision == FALSE)
		pad_zero(tab, str, sign);
	else if (tab->check_zerojustify == '-')
		left_justifynbr(tab, str, sign);
	else if (tab->check_precision == TRUE)
		precision_nbr(tab, str, sign);
	else
	{
		width(tab, ft_strlen(str));
		ft_putstr_fd(str, 1);
		tab->len += (int)ft_strlen(str);
	}
}
