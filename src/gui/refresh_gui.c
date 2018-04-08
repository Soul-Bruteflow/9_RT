/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   refresh_gui.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vholovin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 22:07:49 by vholovin          #+#    #+#             */
/*   Updated: 2018/03/31 22:07:51 by vholovin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void	anti_norm_2(t_rt *rt, char *tmp[27])
{
	tmp[21] = ft_strjoin(tmp[20], "Texture:      T        ");
	if (rt->scene->status_texture)
		tmp[22] = ft_strjoin(tmp[21], "True\n");
	else
		tmp[22] = ft_strjoin(tmp[21], "False\n");
	free(tmp[20]);
	free(tmp[21]);
	tmp[23] = ft_strjoin(tmp[22], "Shadow:      ;         ");
	if (rt->scene->status_shadow)
		tmp[24] = ft_strjoin(tmp[23], "True\n");
	else
		tmp[24] = ft_strjoin(tmp[23], "False\n");
	free(tmp[22]);
	free(tmp[23]);
	tmp[25] = ft_strjoin(tmp[24], "Glossy:        '         ");
	if (rt->scene->status_glossy)
		tmp[26] = ft_strjoin(tmp[25], "True\n");
	else
		tmp[26] = ft_strjoin(tmp[25], "False\n");
	free(tmp[24]);
	free(tmp[25]);
}

static void	anti_norm_1(t_rt *rt, char *tmp[27])
{
	tmp[9] = ft_strjoin(tmp[8], "Reflect:       - +        ");
	tmp[10] = ft_itoa(rt->scene->max_level_reflection);
	tmp[11] = ft_strjoin(tmp[9], tmp[10]);
	tmp[12] = ft_strjoin(tmp[11], "\n");
	free(tmp[8]);
	free(tmp[9]);
	free(tmp[10]);
	free(tmp[11]);
	tmp[13] = ft_strjoin(tmp[12], "Refract:      [ ]         ");
	tmp[14] = ft_itoa(rt->scene->max_level_transparent);
	tmp[15] = ft_strjoin(tmp[13], tmp[14]);
	tmp[16] = ft_strjoin(tmp[15], "\n");
	free(tmp[12]);
	free(tmp[13]);
	free(tmp[14]);
	free(tmp[15]);
	tmp[17] = ft_strjoin(tmp[16], "Anti-Alias:   <  >       ");
	tmp[18] = ft_itoa(rt->scene->aa);
	tmp[19] = ft_strjoin(tmp[17], tmp[18]);
	tmp[20] = ft_strjoin(tmp[19], "-x\n");
	free(tmp[16]);
	free(tmp[17]);
	free(tmp[18]);
	free(tmp[19]);
}

static void	anti_norm_0(t_rt *rt, char *tmp[27])
{
	tmp[0] = ft_strjoin("Name:       Key:    Status:\n", "Close/Open: I\n");
	tmp[1] = ft_strjoin(tmp[0], "Exit:           ESC\n");
	free(tmp[0]);
	tmp[2] = ft_strjoin(tmp[1], "Prt Sc:        P\n");
	free(tmp[1]);
	tmp[3] = ft_strjoin(tmp[2], "Movement: W,S,A,D\n");
	free(tmp[2]);
	tmp[4] = ft_strjoin(tmp[3], "Rotate:    Up,Dwn,Lft,Rght\n\n");
	free(tmp[3]);
	tmp[5] = ft_strjoin(tmp[4], "Color:         C          ");
	tmp[6] = ft_itoa(rt->scene->status_color);
	tmp[7] = ft_strjoin(tmp[5], tmp[6]);
	tmp[8] = ft_strjoin(tmp[7], "\n");
	free(tmp[4]);
	free(tmp[5]);
	free(tmp[6]);
	free(tmp[7]);
}

static void	get_info_text(t_rt *rt, char **buff)
{
	char	*tmp[27];

	anti_norm_0(rt, tmp);
	anti_norm_1(rt, tmp);
	anti_norm_2(rt, tmp);
	*buff = ft_strnew(ft_strlen(tmp[26]));
	*buff = ft_strcat(*buff, tmp[26]);
	free(tmp[26]);
}

void		refresh_gui(t_rt *r)
{
	char		*buff;
	SDL_Surface	*sur_message;

	buff = NULL;
	get_info_text(r, &buff);
	sur_message = TTF_RenderText_Blended_Wrapped(r->font, buff,
		r->fcolor, 180);
	free(buff);
	r->tex_message = SDL_CreateTextureFromSurface(r->sdl->renderer,
			sur_message);
	SDL_FreeSurface(sur_message);
	SDL_QueryTexture(r->tex_message, NULL, NULL,
			&r->message_rect.w, &r->message_rect.h);
}
