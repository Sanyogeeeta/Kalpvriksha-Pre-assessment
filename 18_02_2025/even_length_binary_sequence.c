#include <stdio.h>

void generate_balanced_sequences(int arr[], int index, int n, int sum1, int sum2) {
    if (index == 2 * n) {
        if (sum1 == sum2) {  
            for (int i = 0; i < 2 * n; i++)
                printf("%d", arr[i]);
            printf("\n");
        }
        return;
    }

    arr[index] = 0;
    if (index < n)
        generate_balanced_sequences(arr, index + 1, n, sum1, sum2);
    else
        generate_balanced_sequences(arr, index + 1, n, sum1, sum2);

    arr[index] = 1;
    if (index < n)
        generate_balanced_sequences(arr, index + 1, n, sum1 + 1, sum2);
    else
        generate_balanced_sequences(arr, index + 1, n, sum1, sum2 + 1);
}

int main() {
    int n;
    printf("Enter value of n: ");
    scanf("%d", &n);

    int arr[2 * n];
    generate_balanced_sequences(arr, 0, n, 0, 0);

    return 0;
}
