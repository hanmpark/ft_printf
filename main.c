/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 10:56:47 by hanmpark          #+#    #+#             */
/*   Updated: 2022/11/25 11:00:35 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <stdio.h>
int	main(int ac, char **av)
{
	int		countc;
	int		countcog;
	char	c = 'N';
	char	str[] = "j'adore la vie";
	int		d = 18;

	if (!(ac == 2))
	{
		printf("!!NO PARAMETERS!!");
		return (0);
	}
	else if (av[1][0] == 'c')
	{
		countc = ft_printf("MF:%c\n", c);
		countcog = printf("OG:%c\n", c);
	}
	else if (av[1][0] == 's')
	{
		countc = ft_printf("MF:%s\n", str);
		countcog = printf("OG:%s\n", str);
	}
	else if (av[1][0] == 'd')
	{
		countc = ft_printf("MF:%d\n", d);
		countcog = printf("OG:%d\n", d);
	}
	printf("MF count:%d\nOG count:%d\n", countc, countcog);
	return (0);
}