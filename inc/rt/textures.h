/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vholovin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 15:25:55 by vholovin          #+#    #+#             */
/*   Updated: 2018/04/03 15:25:57 by vholovin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEXTURES_H
# define TEXTURES_H

# include <SDL_surface.h>

typedef struct		s_texture
{
	t_bool			status;
	SDL_Surface		*map;
	Uint8			*map_buf;
	Uint8			bpp;
	t_vec3			offset;
	t_vec3			scale;
}					t_texture;

#endif
