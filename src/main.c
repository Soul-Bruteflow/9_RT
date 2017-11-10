/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvlad <mvlad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/08 12:13:15 by mvlad             #+#    #+#             */
/*   Updated: 2017/10/09 15:07:08 by mvlad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int		main(int ac, char **av)
{
	t_rt	*rtv;

	if (ac == 2)
	{
		rtv = rt_init(av);
		if (!(parser_core(rtv)))
			rtv_error(parse_error);
		init_camera(rtv);
		create_window(rtv, WIDTH, HEIGHT, "RT\0");
//		clear_window(rtv);
//		raytrace(rtv);
//		render_present(rtv);
		rt_loop(rtv);
	}
	else
		rtv_error(usage_error);
}
