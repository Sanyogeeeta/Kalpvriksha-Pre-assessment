#include <stdio.h>
#include <string.h>

int main() {
    char str1[] = "Hello, World!",str2[25];
    // char *ptr = strstr(str1, "World");
    // printf("%s", ptr);  // Output: World!
    // ptr = strrchr(str1, 'o');
    // printf("%s\n", ptr);  // Output: o, World!
    memmove(str1+4,str1,sizeof(char)*4);
    printf("%s\n",str1);
    //  char str[] = "123abc";
    // printf("%zu", strspn(str, "123"));
    return 0;
}
