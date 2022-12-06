/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flx_putimg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 16:11:25 by vicgarci          #+#    #+#             */
/*   Updated: 2022/12/06 19:25:25 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Felix.h"

void	flx_putimg(t_flx *flx, t_flx_img *img, GLuint x, GLuint y)
{
	if (flx && img)
	{
		glBindBuffer(GL_ARRAY_BUFFER, flx->vbo);
		glfwSwapBuffers(flx->window);
	}
}
