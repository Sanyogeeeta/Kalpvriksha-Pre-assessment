#include <stdio.h>
#include <string.h>
 
void AdjacentDuplicates(char *str) {
    int len = strlen(str), index = 0;
 
    for (int i = 0; i < len; i++) {
        if (index > 0 && str[i] == str[index - 1]) {
            index--;
        } else {
            str[index] = str[i];
            index++;
        }
    }
    str[index] = '\0';
    printf("%s\n", str);
}

int main() {
    char str[100];
    fgets(str,sizeof(str),stdin);
    AdjacentDuplicates(str);
    return 0;
}
