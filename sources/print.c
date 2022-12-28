/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 23:40:18 by hanmpark          #+#    #+#             */
/*   Updated: 2022/12/28 17:18:33 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <stdio.h>

void	print_wflags(t_parseflags *tab, char *str, size_t len)
{
	int	toprint;

	toprint = tab->width - (int)len;
	if (toprint <= 0)
	{
		ft_putstr_fd(str, 1);
		tab->len += (int)len;
		return ;
	}
	if (tab->check_zerojustify == '0' && tab->check_precision == FALSE)
	{
		while (toprint--)
			tab->len += write(1, "0", 1);
		ft_putstr_fd(str, 1);
		tab->len += (int)len;
	}
	else if (tab->check_zerojustify == '-' && tab->check_precision == FALSE)
	{
		ft_putstr_fd(str, 1);
		tab->len += (int)len;
		while (toprint--)
			tab->len += write(1, " ", 1);	
	}
}

void	print_str(t_parseflags *tab)
{
	char	*str;
	size_t	len;
	int		toprint;

	str = va_arg(tab->args, char *);
	if (!str)
	{
		ft_putstr_fd("(null)", 1);
		tab->len += 6;
	}
	else
	{
		len = ft_strlen(str);
		toprint = 0;
		print_wflags(tab, str, len);
	}
}