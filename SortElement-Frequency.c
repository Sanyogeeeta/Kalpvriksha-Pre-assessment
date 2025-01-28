#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void sort_elements(int *arr, int frequency[], int first_index[], int unique_length) {
    for (int i = 0; i < unique_length - 1; i++) {
        for (int j = 0; j < unique_length - i - 1; j++) {
            if (frequency[j] < frequency[j + 1]) {
                swap(&frequency[j], &frequency[j + 1]);
                swap(&arr[j], &arr[j + 1]);
                swap(&first_index[j], &first_index[j + 1]);
            } else if (frequency[j] == frequency[j + 1] && first_index[j] > first_index[j + 1]) {
                swap(&frequency[j], &frequency[j + 1]);
                swap(&arr[j], &arr[j + 1]);
                swap(&first_index[j], &first_index[j + 1]);
            }
        }
    }
}

void sort_by_frequency(int arr[], int length) {
    int unique_elements[length];
    int frequency_count[length];
    int first_index[length];
    int unique_length = 0;

    for (int i = 0; i < length; i++) {
        int is_unique = 1;
        for (int j = 0; j < unique_length; j++) {
            if (arr[i] == unique_elements[j]) {
                frequency_count[j]++;
                is_unique = 0;
                break;
            }
        }
        if (is_unique) {
            unique_elements[unique_length] = arr[i];
            frequency_count[unique_length] = 1;
            first_index[unique_length] = i;
            unique_length++;
        }
    }

    sort_elements(unique_elements, frequency_count, first_index, unique_length);

    int sorted_arr[length];
    int index = 0;

    for (int i = 0; i < unique_length; i++) {
        for (int j = 0; j < frequency_count[i]; j++) {
            sorted_arr[index] = unique_elements[i];
            index++;
        }
    }

    for (int i = 0; i < length; i++) {
        printf("%d ", sorted_arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[100000];
    int length = 0;

    while (scanf("%d", &arr[length]) == 1) {
        length++;
    }

    sort_by_frequency(arr, length);

    return 0;
}
