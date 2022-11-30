/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Felix.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 11:43:30 by vicgarci          #+#    #+#             */
/*   Updated: 2022/11/30 16:59:21 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FELIX_H
# define FELIX_H

# include "../libft_def/libftprintf.h"
# include "../glad/glad.h"
# include "../glfw_build/src/glfw3.h"

# ifndef WINDOW_NAME
#  define WINDOW_NAME "Felix"
# endif

static GLfloat g_vertex_buffer_data[] = {
   -1.0f, -1.0f, 0.0f,
   1.0f, -1.0f, 0.0f,
   0.0f,  1.0f, 0.0f,
};

t_bool	flx_open_window(int width, int height, GLFWwindow **window);
void	flx_main_loop(GLFWwindow *window);
void	flx_putimg(void);

#endif