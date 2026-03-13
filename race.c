#include "types.h"
#include "stat.h"
#include "user.h"

int
main()
{
  int pid = fork();

  if(pid < 0){
    printf(1,"Fork failed\n");
  }

  else if(pid == 0){
    printf(1, "child 1 executing\n");
    exit();
  }

  else{
    pid = fork();

    if(pid < 0){
     printf(1, "fork failure\n");
    }

    else if(pid == 0){
      printf(1, "child 2 exec \n");
    }


    else{
      printf(1, "parent wait\n");
      wait();
      wait();

      printf(1, "parent exec\n");
    }
  }
  exit();
}
