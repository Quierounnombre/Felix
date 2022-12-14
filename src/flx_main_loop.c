/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flx_main_loop.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 13:49:08 by vicgarci          #+#    #+#             */
/*   Updated: 2022/12/14 18:06:37 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Felix.h"

void	flx_main_loop(t_flx *flx)
{
	glClearColor(255, 0, 0, 1);
	glClear(GL_COLOR_BUFFER_BIT);
	while (!glfwWindowShouldClose(flx->window))
	{
		glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		glUseProgram(flx->shader_program);
		glBindVertexArray(flx->vao);
		glDrawArrays(GL_TRIANGLES, 0, 3);
		glfwSwapBuffers(flx->window);
		glfwPollEvents();
		//flx_putimg();
	}
}
