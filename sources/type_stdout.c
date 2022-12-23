/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_stdout.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 11:28:36 by hanmpark          #+#    #+#             */
/*   Updated: 2022/12/23 18:54:55 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_putnbrbase(t_toprint *tab, char *base, long long i)
{
	size_t	baselen;

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

void	ft_putnbrbase_p(t_toprint *tab, char *base, unsigned long long i)
{
	size_t	baselen;

	baselen = ft_strlen(base);
	if (i >= (unsigned long long)baselen)
		ft_putnbrbase(tab, base, i / (unsigned long long)baselen);
	ft_putchar_fd(base[i % baselen], 1);
	tab->len++;
}

void	ft_printchar(t_toprint *tab, int is_char)
{
	char	*str;
	char	c;

	if (is_char)
	{
		c = va_arg(tab->args, int);
		tab->len += write(1, &c, 1);
	}
	else
	{
		str = va_arg(tab->args, char *);
		if (!str)
		{
			ft_putstr_fd("(null)", 1);
			tab->len += 6;
		}
		else
		{
			ft_putstr_fd(str, 1);
			tab->len += ft_strlen(str);
		}
	}
}