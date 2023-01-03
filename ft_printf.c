/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 14:59:34 by hanmpark          #+#    #+#             */
/*   Updated: 2023/01/03 13:18:14 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"
#include <stdio.h>

void	def_types(t_parseflags *tab, const char *input, int *i)
{
	char			c;
	int				k;
	const t_printer	printer_tab[] = {
	{'s', &print_str}, {'c', &print_c}, {'d', &print_decimal},
	{'i', &print_decimal}, {'u', &print_unsigned}, {'x', &print_x},
	{'X', &print_xx}, {'p', &print_p}
	};

	(*i)++;
	def_flags(tab, input, i);
	c = input[*i];
	k = -1;
	while (++k < 8)
	{
		if (c == printer_tab[k].c)
		{
			printer_tab[k].ft(tab);
			return ;
		}
	}
	if (c == '%')
		c_wflags(tab, c);
}

int	ft_printf(const char *input, ...)
{
	t_parseflags	*tab;
	int				i;
	int				cnbr;

	tab = malloc(sizeof(t_parseflags));
	if (!tab)
		return (-1);
	tab->len = 0;
	va_start(tab->args, input);
	i = 0;
	cnbr = 0;
	while (input[i])
	{
		if (input[i] == '%' && input[i + 1])
			def_types(tab, input, &i);
		else if (input[i] && input[i] != '%')
			cnbr += write(1, &input[i], 1);
		i++;
	}
	va_end(tab->args);
	cnbr += tab->len;
	free(tab);
	return (cnbr);
}
