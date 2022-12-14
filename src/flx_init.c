/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 15:55:33 by vicgarci          #+#    #+#             */
/*   Updated: 2022/12/14 13:33:49 by vicgarci         ###   ########.fr       */
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
				if (init_window(flx) && flx_shaders(flx))
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
