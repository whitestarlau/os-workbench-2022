#include <game.h>

#define KEYNAME(key) \
  [AM_KEY_##key] = #key,
static const char *key_names[] = {
    AM_KEYS(KEYNAME)};

void print_key()
{
  AM_INPUT_KEYBRD_T event = {.keycode = AM_KEY_NONE};
  ioe_read(AM_INPUT_KEYBRD, &event);
  if (event.keycode != AM_KEY_NONE && event.keydown)
  {
    puts("Key pressed: ");
    puts(key_names[event.keycode]);
    puts("\n");
  }
}

dir_t wait_exit()
{
  AM_INPUT_KEYBRD_T event = {.keycode = AM_KEY_NONE};
  ioe_read(AM_INPUT_KEYBRD, &event);
  // puts("wait_exit ");

  if (event.keycode != AM_KEY_NONE && event.keydown)
  {
    puts("Key pressed: ");
    puts(key_names[event.keycode]);
    puts("\n");

    if (event.keycode == AM_KEY_ESCAPE)
    {
      return ESC;
    }
    else if (event.keycode == AM_KEY_W)
    {
      return UP;
    }
    else if (event.keycode == AM_KEY_A)
    {
      return LEFT;
    }
    else if (event.keycode == AM_KEY_S)
    {
      return DOWN;
    }
    else if (event.keycode == AM_KEY_D)
    {
      return RIGHT;
    }

    else
    {
      return NONE;
    }
  }
  else
  {
    return NONE;
  }
}