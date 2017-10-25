#include "vectors.h"
#include "math.h"

float ft_to_radians(float degrees)
{
	return ((float)(degrees * M_PI / 180));
}

float ft_to_degree(float radians)
{
	return ((float)(radians * 180 / M_PI));
}