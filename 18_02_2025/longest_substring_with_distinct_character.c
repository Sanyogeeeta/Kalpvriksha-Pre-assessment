// #include <stdio.h>
// #include <string.h>
// #define MAX 128

// int hash_function(char c) {
//     return (int)c;
// }

// int longest_substring(int hashmap[MAX], char str[], int k) {
//     int left = 0, right = 0, count = 0;
//     int length = strlen(str);
//     int max_length = -1;
    
//     while (right < length) {
//         int index = hash_function(str[right]);

//         if (hashmap[index] == 0) {
//             hashmap[index] = 1;
//             count++;
//         }

//         while (count > k) {
//             int left_index = hash_function(str[left]);
//             hashmap[left_index] = 0;
//             count--;
//             left++;
//         }

//         if (count == k) {
//             max_length = (max_length > (right - left + 1)) ? max_length : (right - left + 1);
//         }

//         right++;
//     }

//     return max_length;
// }

// int main() {
//     char str[MAX];
//     int k, hashmap[MAX] = {0};

//     scanf("%s", str);
//     scanf("%d", &k);

//     if (k == 0) {
//         printf("-1\n");
//         return 0;
//     }

//     int result = longest_substring(hashmap, str, k);
//     printf("%d\n", result);

//     return 0;
// }
#include <stdio.h>
#include <string.h>
#define MAX 128

int hash_function(char c) {
    return (int)c;
}

int longest_substring(int hashmap[MAX], char str[], int k) {
    int left = 0, right = 0, count = 0;
    int length = strlen(str);
    int max_length = -1;
    
    while (right < length) {
        int index = hash_function(str[right]);

        if (hashmap[index] == 0) {
            hashmap[index] = 1;
            count++;
        }

        while (count > k) {
            int left_index = hash_function(str[left]);
            hashmap[left_index] = 0;
            count--;
            left++;
        }

        if (count == k) {
            max_length = (max_length > (right - left)) ? max_length : (right - left+1);
        }
        right++;
    }

    return max_length;
}

int main() {
    char str[MAX];
    int k, hashmap[MAX] = {0};

    scanf("%s", str);
    scanf("%d", &k);

    if (k == 0) {
        printf("-1\n");
        return 0;
    }

    int result = longest_substring(hashmap, str, k);
    printf("%d\n", result);

    return 0;
}
