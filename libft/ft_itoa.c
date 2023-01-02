/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 10:03:35 by hanmpark          #+#    #+#             */
/*   Updated: 2023/01/02 14:10:05 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_len(unsigned long long n)
{
	unsigned long long	nbr;
	int					len;

	nbr = 1;
	len = 0;
	if (n < 0)
	{
		n *= -1;
		len++;
	}
	if (n == 0)
		len++;
	while (n / nbr && n != 0)
	{
		nbr *= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(unsigned long long n)
{
	char	*a;
	int		i;

	i = count_len(n);
	a = malloc((i + 1) * sizeof(char));
	if (!a)
		return (0);
	if (n < 0)
	{
		a[0] = '-';
		n *= -1;
	}
	a[i] = 0;
	while (i-- > 0)
	{
		if (i == 0 && n % 10 == 0 && n < 0)
			break ;
		a[i] = n % 10 + '0';
		n /= 10;
	}
	return (a);
}
