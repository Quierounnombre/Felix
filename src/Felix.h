/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Felix.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 11:43:30 by vicgarci          #+#    #+#             */
/*   Updated: 2022/12/02 18:36:03 by vicgarci         ###   ########.fr       */
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

# ifndef HEIGHT
#  define HEIGHT 800
# endif

# ifndef WIDTH
#  define WIDTH 800
# endif

typedef	struct felix
{
	GLFWwindow	*window;
	void		*context;
	int			widht;
	int			height;
	double		delta_time;
	char		*name;
}				flx_t;

typedef struct image
{
	GLFWimage	*img;
	int			width;
	int			height;
	void		*context;
	uint8_t		pixels;
}				flx_img;

void	flx_open_window(void);
void	flx_main_loop(GLFWwindow *window);
//void	flx_putimg(GLFWwindow *window, GLFWimage *image, GLuint x, GLuint y);
flx_t	*flx_init(void);
void 	flx_terminate(flx_t *flx);

#endif