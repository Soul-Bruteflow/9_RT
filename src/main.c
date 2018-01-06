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
	t_rt	*r;


	if (ac == 2)
	{
		r = rt_init(av);
		if (!(parser_core(r)))
			rtv_error(parse_error);
		init_camera(r);
		init_controls(r);
		create_window(r, WIDTH, HEIGHT, "RT\0");
		rt_loop(r);
	}
	else
		rtv_error(usage_error);
}
