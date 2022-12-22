/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 17:39:35 by hanmpark          #+#    #+#             */
/*   Updated: 2022/12/22 11:39:51 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

t_toprint	*init_tab(t_toprint *tab)
{
	tab->len = 0;
	tab->left_justify = 0;
	tab->width = 0;
	tab->pad_zero = 0;
	tab->precision = 0;
	return (tab);
}

void	print_numbers(t_toprint *tab, const char *input, unsigned long long i)
{
	if (input[i] && (input[i] == 'd' || input[i] == 'i'))
		ft_putnbr_decibase(tab, va_arg(tab->args, int));
	else if (input[i] && input[i] == 'u')
		ft_putnbr_decibase(tab, va_arg(tab->args, unsigned));
	else if (input[i] && input[i] == 'x')
		ft_putnbr_hexabase(tab, va_arg(tab->args, unsigned), 0);
	else if (input[i] && input[i] == 'X')
		ft_putnbr_hexabase(tab, va_arg(tab->args, unsigned), 1);
	else if (input[i] && input[i] == 'p')
	{
		tab->len += write(1, "0x", 2);
		ft_putnbr_hexabase(tab, va_arg(tab->args, unsigned long long), 0);
	}
}

int	def_input(t_toprint *tab, const char *input, unsigned long long i)
{
	char	c;

	while (input[i] && input[i] == ' ')
		i++;
	c = input[i];
	if (input[i] && (c == 'd' || c == 'i' || c == 'u' || c == 'x' ||
		c =='X' || c == 'p'))
		print_numbers(tab, input, i);
	else if (input[i] && c == 'c')
		ft_putchar_input(tab);
	else if (input[i] && c == 's')
		ft_putstr_input(tab);
	else if (input[i] && c == '%')
		tab->len += write(1, "%", 1);
	else
		tab->len += write(1, &input[i], 1);
	return (i);
}

int	ft_printf(const char *input, ...)
{
	t_toprint	*tab;
	int			i;
	int			cnbr;

	tab = malloc(sizeof(t_toprint));
	if (!tab)
		return (-1);
	init_tab(tab);
	va_start(tab->args, input);
	i = 0;
	cnbr = 0;
	while (input[i])
	{
		if (input[i] == '%' && input[i + 1])
		{
			i = def_flags(tab, input, i + 1);
			i = def_input(tab, input, i);
		}
		else if (input[i] && input[i] != '%')
			cnbr += write(1, &input[i], 1);
		i++;
	}
	va_end(tab->args);
	cnbr += tab->len;
	free(tab);
	return (cnbr);
}
