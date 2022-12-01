/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 11:54:19 by vicgarci          #+#    #+#             */
/*   Updated: 2022/12/01 16:41:28 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Felix.h"

int	main(void)
{
	flx_t	*flx;

	flx = flx_init();
	if (flx)
	{
		if (flx_open_window(flx))
		{
			//flx_putimg();
			//flx_main_loop(win);
		}
	}
	flx_terminate(flx);
	system ("Leaks Felix");
}
