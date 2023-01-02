/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hexadecimal.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 14:16:15 by hanmpark          #+#    #+#             */
/*   Updated: 2023/01/02 17:36:39 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <stdio.h>

static int	count_hexadecimal(long long nbr)
{
	int	count;

	count = 1;
	while (nbr / 16)
	{
		nbr /= 16;
		count++;
	}
	return (count);
}

void	print_x(t_parseflags *tab)
{
	long long	nbr;
	char		*hexadecimal;
	char		*str;
	int			count;
	int			len;

	nbr = va_arg(tab->args, long long);
	hexadecimal = "0123456789abcdef";
	count = count_hexadecimal(nbr);
	str = malloc((count + 1) * sizeof(char));
	str[count] = 0;
	while (count-- > 0)
	{
		str[count] = hexadecimal[nbr % 16];
		nbr /= 16;
	}
	if (nbr == 0 && tab->check_precision == TRUE && tab->precision == 0)
		len = 0;
	else
		len = (int)ft_strlen(str);
	if (tab->check_nbrflags == '#')
		len += 2;
	nbr_wflags(tab, str, FALSE, len);
	free(str);
}

void	print_xx(t_parseflags *tab)
{
	long long	nbr;
	char		*hexadecimal;
	char		*str;
	int			count;

	nbr = va_arg(tab->args, long long);
	hexadecimal = "0123456789ABCDEF";
	count = count_hexadecimal(nbr);
	str = malloc((count + 1) * sizeof(char));
	str[count] = 0;
	while (nbr && count-- > 0)
	{
		str[count] = hexadecimal[nbr % 16];
		nbr /= 16;
	}
	nbr_wflags(tab, str, FALSE, (int)ft_strlen(str));
	free(str);
}
