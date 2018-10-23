#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  char *dirname;
  if( argc == 1 ) {
   dirname = ".";
   printf("current");
  }
  else if(argc == 2) {
    dirname = argv[1];
    printf("user");
  }
  else {
    fprintf(stderr, "usage: lsls [dirname]\n");
    return 0;
  }
  // Parse command line

  // Open directory
  DIR *d = opendir( dirname );

  if (d == NULL ) {
    fprintf(stderr, "lsls: cannot open directory %s \n", dirname);
    return 2;
  }

  // Repeatly read and print entries
  struct dirent *ent;
  while ( (ent=readdir( d )) != NULL ){
    printf("%s\n", ent->d_name);
  }

  // Close directory
  closedir( d );

  return 0;
}