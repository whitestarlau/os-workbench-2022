#include <game.h>

#define SIDE 16
static int w, h;

static point_t point;

static void init()
{
  AM_GPU_CONFIG_T info = {0};
  ioe_read(AM_GPU_CONFIG, &info);
  w = info.width;
  h = info.height;
}

static void draw_tile(int x, int y, int w, int h, uint32_t color)
{
  uint32_t pixels[w * h]; // WARNING: large stack-allocated memory
  AM_GPU_FBDRAW_T event = {
      .x = x,
      .y = y,
      .w = w,
      .h = h,
      .sync = 1,
      .pixels = pixels,
  };
  for (int i = 0; i < w * h; i++)
  {
    pixels[i] = color;
  }
  ioe_write(AM_GPU_FBDRAW, &event);
}

void splash()
{
  init();

  for (int x = 0; x * SIDE <= w; x++)
  {
    for (int y = 0; y * SIDE <= h; y++)
    {
      if ((x & 1) ^ (y & 1))
      {
        draw_tile(x * SIDE, y * SIDE, SIDE, SIDE, 0xffffff); // white
      }
    }
  }
}

void init_point()
{
  init();

  int wf = w / 2;
  int hf = h / 2;
  point.x = wf;
  point.y = hf;
  draw_tile(point.x, point.y, SIDE, SIDE, 0xffffff); // white
}

void update_point(dir_t dir)
{
  switch (dir)
  {
  case LEFT:
    point.x -= SIDE;
    break;
  case DOWN:
    point.y += SIDE;
    break;
  case RIGHT:
    point.x += SIDE;
    break;
  case UP:
    point.y -= SIDE;
    break;
  default:
    break;
  }
  draw_tile(point.x, point.y, SIDE, SIDE, 0xffffff); // white
}