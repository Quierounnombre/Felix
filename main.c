/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 11:54:19 by vicgarci          #+#    #+#             */
/*   Updated: 2022/11/30 12:34:04 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Felix.h"

int	main(void)
{
	if (glfwInit())
	{
		ft_printf("ABRO");
		if (open_window())
		{
			ft_printf("HOLA");

		}
	}
	glfwTerminate();
}
