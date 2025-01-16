#include <stdio.h>
#include <string.h>
 
void longestPalindromicSubstring(char *str) {
    int n = strlen(str);
    if (n == 0) {
        printf("No palindrome\n");
        return;
    }
 
    int start = 0, maxLength = 1;
 
    for (int i = 0; i < n; i++) {
        int low = i - 1, high = i + 1;

        while (high < n && str[high] == str[i])
            high++;
        while (low >= 0 && str[low] == str[i])
            low--;
 
        while (low >= 0 && high < n && str[low] == str[high]) {
            low--;
            high++;
        }
 
        int length = high - low - 1;
        if (length > maxLength) {
            maxLength = length;
            start = low + 1;
        }
    }
 
    for (int i = start; i < start + maxLength; i++) {
        printf("%c", str[i]);
    }
    printf("\n");
}
 
int main() {
    char str[100];
    fgets(str,sizeof(str),stdin);
    longestPalindromicSubstring(str);
    return 0;
}