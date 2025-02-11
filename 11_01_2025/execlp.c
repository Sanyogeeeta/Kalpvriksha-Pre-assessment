#include <stdio.h>
#include <unistd.h>
 
int main() {
    execlp("echo", "echo", "Hello", NULL);
    perror("execlp failed");
    return 1;
}