#ifndef _RT_H
# define _RT_H

# include <SDL.h>
# include "math/math.h"
# include "math/vectors.h"
# include "math/quaternions.h"
# include "math/matrices.h"

# include "utility/bool.h"
# include "utility/defines.h"
# include "utility/get_next_line.h"
# include "utility/errors.h"

# include "rt/transform.h"
# include "rt/raytrace.h"
# include "rt/objects.h"
# include "rt/camera.h"



//#include "utility/bool.h"
//#include "math/vectors.h"
//#include "math/matrices.h"
//#include "math/math.h"
//#include "math/quaternions.h"
//#include "rt/camera.h"
//#include "rt/objects.h"
//#include "rt/raytrace.h"
//#include "rt/transform.h"
//#include "utility/bool.h"
//#include "utility/defines.h"
//#include "utility/errors.h"
//#include "libft.h"
//#include "utility/get_next_line.h"

/*
** Basic SDL2 variables
** key_state - current key code
*/
typedef struct		s_sdl
{
	SDL_Window		*window;
	SDL_Renderer	*renderer;
	SDL_Event		event;
	const Uint8		*key_state;
	SDL_bool		is_mouse_cap;
	t_vec2			mouse_rel_pos;
	t_vec2			mouse_angle;
}					t_sdl;

/*
** Window draw
** screen - texture on which drawing is happening
** draw_buf - content of draw buffer is updated on to the texture
** each redraw call.
** pitch - the length of a row of pixels in bytes
** offset - draw location in draw buffer
*/
typedef struct		s_win
{
	SDL_Texture		*screen;
	Uint8			*draw_buf;
	int				pitch;
	size_t			offset;
	Uint16			width;
	Uint16			height;
	char			*title;
}					t_win;

/*
** Scene
*/
typedef struct		s_scene
{
	t_obj3d			**objects;
	t_material		**materials;
	t_light			**lights;
	t_ray			ray;
	t_cam			cam;
	t_vec2			point;
	int				objs_n;
	int				mats_n;
	int				lits_n;
}					t_scene;

/*
** Support struct for calculation
*/
typedef struct		s_calc
{
	t_rgbap			color;
	t_rgba			pixel_color;
	int				level;
	float			coef;
	int				cur_obj;
	t_vec3			intersect_normal;
	t_vec3			new_start;
	t_material		cur_mat;
	int				material_n;
	float			reflect;
	t_vec3			tmp;
	int				i;
	int				n;
}					t_calc;

/*
** Parser struct
*/
typedef	struct		s_pars
{
	int				fd;
	int				n;
	char			**av;
	char			*line;
}					t_pars;


typedef struct		s_time
{
	uint32_t		oldtime;
	uint32_t		curtime;
	double			ftime;
	char			fps[4];
	int				fps_counter;
}					t_time;

/*
** Main struct.
** av - ./RTv1 arguments
*/
typedef struct		s_rt
{
	char			**av;
	t_sdl			*sdl;
	t_win			*win;
	t_scene			*scene;
	t_calc			*calc;
	t_pars			*pars;
	t_time			delta;
}					t_rt;

/*
** Errors
*/
void				rtv_error(t_error error_code);
void				print_error_and_exit(const char *error_text, Uint8 sdl);
/*
** Parser
*/
t_bool				parser_core(t_rt *r);
t_bool				parse_scene(t_rt *r);
t_bool				parse_camera(t_rt *r);
t_bool				parse_lights(t_rt *r);
t_bool				parse_materials(t_rt *r);
t_bool				parse_objects(t_rt *r);
t_bool				parse_plane(t_rt *r, int i);
t_bool				parse_sphere(t_rt *r, int i);
t_bool				parse_cylinder(t_rt *r, int i);
t_bool				parse_cone(t_rt *r, int i);
void				open_file(t_rt *r);
void				close_file(t_rt *r);
void				gnl_error(t_rt *r, int i);
float				ft_atof(const char *s);
t_bool				get_str(t_rt *r);
t_bool				parse_vector(t_rt *r, t_vec3 *v, int min, int max);
t_bool				parse_number(t_rt *r, float *n, int min, int max);
t_bool				parse_color(t_rt *r, t_rgbap *c, float min, float max);
t_bool				parse_float_number(t_rt *r, float *n, float mi, float ma);
t_bool				check_line(t_rt *r, const char *s);
t_bool				valid_material(t_rt *r, Uint16 *material, int mi, int ma);
/*
** RTv1
*/
void				ft_noise(t_rt *rt);
t_rt				*rt_init(char **av);
void				rt_loop(t_rt *rt);
void				rt_quit(t_rt *rt);
/*
** Raycast
*/
void				raytrace(t_rt *rt);
t_bool				normal_of_intersect(t_vec3 *normal, t_vec3 *new_start,
					t_obj3d **objects, int cur_obj);
t_bool				object_intersect(t_rt *rt, t_ray *r, int *cur_obj,
					t_vec3 *new_start);
void				calculate_light(t_rt *rt);
void				calculate_reflection(t_rt *rt);
/*
** Scene
*/
void				init_camera(t_rt *r);
void				new_scene(t_rt *r, int n_of_lights,
					int n_of_mats, int n_of_objs);
void				create_sceen_one(t_scene *scene);
t_bool				create_scene(t_rt *r);
t_obj3d				*new_object(t_obj_type object_type);
/*
** Keyboard
*/
void				keyboard_core(t_rt *rt);
/*
** Mouse
*/
void				mouse_core(t_rt *rt);
/*
** Window
*/
void				create_window(t_rt *rtv, Uint16 wdth, Uint16 hght,
					const char *title);
void				clear_window(t_rt *rtv);
void				render_present(t_rt *rtv);
void				ft_draw_pixel(Uint16 x, Uint16 y, t_rgba *color,
					Uint8 *draw_buffer);

#endif
