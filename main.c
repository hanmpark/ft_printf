/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 12:38:26 by hanmpark          #+#    #+#             */
/*   Updated: 2022/12/29 18:32:03 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"
#include <stdio.h>

int	main(void)
{
	int	i = 1;
	printf(" og = %d\n", printf("<%+06.7d>", i));
	//printf(" mf = %d\n", ft_printf("<%3d>", i));
	return (0);
}