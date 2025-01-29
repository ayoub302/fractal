#include "fractal.h"
#include "math.h"

int	calc_mandelbrot(t_fractal *fract, t_complex *c)
{
	double		real_temp;
	t_complex	z;
	int			i;

	i = -1;
	z.real = 0;
	z.imaginary = 0;
	while ((z.real * z.real + z.imaginary * z.imaginary) < 4
		&& ++i < fract->iterations)
	{
		real_temp = z.real * z.real - z.imaginary * z.imaginary + c->real;
		z.imaginary = 2 * z.real * z.imaginary + c->imaginary;
		z.real = real_temp;
	}
	return (i);
}

int	calc_julia(t_fractal *fract, t_complex *c, int x, int y)
{
	double		real_temp;
	t_complex	z;
	int			i;

	i = -1;
	z.real = (x / fract->zoom) + fract->offset_x;
	z.imaginary = (y / fract->zoom) + fract->offset_y;
	while ((z.real * z.real + z.imaginary * z.imaginary) < 4
		&& ++i < fract->iterations)
	{
		real_temp = z.real * z.real - z.imaginary * z.imaginary + c->real;
		z.imaginary = 2 * z.real * z.imaginary + c->imaginary;
		z.real = real_temp;
	}
	return (i);
}

int	calc_burning_ship(t_fractal *fract, t_complex *c)
{
	double		real_temp;
	t_complex	z;
	int			i;

	i = -1;
	z.real = 0;
	z.imaginary = 0;
	while ((z.real * z.real + z.imaginary * z.imaginary) < 4
		&& ++i < fract->iterations)
	{
		real_temp = z.real * z.real - z.imaginary * z.imaginary + c->real;
		z.imaginary = fabs(2 * z.real * z.imaginary) + c->imaginary;
		z.real = fabs(real_temp);
	}
	return (i);
}

int	calc_tricorn(t_fractal *fract, t_complex *c)
{
	double		real_temp;
	t_complex	z;
	int			i;

	i = -1;
	z.real = 0;
	z.imaginary = 0;
	while ((z.real * z.real + z.imaginary * z.imaginary) < 4
		&& ++i < fract->iterations)
	{
		real_temp = z.real * z.real - z.imaginary * z.imaginary + c->real;
		z.imaginary = -2 * z.real * z.imaginary + c->imaginary;
		z.real = real_temp;
	}
	return (i);
}

int	calc_celtic_mandelbar(t_fractal *fract, t_complex *c)
{
	double		real_temp;
	t_complex	z;
	int			i;

	i = -1;
	z.real = 0;
	z.imaginary = 0;
	while ((z.real * z.real + z.imaginary * z.imaginary) < 4
		&& ++i < fract->iterations)
	{
		real_temp = z.real * z.real - z.imaginary * z.imaginary;
		z.imaginary = -2 * z.real * z.imaginary + c->imaginary;
		if (real_temp < 0)
			real_temp *= -1;
		z.real = real_temp + c->real;
	}
	return (i);
}
