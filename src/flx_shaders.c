/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flx_shaders.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 13:01:16 by vicgarci          #+#    #+#             */
/*   Updated: 2022/12/22 20:30:23 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Felix.h"

static t_bool	compilation_sucesful(GLuint	to_be_checked);
static t_bool	compile_shaders(char *path, GLuint *shader);
static t_bool	make_program(GLuint *shader_program);

t_bool	flx_shaders(t_flx *flx)
{

	ft_printf("SIG 6\n");
	if (make_program(&flx->shader_program))
	{
		GLfloat	vertices[] =
		{
			-0.5f, -0.5f * (float)(sqrt(3)) / 3, 0.0f, // Lower left corner
			0.5f, -0.5f * (float)(sqrt(3)) / 3, 0.0f, // Lower right corner
			0.0f, 0.5f * (float)(sqrt(3)) * 2 / 3, 0.0f // Upper corner
		};
		glGenVertexArrays(1, &flx->vao);
		glGenBuffers(1, &flx->vbo);
		glBindVertexArray(flx->vao);
		glBindBuffer(GL_ARRAY_BUFFER, flx->vbo);
		glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
		glEnableVertexAttribArray(0);
		glBindBuffer(GL_ARRAY_BUFFER, 0);
		glBindVertexArray(0);
		ft_printf("SIG 11\n");
		return (true);
	}
	ft_printf("SIG 9\n");
	return (false);
}

static t_bool	make_program(GLuint *shader_program)
{
	GLuint	vertex;
	GLuint	fragment;

	vertex = glCreateShader(GL_VERTEX_SHADER);
	fragment = glCreateShader(GL_FRAGMENT_SHADER);
	if (!vertex || !fragment)
		return (false);
	if (!compile_shaders(PATH_VERTEX, &vertex)
		|| !compile_shaders(PATH_VERTEX, &fragment))
		return (false);
	*shader_program = glCreateProgram();
	if (!(*shader_program))
		return (false);
	glAttachShader(*shader_program, vertex);
	glAttachShader(*shader_program, fragment);
	glLinkProgram(*shader_program);
	glDeleteShader(vertex);
	glDeleteShader(fragment);
	return (true);
}

static t_bool	compile_shaders(char *path, GLuint *shader)
{
	int		fd;
	char	*src;

	fd = open(path, O_RDONLY);
	if (fd > 2 && ft_store_file(fd, &src))
	{
		close(fd);
		glShaderSource(*shader, 1, (const GLchar * const *)&src, NULL);
		glCompileShader(*shader);
		free(src);
		ft_printf("SIG 7\n");
		if (compilation_sucesful(*shader))
			return (true);
	}
	close(fd);
	return (false);
}

static t_bool	compilation_sucesful(GLuint	to_be_checked)
{
	int		succes;
	char	log[512];

	succes = 0;
	glGetShaderiv(to_be_checked, GL_COMPILE_STATUS, &succes);
	if (!succes)
	{
		glGetShaderInfoLog(to_be_checked, 512, NULL, log);
		ft_printf("\n--------ERROR COMPILATION SHADER--------\n%s\n\n");
		return (false);
	}
	return (true);
}
