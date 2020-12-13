#include<stdio.h>
#include<string.h>

int main(){
    char str[20];
    printf("Enter a command: ");
    fgets(str, sizeof(str), stdin);
    puts(str);
    char* piece = strtok(str," ");
    int i = 1;
    char* cmds[20];
    cmds[0] = piece;
    while(piece != NULL) {
        //printf("%s\n",piece);
        piece = strtok(NULL," ");
        cmds[i] = piece;
        i = i + 1;
    }
    
    int j;
    for(j=0;j<i-1;j++) {
        printf("%s\n", cmds[j]);
    }
    return 0;
}

