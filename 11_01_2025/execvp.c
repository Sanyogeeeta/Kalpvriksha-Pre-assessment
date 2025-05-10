#include <stdio.h>
#include <unistd.h>
 
int main() {
    char* args[]={"ls","-l",NULL};
    execvp(args[0],args);
    perror("execvp failed");
    return 1;
}