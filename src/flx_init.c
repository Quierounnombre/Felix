/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 15:55:33 by vicgarci          #+#    #+#             */
/*   Updated: 2022/12/15 14:08:09y vicgarci         ###   ########.fr       */
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
		if (glfwInit())
		{
			flx = malloc(sizeof(flx));
			if (flx)
			{
				init_struct(flx);
				if (init_window(flx))
				{
					return (flx);
				}
				free(flx);
			}
			glfwTerminate();
		}
	}
	return (NULL);
}

static void	init_struct(t_flx *flx)
{
	flx->height = HEIGHT;
	flx->widht = WIDTH;
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
	ft_printf("SIG 2\n");
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	flx->window = glfwCreateWindow(flx->height, flx->widht, flx->name,
			NULL, NULL);
	if (flx->window == NULL)
	{
		ft_printf("No se ha podido crear una ventana\n");
		glfwTerminate();
		return (false);
	}
	ft_printf("SIG 3\n");
	glfwMakeContextCurrent(flx->window);
	glfwGetFramebufferSize(flx->window, &flx->height, &flx->widht);
	ft_printf("SIG 4\n");
	ft_printf("SIG 5\n");
	gladLoadGL();
	glViewport(0, 0, flx->widht, flx->height);
	if (!flx_shaders(flx))
		return (false);
	return (true);
}
