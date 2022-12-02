/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flx_make_img.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 18:22:01 by vicgarci          #+#    #+#             */
/*   Updated: 2022/12/02 18:44:30 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Felix.h"

flx_img	*flx_make_img(flx_t	*flx)
{
	flx_img	*img;

	img = malloc (sizeof(flx_img));
	if (img)
	{
		img->height = HEIGHT;
		img->width = WIDTH;
		img->context = flx->context;
		img->img = ft_calloc(1, sizeof())
	}
}