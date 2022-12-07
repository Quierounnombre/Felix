/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Felix.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 11:43:30 by vicgarci          #+#    #+#             */
/*   Updated: 2022/12/07 17:42:57 by vicgarci         ###   ########.fr       */
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

extern const char	*g_vert_shader;
extern const char	*g_frag_shader;

typedef struct s_felix
{
	GLFWwindow	*window;
	void		*context;
	int32_t		widht;
	int32_t		height;
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
void	flx_main_loop(GLFWwindow *window);
//void	flx_putimg(GLFWwindow *window, GLFWimage *image, GLuint x, GLuint y);
t_flx	*flx_init(void);
void	flx_terminate(t_flx *flx);

#endif