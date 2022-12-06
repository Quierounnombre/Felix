/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 15:55:33 by vicgarci          #+#    #+#             */
/*   Updated: 2022/12/06 19:30:28 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Felix.h"

static void		init_struct(t_flx	*flx);
static t_bool	init_window(t_flx	*flx);
static t_bool	check_params(void);

t_flx	*flx_init(void)
{
	t_flx	*flx;

	if (check_params())
	{
		flx = malloc(sizeof(flx));
		if (flx)
		{
			init_struct(flx);
			if (glfwInit())
			{
				if (init_window(flx))
				{
					return (flx);
				}
				glfwTerminate();
			}
			free(flx);
		}
	}
	return (NULL);
}

static void	init_struct(t_flx *flx)
{
	flx->height = WIDTH;
	flx->widht = HEIGHT;
	flx->name = WINDOW_NAME;
	glActiveTexture(GL_TEXTURE0);
	glGenVertexArrays(1, &(flx->vao));
	glGenBuffers(1, &(flx->vbo));
	glBindVertexArray(flx->vao);
	glBindBuffer(GL_ARRAY_BUFFER, flx->vbo);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(t_vertex), NULL);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(t_vertex),
		(void *)(sizeof(float) * 3));
	glEnableVertexAttribArray(1);
	glVertexAttribIPointer(2, 1, GL_BYTE, sizeof(t_vertex),
		(void *)(sizeof(float) * 5));
	glEnableVertexAttribArray(2);
	glEnable(GL_BLEND);
	glEnable(GL_DEPTH_TEST);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}

static t_bool	check_params(void)
{
	if (WIDTH >= INT16_MAX)
		return (false);
	else if (HEIGHT >= INT16_MAX)
		return (false);
	return (true);
}

static t_bool	init_window(t_flx *flx)
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
	return (true);
}
