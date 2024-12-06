#include <stdio.h>
#include <getopt.h>
#include <stdlib.h>
#include <string.h>
int unstall(char ipkg[256]) {
  printf("Starting to install %s\n", ipkg);
  char basecmd[256] = "sudo xbps-remove -R ";
  char uncmd[1028] = "";
  strcat(uncmd, basecmd);
  strcat(uncmd, ipkg);
  system(uncmd);
}
int install(char ipkg[256]) {
  printf("Starting to install %s\n", ipkg);
  char basecmd[256] = "sudo xbps-install -S ";
  char uncmd[1028] = "";
  strcat(uncmd, basecmd);
  strcat(uncmd, ipkg);
  system(uncmd);
}
int main(int argc, char **argv) 
{
  int c;
  while (1)
    {
      static struct option long_options[] =
        {
          {"update",     no_argument,       0, 's'},
          {"uninstall",  required_argument, 0, 'r'},
          {"install",    required_argument, 0, 'i'},
          
          {0, 0, 0, 0}
        };
      int option_index = 0;
      c = getopt_long (argc, argv, "ir::s",
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
          printf("Starting system update...")
          system("sudo xbps-install -Su");
          break;
        case 'i':
          if (optarg) {
            install(optarg);
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
        case '?':
          /* getopt_long already printed an error message. */
          break;
        default:
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
