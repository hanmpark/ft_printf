/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nbr_flags.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 17:54:49 by hanmpark          #+#    #+#             */
/*   Updated: 2022/12/30 17:51:59 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <stdio.h>

int	count_precision(t_parseflags *tab, unsigned long long nbr)
{
	int		i;
	int		toprint;
	char	*str;

	i = 0;
	str = ft_itoa(nbr);
	toprint = tab->precision - (int)ft_strlen(str);
	while (i++ < toprint)
		tab->len += write(1, "0", 1);
	if (toprint <= 0)
	{
		ft_putstr_fd(str, 1);
		tab->len += (int)ft_strlen(str);
	}
	free(str);
	return (toprint);
}

void	precision_nbr(t_parseflags *tab, unsigned long long nbr)
{
	int		toprint;
	char	*str;

	str = ft_itoa(nbr);
	toprint = tab->precision - (int)ft_strlen(str);
	if (toprint < 0)
		toprint = 0;
	if (tab->precision > (int)ft_strlen(str))
		width(tab, (size_t)tab->precision);
	while (toprint--)
		tab->len += write(1, "0", 1);
	if (toprint <= 0)
	{
		ft_putstr_fd(str, 1);
		tab->len += (int)ft_strlen(str);
	}
	free(str);
}

void	pad_zero(t_parseflags *tab, unsigned long long nbr, int sign)
{
	int		toprint;
	int		len;
	char	*str;

	len = 0;
	if (sign == TRUE || (sign == FALSE && tab->check_nbrflags == '+'))
		len = 1;
	str = ft_itoa(nbr);
	len += (int)ft_strlen(str);
	if (tab->check_precision == TRUE)
		len += count_precision(tab, nbr);
	toprint = tab->width - len;
	while (toprint-- > 0)
		tab->len += write(1, "0", 1);
	ft_putstr_fd(str, 1);
	free(str);
	tab->len += (int)ft_strlen(str);
}

void	left_justifynbr(t_parseflags *tab, unsigned long long nbr, int sign)
{
	int		toprint;
	int		len;
	char	*str;

	len = 0;
	if (sign == TRUE || (sign == FALSE && tab->check_nbrflags == '+'))
		len = 1;
	str = ft_itoa(nbr);
	len += (int)ft_strlen(str);
	if (tab->check_precision == TRUE)
		len += count_precision(tab, nbr);
	toprint = tab->width - len;
	ft_putstr_fd(str, 1);
	free(str);
	tab->len += (int)ft_strlen(str);
	while (toprint-- > 0)
		tab->len += write(1, " ", 1);
}

void	nbr_wflags(t_parseflags *tab, unsigned long long nbr, int sign)
{
	char	*str;

	str = ft_itoa(nbr);
	if (sign == FALSE && tab->check_nbrflags == '+')
		tab->len += write(1, "+", 1);
	else if (sign == TRUE)
		tab->len += write(1, "-", 1);
	if (tab->check_zerojustify == '0' && tab->check_precision == FALSE)
		pad_zero(tab, nbr, sign);
	else if (tab->check_zerojustify == '-')
		left_justifynbr(tab, nbr, sign);
	else if (tab->check_precision == TRUE)
		precision_nbr(tab, nbr);
	else
	{
		width(tab, ft_strlen(str));
		ft_putstr_fd(str, 1);
		tab->len += (int)ft_strlen(str);
	}
	free(str);
}