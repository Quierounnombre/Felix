/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 11:54:19 by vicgarci          #+#    #+#             */
/*   Updated: 2022/12/01 16:49:38 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Felix.h"

int	main(void)
{
	flx_t	*flx;

	flx = flx_init();
	if (flx)
	{
		flx_open_window();
		flx_main_loop(flx->window);
		//flx_putimg();
	}
	flx_terminate(flx);
	system ("Leaks Felix");
}
