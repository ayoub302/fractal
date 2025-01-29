#include "fractal.h"
#include "math.h"

static double	box_fold(double z)
{
	if (z > 1)
		z = 2 - z;
	else if (z < -1)
		z = -2 - z;
	return (z);
}

static double	ball_fold(double r, double m)
{
	if (m < r)
		m = m / (r * r);
	else if (m < 1)
		m = 1 / (m * m);
	return (m);
}

int	calc_mandelbox(t_fractal *fract, t_complex *c)
{
	double		mag;
	t_complex	z;
	int			i;

	i = -1;
	mag = 0;
	z.real = c->real;
	z.imaginary = c->imaginary;
	while ((sqrt(mag) < 2) && (++i < fract->iterations))
	{
		z.real = FIXED_READIUS * box_fold(z.real);
		z.imaginary = FIXED_READIUS * box_fold(z.imaginary);
		mag = sqrt(z.real * z.real + z.imaginary * z.imaginary);
		z.real = z.real * SCALE * ball_fold(MINIMUM_RADUIS, mag) + c->real;
		z.imaginary = z.imaginary * SCALE * ball_fold(MINIMUM_RADUIS, mag)
			+ c->imaginary;
	}
	return (i);
}
