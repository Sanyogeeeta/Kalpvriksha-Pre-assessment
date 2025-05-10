#include <stdio.h>
#include <unistd.h>
 
int main() {
    execl("/bin/echo", "echo", "Hello, World!", NULL);
    perror("execl failed");
    return 1;
}