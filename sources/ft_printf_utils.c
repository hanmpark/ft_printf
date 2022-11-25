/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 11:28:36 by hanmpark          #+#    #+#             */
/*   Updated: 2022/11/25 07:34:15 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void ft_putchar(char c)
{
	write(1, &c, 1);
}
void	ft_putchar_f(t_toprint *tab)
{
	char	c;

	c = va_arg(tab->args, int);
	write(1, &c, 1);
	tab->len++;
}

void	ft_putstr_f(t_toprint *tab)
{
	char	*str;

	str = va_arg(tab->args, char *);
	while (*str)
	{
		write(1, &(*str), 1);
		str++;
		tab->len++;
	}
}

void	ft_putint_f(t_toprint *tab)
{
	int		i;
	int		len;

	i = va_arg(tab->args, int);
	len = 1;
	while (i / len)
	{
		len *= 10;
		tab->len++;
	}
	if (i < 0)
	{
		write(1, "-", 1);
		i *= -1;
	}
	while (i / len)
	{
		ft_putchar(i / len + '0');
		len /= 10;
	}
}