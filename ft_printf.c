/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 14:59:34 by hanmpark          #+#    #+#             */
/*   Updated: 2022/12/28 14:00:24 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"
#include <stdio.h>
void	def_types(t_parseflags *tab, const char *input, int *i)
{
	t_printer	printer_tab[1];
	char		c;
	int			k;

	printer_tab[0].c = 's';
	printer_tab[0].ft = &print_str;
	while (input[*i] && input[*i] == ' ')
		(*i)++;
	def_flags(tab, input, i);
	c = input[*i];
	k = 0;
	while (k < 1)
	{
		if (c == printer_tab[k].c)
		{
			printer_tab[k].ft(tab);
			return ;
		}
		k++;
	}
}

int	ft_printf(const char *input, ...)
{
	t_parseflags	*tab;
	int				*i;
	int				value;
	int				cnbr;

	tab = malloc(sizeof(t_parseflags));
	if (!tab)
		return (-1);
	tab->len = 0;
	va_start(tab->args, input);
	value = 0;
	i = &value;
	cnbr = 0;
	while (input[*i])
	{
		if (input[*i] == '%' && input[*i + 1])
		{
			(*i)++;
			def_types(tab, input, i);
		}
		else if (input[*i] && input[*i] != '%')
			cnbr += write(1, &input[*i], 1);
		(*i)++;
	}
	va_end(tab->args);
	cnbr += tab->len;
	free(tab);
	return (cnbr);
}
