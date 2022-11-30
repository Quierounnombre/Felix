/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 11:57:08 by vicgarci          #+#    #+#             */
/*   Updated: 2022/11/30 12:50:28 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Felix.h"

t_bool	open_window(void)
{
	GLFWwindow	*window;
	int			width;
	int			height;

	height = 600;
	width = 600;
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
	window = glfwCreateWindow(height, width, "My Title", NULL, NULL);
	if (!window)
		return (false);
	glfwMakeContextCurrent(window);
	glfwGetFramebufferSize(window, &width, &height);
	while (!glfwWindowShouldClose(window))
	{
		ft_printf("HOLA\n");
		//glViewport(0, 0, width, height);
	}
	return (true);
}
