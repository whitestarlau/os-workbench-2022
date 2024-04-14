#include <stdio.h>
#include <assert.h>

#include <dirent.h>
#include <sys/stat.h>
#include <string.h>
#include <ctype.h>

char version[] = "0.1";

void traverse_numeric_folders(const char *directory_path)
{
  struct dirent *entry;
  DIR *dir = opendir(directory_path);

  if (dir == NULL)
  {
    perror("Failed to open directory");
    return;
  }

  while ((entry = readdir(dir)) != NULL)
  {
    // printf("readdir: %s\n", entry->d_name);

    // Skip '.' and '..' entries
    if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
    {
      continue;
    }

    char full_path[strlen(directory_path) + strlen(entry->d_name) + 2];
    sprintf(full_path, "%s/%s", directory_path, entry->d_name);

    struct stat sb;
    //获取文件夹的属性，放到sb中。
    if (stat(full_path, &sb) == -1)
    {
      perror("Failed to get file stats");
      continue;
    }

    // Check if it's a directory
    if (S_ISDIR(sb.st_mode))
    {
      // Check if the name consists only of digits
      if (isdigit_only(entry->d_name))
      {
        //TODO 建立一个结构体，使用hashmap来存储pid和进程信息。
        printf("Numeric folder found: %s\n", full_path);
        // Perform further actions with the numeric folder here
      }
    }
  }

  closedir(dir);
}

int isdigit_only(const char *str)
{
  for (size_t i = 0; str[i] != '\0'; ++i)
  {
    if (!isdigit((unsigned char)str[i]))
    {
      return 0;
    }
  }
  return 1;
}

void handle_version_option()
{
  printf("Verion %s\n", version);
}

int main(int argc, char *argv[])
{
  printf("argc: %d\n", argc);

  for (int i = 1; i < argc; i++)
  {
    assert(argv[i]);
    const char *arg = argv[i];
    if (arg[1] == 'v')
    {
      handle_version_option();
      return 0;
    }
    else if (arg[1] == 'p')
    {
    }
    else if (arg[1] == 'n')
    {
      //
    }
    else
    {
      printf("Unknown option: %s\n", arg);
      return 1;
    }
  }

  traverse_numeric_folders("/proc");

  return 0;
}

int forEachProcFile()
{
}
