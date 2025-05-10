#include <stdio.h>
#define MAX 1000

int subarray(int arr[], int length, int k) {
    if (k == 0) return 0;

    int hashmap[MAX] = {0};
    int left = 0, right = 0, count = 0, total = 0;

    while (right < length) {
        if (hashmap[arr[right]] == 0) {  
            count++;
        }
        hashmap[arr[right]]++;  
        right++;

        while (count > k) {  
            hashmap[arr[left]]--;
            if (hashmap[arr[left]] == 0) {
                count--;
            }
            left++;
        }

        if (count == k) {
            total += 1;
        }
    }

    return total;
}

int main() {
    int array[MAX], index = 0, k;

    while (getchar() != '[');
    while (scanf("%d", &array[index++]) == 1) {
        if (getchar() == ']') break;
    }
    scanf("%d", &k);

    printf("%d\n", subarray(array, index, k));
    return 0;
}
