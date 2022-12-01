/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flx_open_window.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 11:57:08 by vicgarci          #+#    #+#             */
/*   Updated: 2022/12/01 13:19:00 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Felix.h"

t_bool	flx_open_window(int width, int height, GLFWwindow **window)
{
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	*window = glfwCreateWindow(height, width, WINDOW_NAME, NULL, NULL);
	if (*window == NULL)
	{
		glfwTerminate();
		return (false);
	}
	glfwMakeContextCurrent(*window);
	glfwGetFramebufferSize(*window, &width, &height);
	gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);

	// TEMP

	GLuint VertexArrayID;
	glGenVertexArrays(1, &VertexArrayID);
	glBindVertexArray(VertexArrayID);
	return (true);
}
