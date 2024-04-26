#include <game.h>

// Operating system is a C program!
int main(const char *args) {
  ioe_init();

  puts("mainargs = \"");
  puts(args); // make run mainargs=xxx
  puts("\"\n");

  init_point();

  puts("Press any key to see its key code...\n");
  dir_t dir = NONE;
  while (dir != ESC) {
    dir = wait_exit();
    if (dir != ESC && dir != NONE)
    {
      update_point(dir);
    }
    
  }
  return 0;
}
