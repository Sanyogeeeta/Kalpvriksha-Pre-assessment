#include <stdio.h>
#include <string.h>
#include <limits.h>

#define MAX_CHAR 256

void findSmallestWindow(char *str, char *pat) {
    int n = strlen(str);
    int m = strlen(pat);
    if (n < m) {
        printf("-1\n");
        return;
    }
    
    int patCount[MAX_CHAR] = {0};
    for (int i = 0; i < m; i++) {
        patCount[pat[i]]++;
    }
    
    int start = 0, startIndex = -1, minLength = INT_MAX;
    int strCount[MAX_CHAR] = {0};
    int count = 0;
    
    for (int end = 0; end < n; end++) {
        strCount[str[end]]++;
        if (strCount[str[end]] <= patCount[str[end]]) {
            count++;
        }
        
        while (count == m) {
            if (end - start + 1 < minLength) {
                minLength = end - start + 1;
                startIndex = start;
            }
            strCount[str[start]]--;
            if (strCount[str[start]] < patCount[str[start]]) {
                count--;
            }
            start++;
        }
    }
    
    if (startIndex == -1) {
        printf("-1\n");
    } else {
        for (int i = startIndex; i < startIndex + minLength; i++) {
            printf("%c", str[i]);
        }
        printf("\n");
    }
}

int main() {
    char str[100], pat[100];
    fgets(str, sizeof(str), stdin);
    fgets(pat, sizeof(pat), stdin);
    
    str[strcspn(str, "\n")] = '\0';
    pat[strcspn(pat, "\n")] = '\0';
    
    findSmallestWindow(str, pat);
    return 0;
}
