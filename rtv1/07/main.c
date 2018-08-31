#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <SDL2/SDL.h>
#include <unistd.h>

#define WINOW_W 640
#define WINDOW_H 480
#define INT_MAX 2147483647

typedef	struct		s_xy
{
	int				x;
	int				y;
}					t_xy;

typedef	struct		s_vec
{
	double			x;
	double			y;
	double			z;
}					t_vec;

typedef struct		s_col
{
	int				r;
	int				g;
	int				b;
	int				a;
}					t_col;

typedef	struct		s_sphere
{
	t_vec			center;
	int				radius;
	t_col			color;
}					t_sphere;

typedef	struct		s_env
{
	SDL_Window		*window;
	SDL_Renderer	*renderer;
	SDL_Event		e;
	t_vec			camera;
	double			viewport_size;
	double			projection_plane_z;
}					t_env;

// ======================================================================
//  Low-level canvas access. 
// ======================================================================

void	put_pixel(int x, int y, t_col color, t_env env)
{
	// printf("[%d][%d][%d]\n", color.r, color.g, color.b);
	SDL_SetRenderDrawColor(env.renderer, color.r, color.g, color.b, 255);
	SDL_RenderDrawPoint(env.renderer, x, y);
}


// The PutPixel() function.
var PutPixel = function(x, y, color) {
  x = canvas.width/2 + x;
  y = canvas.height/2 - y - 1;

  if (x < 0 || x >= canvas.width || y < 0 || y >= canvas.height) {
	return;
  }

  var offset = 4*x + canvas_pitch*y;
  canvas_buffer.data[offset++] = color[0];
  canvas_buffer.data[offset++] = color[1];
  canvas_buffer.data[offset++] = color[2];
  canvas_buffer.data[offset++] = 255; // Alpha = 255 (full opacity)
}


// Displays the contents of the offscreen buffer into the canvas.
var UpdateCanvas = function() {
  canvas_context.putImageData(canvas_buffer, 0, 0);
}


// ======================================================================
//  Linear algebra and helpers.
// ======================================================================

// Dot product of two 3D vectors.
var DotProduct = function(v1, v2) {
  return v1[0]*v2[0] + v1[1]*v2[1] + v1[2]*v2[2];  
}


// Computes v1 - v2.
var Subtract = function(v1, v2) {
  return [v1[0] - v2[0], v1[1] - v2[1], v1[2] - v2[2]];
}


// ======================================================================
//  A very basic raytracer.
// ======================================================================

// A Sphere.
var Sphere = function(center, radius, color) {
  this.center = center;
  this.radius = radius;
  this.color = color;
}

// Scene setup.
var viewport_size = 1;
var projection_plane_z = 1;
var camera_position = [0, 0, 0];
var background_color = [255, 255, 255];
var spheres = [new Sphere([0, -1, 3], 1, [255, 0, 0]),
		   new Sphere([2, 0, 4], 1, [0, 0, 255]),
		   new Sphere([-2, 0, 4], 1, [0, 255, 0])]; 


// Converts 2D canvas coordinates to 3D viewport coordinates.
var CanvasToViewport = function(p2d) {
  return [p2d[0] * viewport_size / canvas.width,
	  p2d[1] * viewport_size / canvas.height,
	  projection_plane_z]; 
}


// Computes the intersection of a ray and a sphere. Returns the values
// of t for the intersections.
var IntersectRaySphere = function(origin, direction, sphere) {
  var oc = Subtract(origin, sphere.center);

  var k1 = DotProduct(direction, direction);
  var k2 = 2*DotProduct(oc, direction);
  var k3 = DotProduct(oc, oc) - sphere.radius*sphere.radius;

  var discriminant = k2*k2 - 4*k1*k3;
  if (discriminant < 0) {
	return [Infinity, Infinity];
  }

  var t1 = (-k2 + Math.sqrt(discriminant)) / (2*k1);
  var t2 = (-k2 - Math.sqrt(discriminant)) / (2*k1);
  return [t1, t2];
}


// Traces a ray against the set of spheres in the scene.
var TraceRay = function(origin, direction, min_t, max_t) {
  var closest_t = Infinity;
  var closest_sphere = null;
  
  for (var i = 0; i < spheres.length; i++) {
	var ts = IntersectRaySphere(origin, direction, spheres[i]);
	if (ts[0] < closest_t && min_t < ts[0] && ts[0] < max_t) {
	  closest_t = ts[0];
	  closest_sphere = spheres[i];
	}
	if (ts[1] < closest_t && min_t < ts[1] && ts[1] < max_t) {
	  closest_t = ts[1];
	  closest_sphere = spheres[i];
	}
  }

  if (closest_sphere == null) {
	return background_color;
  }

  return closest_sphere.color;
}


//
// Main loop.
//
for (var x = -canvas.width/2; x < canvas.width/2; x++) {
  for (var y = -canvas.height/2; y < canvas.height/2; y++) {
	var direction = CanvasToViewport([x, y])
	var color = TraceRay(camera_position, direction, 1, Infinity);
	PutPixel(x, y, color);
  }
}

void	canvas_to_view(t_vec *diraction, t_env env, t_xy xy)
{
	diraction->x = xy.x * env.viewport_size / WINDOW_W;
	diraction->y = xy.y * env.viewport_size / WINDOW_W;
	diraction->z = env.projection_plane_z;
}

void	draw_sphere(t_env env)
{
	t_xy	xy;
	t_vec	diraction;
	t_col	color;

	xy.x = -1;
	while (++xy.x < WINDOW_W)
	{
		xy.y = -1;
		while (++xy.y < WINDOW_H)
		{
			canvas_to_view(&diraction, env, xy);
			trace_ray(env.camera, diraction, &color);
			put_pixel(xy.x, xy.y, color, env);
		}
	}
}

int		main(int ac, char **av)
{
	t_env	env;
	int		q;

	q = 0;
	init(&env);
	// draw_line(env);
	// draw_rect(env);
	draw_sphere(env);
	SDL_RenderPresent(env.renderer);
	while (!q)
		while(SDL_PollEvent(&env.e))
			env.e.type == SDL_QUIT ? q = 1 : 0;
	destroy(env);
	return (0);
}
