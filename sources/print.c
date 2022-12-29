/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 23:40:18 by hanmpark          #+#    #+#             */
/*   Updated: 2022/12/29 18:01:05 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <stdio.h>

void	print_str(t_parseflags *tab)
{
	char	*str;
	size_t	len;

	str = va_arg(tab->args, char *);
	if (!str)
	{
		ft_putstr_fd("(null)", 1);
		tab->len += 6;
		return ;
	}
	len = ft_strlen(str);
	str_wflags(tab, str, len);
}

void	print_c(t_parseflags *tab)
{
	char	c;
	char	str[2];
	
	c = va_arg(tab->args, int);
	if (!c)
		return ;
	str[0] = c;
	str[1] = 0;
	str_wflags(tab, str, 1);
}

void	print_decimal(t_parseflags *tab)
{
	int		nbr;
	char	*str;
	size_t	len;

	nbr = va_arg(tab->args, int);
	if (!nbr)
		return ;
	str = ft_itoa(nbr);
	len = ft_strlen(str);
	free(str);
}