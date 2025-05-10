#include<stdio.h>
#include<unistd.h>

int main(){
    char* args[]={"/bin/ls","-l",NULL};
    execv(args[0],args);
    printf("failed execution\n");
    return 0;
}