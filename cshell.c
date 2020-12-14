#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<string.h>

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
    printf(">>>");
    fgets(str, sizeof(str), stdin);
    char* piece = strtok(str," ");
    int i = 1;
    char* cmds[20];
    cmds[0] = piece;
    if (strcmp(cmds[0],"quit\n") == 0 || strcmp(cmds[0],"\n") == 0){
      break;
    }
    while(piece != NULL) {
        piece = strtok(NULL," ");
        cmds[i] = piece;
        i = i + 1;
    }

    int ret = fork();
    if (ret <= 0) {
      char path[100];
      strcpy(path,"/bin/");
      strcat(path,cmds[0]);
      execl(path,cmds[0],(char*)0);
      printf("csh: command not found \n");
      break;
    }
    else{
      wait(&ret);
    }
  }
    return 0;
}
