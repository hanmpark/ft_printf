/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_stdout.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 11:28:36 by hanmpark          #+#    #+#             */
/*   Updated: 2022/12/22 13:10:27 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_putnbr_decibase(t_toprint *tab, long long i)
{
	char	*str;

	str = ft_itoa(i);
	if (!treat_flags(tab, str))
	{
		ft_putstr_fd(str, 1);
		tab->len += ft_strlen(str);
	}
	free(str);
}

void	ft_putnbr_hexabase(t_toprint *tab, unsigned long long i, int is_maj)
{
	char	*base;
	size_t	baselen;
	size_t	k;

	base = "0123456789abcdef";
	baselen = ft_strlen(base);
	k = 0;
	if (is_maj)
		base = "0123456789ABCDEF";
	if (i < 0)
	{
		tab->len += write(1, "-", 1);
		i *= -1;
	}
	if (i >= baselen)
		ft_putnbr_hexabase(tab, i / baselen, is_maj);
	ft_putchar_fd(base[i % baselen], 1);
	tab->len++;
}

void	ft_putchar_input(t_toprint *tab)
{
	char	c;

	c = va_arg(tab->args, int);
	write(1, &c, 1);
	tab->len++;
}

void	ft_putstr_input(t_toprint *tab)
{
	char	*str;
	int		i;

	str = va_arg(tab->args, char *);
	if (!str)
	{
		ft_putstr_fd("(null)", 1);
		tab->len += 6;
		return ;
	}
	i = 0;
	if (!treat_flags(tab, str))
	{
		ft_putstr_fd(str, 1);
		tab->len += ft_strlen(str);
	}
}