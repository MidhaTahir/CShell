#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<string.h>
#include<stdlib.h>

int main(){
  // while loop
  // input string
  // parse the string
  // check if commands are present inside bin functions otherwise Throw an error
  // fork --> parent,child 
  // (execute within child) if command is present --> execute
  // return parent
  while(1){
    char str[20];
    char pwd[1024];
    getcwd(pwd, sizeof(pwd));
    printf("🔥 \e[31m %s\e[00m@\e[32m%s\e[00m: \e[33;01m%s \e[00m \e[31m >>\e[00m ",getenv("USER"), getenv("USER"),pwd);
    fgets(str, sizeof(str), stdin);
    char* piece = strtok(str," ");
    int i = 1;
    char* args[20];
    char* cmd;
    cmd = piece;
    args[0] = piece;
    if (strcmp(cmd,"quit\n") == 0 || strcmp(cmd,"\n") == 0){
      break;
    }

    while(piece != NULL) {
        piece = strtok(NULL," ");
        args[i] = piece;
        i = i + 1;
    }

    int ret = fork();
    if (ret <= 0) {
      char path[100];
      char* ptr;
      strcpy(path, "/bin/");
      strcat(path, cmd);
      ptr = strtok(path, "\n");
      args[i - 2] = strtok(args[i - 2], "\n");
      if (i > 2) {
        execvp(cmd, args);
      } else {
        execl(ptr, cmd, (char*)0);
      }
      printf("❌ \e[31mmsh: command not found \n\e[00m");
      break;
    }
    else{
      wait(&ret);
    }
  }
    return 0;
}