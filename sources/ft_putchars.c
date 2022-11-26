/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchars.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 18:04:43 by hanmpark          #+#    #+#             */
/*   Updated: 2022/11/26 18:23:43 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

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
	char	*null;

	str = va_arg(tab->args, char *);
	null = "(null)";
	if (!str)
	{
		while (*null)
		{
			tab->len += write(1, &*null, 1);
			null++;
		}
	}
	else
	{
		while (*str)
		{
			write(1, &(*str), 1);
			str++;
			tab->len++;
		}
	}
}
