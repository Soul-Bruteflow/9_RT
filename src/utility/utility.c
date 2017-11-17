#include "rt.h"

/*
** Hard clamp
*/
float	ft_clamp_f(float value, float lower, float upper)
{
	if (value > upper)
		value = upper;
	if (value < lower)
		value = lower;
	return (value);
}

/*
** Wrap around clamp
*/
float	ft_clamp_wf(float value, float lower, float upper)
{
	if (value > upper)
		value -= upper;
	if (value < lower)
		value += lower;
	return (value);
}