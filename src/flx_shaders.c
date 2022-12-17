/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flx_shaders.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 13:01:16 by vicgarci          #+#    #+#             */
/*   Updated: 2022/12/17 14:47:59 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Felix.h"

static t_bool	load_src(char *path, char **src_vertex);

t_bool	flx_shaders(t_flx *flx)
{
	GLuint	vertex;
	GLuint	fragment;
	char	*src_vrt;
	char	*src_frag;

	ft_printf("SIG 6\n");
	if (load_src(PATH_FRAG, &src_frag) && load_src(PATH_VERTEX, &src_vrt))
	{
		vertex = glCreateShader(GL_VERTEX_SHADER);
		glShaderSource(vertex, 1, (const GLchar * const *)src_vrt, NULL);
		ft_printf("SIG 1\n");
		glCompileShader(vertex);
		fragment = glCreateShader(GL_FRAGMENT_SHADER);
		glShaderSource(fragment, 1, (const GLchar * const *)src_frag, NULL);
		glCompileShader(fragment);
		flx->shader_program = glCreateProgram();
		glAttachShader(flx->shader_program, vertex);
		glAttachShader(flx->shader_program, fragment);
		glLinkProgram(flx->shader_program);
		glDeleteShader(vertex);
		glDeleteShader(fragment);
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
		return (true);
	}
	ft_printf("SIG 9\n");
	return (false);
}

static t_bool	load_src(char *path, char **src_vertex)
{
	int		fd;

	ft_printf("SIG 8\n");
	fd = open(path, O_RDONLY);
	ft_printf("\nFD-> %d\n", fd);
	ft_printf("SIG 7\n");
	if (fd > 2 && ft_store_file(fd, src_vertex))
	{
		system("Leaks Felix");
		ft_printf("\n\n\n%s\n\n\n", *src_vertex);
		return (true);
	}
	close(fd);
	return (false);
}
