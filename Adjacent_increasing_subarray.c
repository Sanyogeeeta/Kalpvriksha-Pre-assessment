#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int max_subarray_index(int arr[], int n) {
    int maxK = 0;
    int len[n];
    len[0] = 1;
    
    for (int i = 1; i < n; i++) {
        if (arr[i] > arr[i - 1]) {
            len[i] = len[i - 1] + 1;
        } else {
            len[i] = 1;
        }
    }
    
    for (int k = 1; k <= n / 2; k++) {
        for (int i = 0; i + 2 * k - 1 < n; i++) {
            if (len[i + k - 1] >= k && len[i + 2 * k - 1] >= k) {
                maxK = k;
            }
        }
    }

    return maxK;
}
int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    int arr[100000];
    
    int index=0,value;
    while (scanf("%d", &value) == 1)
    {
        arr[index]= value;
        index++;
        if (getchar() == '\n')
            break;
    }
    
    int k=max_subarray_index(arr,index);
    printf("%d",k);
    return 0;
}
