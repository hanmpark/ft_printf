/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 23:40:18 by hanmpark          #+#    #+#             */
/*   Updated: 2022/12/28 02:00:49 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf_bonus.h"

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
		if (tab->width)
		{
			toprint = tab->width - (int)len;
			if (tab->check_zerojustify == '0')
			{
				while (toprint-- && tab->check_precision == FALSE)
					tab->len += write(1, "0", 1);
			}
		}
		ft_putstr_fd(str, 1);
		tab->len += (int)len;
	}
}