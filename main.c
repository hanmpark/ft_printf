/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 12:38:26 by hanmpark          #+#    #+#             */
/*   Updated: 2022/12/28 02:24:25 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf_bonus.h"
#include <stdio.h>

int	main(void)
{
	char	str[] = "Hello World !";
	//int		x = -5;
	//printf("count: %d\n", printf("og: %-p%%\n", &str));
	//ft_printf("\n");
	//ft_printf("count: %d\n", ft_printf("mf: %p%%\n", str));
	//printf(" og = %d\n", printf("<%015s>", str));
	ft_printf(" mf = %d\n", ft_printf("<I don't know man %s>", str));
	return (0);
}