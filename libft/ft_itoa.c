/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 10:03:35 by hanmpark          #+#    #+#             */
/*   Updated: 2022/11/23 10:38:12 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_len(int n)
{
	int		len;
	long	nbr;

	len = 0;
	nbr = 1;
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

char	*ft_itoa(int n)
{
	char	*a;
	int		i;
	long	nbr;

	i = count_len(n);
	nbr = n;
	a = malloc((i + 1) * sizeof(char));
	if (!a)
		return (0);
	if (nbr < 0)
	{
		a[0] = '-';
		nbr *= -1;
	}
	a[i] = 0;
	while (i-- > 0)
	{
		if (i == 0 && nbr % 10 == 0 && n < 0)
			break ;
		a[i] = nbr % 10 + '0';
		nbr /= 10;
	}
	return (a);
}
/*#include <stdio.h>
int	main()
{
	int	n = -2147483648;

	printf("%s\n", ft_itoa(n));
	return (0);
}*/