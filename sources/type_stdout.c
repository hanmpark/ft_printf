/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_stdout.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 11:28:36 by hanmpark          #+#    #+#             */
/*   Updated: 2022/12/21 23:58:39 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_putnbrbase(t_toprint *tab, char *base, long long i)
{
	size_t				baselen;

	baselen = ft_strlen(base);
	if (i < 0)
	{
		tab->len += write(1, "-", 1);
		i *= -1;
	}
	if (i >= (long long)baselen)
		ft_putnbrbase(tab, base, i / (long long)baselen);
	ft_putchar_fd(base[i % baselen], 1);
	tab->len++;
}

void	ft_putnbrbase_p(t_toprint *tab, char *base, unsigned long i)
{
	size_t				baselen;

	baselen = ft_strlen(base);
	if (i >= baselen)
		ft_putnbrbase_p(tab, base, i / baselen);
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
	size_t	len;
	int		i;

	str = va_arg(tab->args, char *);
	if (!str)
	{
		ft_putstr_fd("(null)", 1);
		tab->len += 6;
		return ;
	}
	i = 0;
	str = ft_strdup(str);
	len = ft_strlen(str);
	if (tab->pad_zero)
	{
		treat_justify(tab, str, 1, 1);
		tab->pad_zero = 0;
	}
	else if (tab->precision)
	{
		treat_precision(tab, len, str);
		tab->precision = 0;
	}
	else if (tab->left_justify)
	{
		treat_justify(tab, str, 0, 0);
		tab->left_justify = 0;
	}
	else if (tab->width)
	{
		treat_justify(tab, str, 1, 0);
		tab->width = 0;
	}
	else
	{
		ft_putstr_fd(str, 1);
		tab->len += ft_strlen(str);
	}
	free (str);
}