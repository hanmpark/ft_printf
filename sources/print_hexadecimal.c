/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hexadecimal.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 14:16:15 by hanmpark          #+#    #+#             */
/*   Updated: 2022/12/31 14:21:24 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <stdio.h>

int	count_hexadecimal(long long nbr)
{
	int	count;

	count = 0;
	while (nbr / 16)
	{
		nbr /= 16;
		count++;
	}
	return (count);
}

void	print_hexadecimal(t_parseflags *tab)
{
	long long	nbr;
	char		*hexadecimal;
	char		*str;
	int			count;

	nbr = va_arg(tab->args, long long);
	hexadecimal = "0123456789abcdef";
	count = count_hexadecimal(nbr);
	str = malloc((count + 1) * sizeof(char));
	while (count-- > 0)
	{
		str[count] = hexadecimal[nbr % 16];
		nbr /= 16;
	}
	if (tab->check_nbrflags == '#')
		tab->len += write(1, "0x", 2);
	else if (tab->check_nbrflags == ' ')
	nbr_wflags(tab, str, FALSE);
	free(str);
}