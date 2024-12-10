// need these things
#include <stdio.h>
#include <getopt.h>
#include <stdlib.h>
#include <string.h>
#include "config.h"
//definitions to make it easier
#define inarg installarg
#define unarg unstallarg
#define uparg updatearg
#define sucmd superuser
static const char spacer[50] = " ";//qol thing for config file
int unstall(char ipkg[256]) {
  printf("Starting to uninstall %s\n", ipkg);
  char uncmd[2028] = "";
  strcat(uncmd, sucmd);
  strcat(uncmd, spacer);
  strcat(uncmd, unarg);
  strcat(uncmd, spacer);
  strcat(uncmd, ipkg);
  system(uncmd);
  return 0;
}
int install(char ipkg[256]) {//the install func
  printf("Starting to install %s\n", ipkg);
  char uncmd[2028] = "";
  strcat(uncmd, sucmd);
  strcat(uncmd, spacer);
  strcat(uncmd, inarg);
  strcat(uncmd, spacer);
  strcat(uncmd, ipkg);
  system(uncmd);
  return 0;
}
int update() {
  printf("Starting System Update...\n");
  char uncmd[2028] = "";
  strcat(uncmd, sucmd);
  strcat(uncmd, spacer);
  strcat(uncmd, uparg);
  system(uncmd);
  return 0;
}
int main(int argc, char **argv) 
{
  int c;
  while (1)
    {
      static struct option long_options[] =//def didnt copy from the GNU site...
        {
          {"update",     no_argument,       0, 's'},
          {"uninstall",  required_argument, 0, 'r'},
          {"install",    required_argument, 0, 'i'},
          {"help",       no_argument,       0, 'h'},
          // {"clear",      no_argument,       0, 'c'},
          {0, 0, 0, 0}
        };
      int option_index = 0;
      c = getopt_long (argc, argv, "hi:r:s",
                       long_options, &option_index);
      if (c == -1)
        break;
      switch (c) {
        case 0:
          if (long_options[option_index].flag != 0)
            break;
          printf ("option %s", long_options[option_index].name);
          if (optarg)
            printf (" with arg %s", optarg);
          printf ("\n");
          break;
        case 's':
          update();
          break;
        case 'i':
          if (optarg) {
            install(optarg);//checks for a arg
          } else {
            fprintf(stderr, "Error: -i requires a package name.\n");
          }
          break;
          break;
        case 'r':
          if (optarg) {
            unstall(optarg);
          } else {
            fprintf(stderr, "Error: -r requires a package name.\n");
          }
          break;
          break;
        case 'h'://help message
          printf("Options:\n");
          printf("-r Usage: -r (package) | This means remove a package.\n");
          printf("-i Usage: -i (package) | This means install a package.\n");
          printf("-s Usage: -s | This means perform a system update.\n");
          printf("-h Usage: -h | This means that this message will come up.\n");
        case '?':
          printf("unknown option. For list of options do sputil -h\n");
          break;
        default:
          printf("For list of options do sputil -h\n");
          abort ();
        }
    }
  if (optind < argc) {
      printf ("non-option ARGV-elements: ");
      while (optind < argc)
        printf ("%s ", argv[optind++]);
      putchar ('\n');
    }
  exit (0);
}
