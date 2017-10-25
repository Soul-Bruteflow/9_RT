#include "vectors.h"

void	ft_mat_set(t_mat4 *m, uint x, uint y, float value)
{
	*m[x][y] = value;
}