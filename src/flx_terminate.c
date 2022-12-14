/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flx_terminate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 16:37:25 by vicgarci          #+#    #+#             */
/*   Updated: 2022/12/14 17:59:41 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Felix.h"

void	flx_terminate(t_flx *flx)
{
	glDeleteVertexArrays(1, &flx->vao);
	glDeleteBuffers(1, &flx->vbo);
	glDeleteProgram(flx->shader_program);
	if (flx->window)
		free(flx->window);
	free(flx);
	glfwTerminate();
}
