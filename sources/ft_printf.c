/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 17:39:35 by hanmpark          #+#    #+#             */
/*   Updated: 2022/11/23 13:33:12 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

t_toprint	*init_tab(t_toprint *tab)
{
	tab->len = 0;
	return (tab);
}

int	def_input(t_toprint *tab, const char *input, int i)
{
	if (input[i] == 's')
	{
		ft_putstr_printf(tab);
	}
	return (i);
}

int	ft_printf(const char *input, ...)
{
	t_toprint				*tab;
	unsigned long long int	i;
	unsigned long long int	cnbr;
	va_list					args;

	tab = malloc(sizeof(t_toprint));
	if (!tab)
		return (0);
	init_tab(tab);
	va_start(args, input);
	i = -1;
	cnbr = 0;
	while (input[++i])
	{
		if (input[i] == '%')
			i = def_input(tab, input, i + 1);
		else
		{
			cnbr++;
			write(1, &input[i], 1);
		}
	}
	va_end(args);
	cnbr += tab->len;
	free(tab);
	return (cnbr);
}

#include <stdio.h>
int	main()
{
	ft_printf("Hello %s", "World !");
	return (0);
}