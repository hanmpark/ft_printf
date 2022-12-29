/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nbr_flags.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 17:54:49 by hanmpark          #+#    #+#             */
/*   Updated: 2022/12/29 18:30:39 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <stdio.h>

void	pad_zero(t_parseflags *tab, char *str, size_t len)
{
	int	toprint;
	int	nbr;

	nbr = ft_atoi(str);
	if (nbr < 0)
	{
		tab->len += write(1, "-", 1);
		nbr *= -1;
	}
	else if (tab->check_nbrflags == '+')
	{
		if (nbr >= 0)
			tab->len += write(1, "+", 1);
	}
	toprint = tab->width - (int)len;
	while (toprint-- > 0)
		tab->len += write(1, "0", 1);
	ft_putstr_fd(str, 1);
	tab->len += len;
}

void	nbr_wflags(t_parseflags *tab, char *str, size_t len)
{
	if (tab->check_zerojustify == '0' && tab->check_precision == FALSE)
		pad_zero(tab, str, len);
}