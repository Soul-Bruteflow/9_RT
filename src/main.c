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

	t_rt	*rt;

	if (ac == 2)
	{
		rt = rt_init(av);
		if (!(parser_core(rt)))
			rtv_error(parse_error);
		init_camera(rt);
		init_controls(rt);
		create_window(rt, WIDTH, HEIGHT, "RT\0");
		rt_loop(rt);
	}
	else
		rtv_error(usage_error);
}
