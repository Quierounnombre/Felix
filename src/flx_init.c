/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 15:55:33 by vicgarci          #+#    #+#             */
/*   Updated: 2022/12/07 17:42:52 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Felix.h"

static void		init_struct(t_flx	*flx);
static t_bool	init_window(t_flx	*flx);
static t_bool	check_params(void);
static t_bool	init_shaders(t_flx *flx);

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
				if (init_window(flx) && init_shaders(flx))
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

static t_bool	init_shaders(t_flx *flx)
{
	GLuint	vertex_shader;
	GLuint	fragment_shader;

	flx->shader_program = glCreateProgram();
	if (flx->shader_program)
	{
		vertex_shader = glCreateShader(GL_VERTEX_ARRAY);
		glShaderSource(vertex_shader, 1, &g_vert_shader, NULL);
		glCompileShader(vertex_shader);
		fragment_shader = glCreateShader(GL_FRAGMENT_SHADER);
		glShaderSource(fragment_shader, 1, &g_frag_shader, NULL);
		glCompileShader(fragment_shader);
		glAttachShader(flx->shader_program, vertex_shader);
		glAttachShader(flx->shader_program, fragment_shader);
		glLinkProgram(flx->shader_program);
		glDeleteShader(vertex_shader);
		glDeleteShader(fragment_shader);
		return (true);
	}
	return (false);
}
