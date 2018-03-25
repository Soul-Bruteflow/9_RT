#include "rt.h"

void	create_background(t_rt *r)
{
	r->img = IMG_LoadTexture(r->sdl->renderer, "./res/backgound_info.png");
	SDL_QueryTexture(r->img, NULL, NULL, &r->w, &r->h);
	r->texr.x = 10;
	r->texr.y = (HEIGHT - r->h) - 10;
	r->texr.w = r->w * 1;
	r->texr.h = r->h * 1;
}

void	create_info_text(t_rt *r)
{
	TTF_Init();
	r->font = TTF_OpenFont("./res/Fontin-Regular.ttf", 18);
	r->fcolor.r = 255;
	r->fcolor.g = 255;
	r->fcolor.b = 255;
	r->message_rect.x = 27;
	r->message_rect.y = (HEIGHT - r->h) + 35;
	r->sur_message = TTF_RenderText_Blended_Wrapped(r->font,
	"Close/Open: I        "
	"Escape: ESC          "
	"Print Screen: P      "
	"Color Filter: C      "
	"Movement: W, A, S, D "
	"Reflection: -=       "
	"Transparency: []     "
	"Anti-aliasing: ,.    "
	"Shadow: ;            "
	"Gloss: '             ",
	r->fcolor, 180);
	r->tex_message = SDL_CreateTextureFromSurface(r->sdl->renderer, r->sur_message);
	SDL_QueryTexture(r->tex_message, NULL, NULL, &r->message_rect.w, &r->message_rect.h);
}

void	init_gui(t_rt *r)
{
	r->togle_info = false;
//	r->on = false;
//	r->show = false;
	create_background(r);
	create_info_text(r);
}