/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 15:55:33 by vicgarci          #+#    #+#             */
/*   Updated: 2022/12/01 16:27:24 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Felix.h"

static void		init_struct(flx_t	*flx);
static t_bool	init_window(flx_t	*flx);

flx_t	*flx_init(void)
{
	flx_t	*flx;
	
	flx = malloc(sizeof(flx));
	if (flx)
	{
		init_struct(flx);
		if (glfwInit())
		{
			if (init_window(flx))
				return (flx);
			glfwTerminate();
		}
		free(flx);
	}
	return (NULL);
}

static void init_struct(flx_t *flx)
{
	flx->height = WIDTH;
	flx->widht = HEIGHT;
	flx->name = WINDOW_NAME;
}

static t_bool	init_window(flx_t *flx)
{
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	flx->window = glfwCreateWindow(HEIGHT, WIDTH, WINDOW_NAME, NULL, NULL);
	if (flx->window == NULL)
	{
		glfwTerminate();
		return (false);
	}
	glfwMakeContextCurrent(flx->window);
	glfwGetFramebufferSize(flx->window, &flx->height, &flx->widht);
	gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
	return (true);
}
