/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pthreads.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vholovin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 21:01:24 by vholovin          #+#    #+#             */
/*   Updated: 2018/03/30 21:01:37 by vholovin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void			pthreads(t_rt *rt)
{
	pthread_t	th[NB_THREAD];
	t_rt_pth	rt_pth[NB_THREAD];
	void		*ret;
	int			i;

	i = -1;
	while (++i < NB_THREAD)
	{
		rt_pth[i].i = i;
		rt_pth[i].rt = ft_copy(rt);
		rt_pth[i].rt->sdl = rt->sdl;
		rt_pth[i].rt->win = rt->win;
		pthread_create(&th[i], NULL, raytrace, &rt_pth[i]);
	}
	i = -1;
	while (++i < NB_THREAD)
	{
		(void)pthread_join(th[i], &ret);
		ft_free(rt_pth[i].rt);
	}
}
