/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 11:54:19 by vicgarci          #+#    #+#             */
/*   Updated: 2022/12/01 13:59:33 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Felix.h"

int	main(void)
{
	GLFWwindow	*win;

	if (glfwInit())
	{
		ft_printf("ABRO");
		if (flx_open_window(800, 800, &win))
		{
			flx_putimg(win);
			//flx_main_loop(win);
		}
	}
	glfwTerminate();
	system ("Leaks Felix");
}
