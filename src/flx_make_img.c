/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flx_make_img.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 18:22:01 by vicgarci          #+#    #+#             */
/*   Updated: 2022/12/06 15:26:53 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Felix.h"

t_flx_img	*flx_make_img(t_flx	*flx)
{
	t_flx_img	*img;

	img = malloc (sizeof(t_flx_img));
	if (img)
	{
		img->height = HEIGHT;
		img->width = WIDTH;
		img->context = flx->context;
		img->pixels = calloc (WIDTH * HEIGHT, sizeof(int32_t));
		if (!img->pixels)
			free(img);
	}
	return (img);
}
