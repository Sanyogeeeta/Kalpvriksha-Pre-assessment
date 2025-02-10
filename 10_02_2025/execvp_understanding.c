#include<stdio.h>
#include<unistd.h>

int main(){
    char* args[]={"gcc","fork_basic.out","-o","a.out",NULL};
    execvp(args[0],args);
    printf("failed execution\n");
    return 0;
}