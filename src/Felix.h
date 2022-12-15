/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Felix.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 11:43:30 by vicgarci          #+#    #+#             */
/*   Updated: 2022/12/15 15:26:21 by vicgarci         ###   ########.fr       */
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

# ifndef PATH_VERTEX
#  define PATH_VERTEX "../shaders/default.vertex"
# endif

# ifndef PATH_FRAG
#  define PATH_FRAG "../shaders/default.frag"
# endif

typedef struct s_felix
{
	GLFWwindow	*window;
	void		*context;
	int			widht;
	int			height;
	double		delta_time;
	GLuint		shader_program;
	GLuint		vao;
	GLuint		vbo;
	char		*name;
}				t_flx;

typedef struct vertex
{
	float	x;
	float	y;
	float	z;
	float	u;
	float	v;
	int8_t	tex;
}			t_vertex;

typedef struct s_image
{
	unsigned int	width;
	unsigned int	height;
	void			*context;
	uint8_t			*pixels;
}				t_flx_img;

void	flx_open_window(void);
void	flx_main_loop(t_flx *flx);
//void	flx_putimg(GLFWwindow *window, GLFWimage *image, GLuint x, GLuint y);
void	flx_terminate(t_flx *flx);

/*-----INIT-----*/
t_flx	*flx_init(void);
t_bool	flx_shaders(t_flx *flx);

#endif