#include <game.h>

// Operating system is a C program!
int main(const char *args) {
  ioe_init();

  puts("mainargs = \"");
  puts(args); // make run mainargs=xxx
  puts("\"\n");

  splash();

  puts("Press any key to see its key code...\n");
  int is_esc = 1;
  while (is_esc) {
    is_esc = wait_exit();
  }
  return 0;
}
