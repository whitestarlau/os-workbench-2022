#include <am.h>
#include <amdev.h>
#include <klib.h>
#include <klib-macros.h>

typedef enum
{
  NONE,
  UP,
  DOWN,
  LEFT,
  RIGHT,
  ESC,
} dir_t;

typedef struct
{
  int x, y;
} point_t;


void splash();

void init_point();
void update_point(dir_t dir);

void print_key();
dir_t wait_exit();

static inline void puts(const char *s) {
  for (; *s; s++) putch(*s);
}
