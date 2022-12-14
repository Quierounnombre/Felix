/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flx_shaders.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 13:01:16 by vicgarci          #+#    #+#             */
/*   Updated: 2022/12/14 13:42:57 by vicgarci         ###   ########.fr       */
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

	flx->shader_program = glCreateProgram();
	if (flx->shader_program && load_src(PATH_FRAG, &src_frag)
		&& load_src(PATH_VERTEX, &src_vrt))
	{
		vertex = glCreateShader(GL_VERTEX_ARRAY);
		glShaderSource(vertex, 1, (const GLchar * const *)src_vrt, NULL);
		glCompileShader(vertex);
		fragment = glCreateShader(GL_FRAGMENT_SHADER);
		glShaderSource(fragment, 1, (const GLchar * const *)src_frag, NULL);
		glCompileShader(fragment);
		glAttachShader(flx->shader_program, vertex);
		glAttachShader(flx->shader_program, fragment);
		glLinkProgram(flx->shader_program);
		glDeleteShader(vertex);
		glDeleteShader(fragment);
		return (true);
	}
	return (false);
}

static t_bool	load_src(char *path, char **src_vertex)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd)
	{
		*src_vertex = ft_get_next_line(fd);
		if (*src_vertex)
			return (true);
	}
	return (false);
}
