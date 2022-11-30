/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flx_open_window.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 11:57:08 by vicgarci          #+#    #+#             */
/*   Updated: 2022/11/30 13:58:48 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Felix.h"

t_bool	flx_open_window(int width, int height, GLFWwindow **window)
{
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
	*window = glfwCreateWindow(height, width, "My Title", NULL, NULL);
	if (*window == NULL)
	{
		glfwTerminate();
		return (false);
	}
	glfwMakeContextCurrent(*window);
	glfwGetFramebufferSize(*window, &width, &height);
	gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
	return (true);
}
