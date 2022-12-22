/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 12:38:26 by hanmpark          #+#    #+#             */
/*   Updated: 2022/12/22 15:22:09 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"
#include <stdio.h>

int	main(void)
{
	char	str[] = "hello";
	int		x = 423443;
	//printf("count: %d\n", printf("og: %-p%%\n", &str));
	//ft_printf("\n");
	//ft_printf("count: %d\n", ft_printf("mf: %p%%\n", &str));
	printf("og = %d\n", printf("<%-.6s>%%% %%%%", str));
	ft_printf("mf = %d\n", ft_printf("<%.-7s>%%% %%%%", str));
	return (0);
}