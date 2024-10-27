#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void bubble_sort(int arr[], int n) {
    int i, j;
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

void selection_sort(int arr[], int n) {
    int i, j, min_index;
    for (i = 0; i < n-1; i++) {
        min_index = i;
        for (j = i+1; j < n; j++) {
            if (arr[j] < arr[min_index]) {
                min_index = j;
            }
        }
        int temp = arr[min_index];
        arr[min_index] = arr[i];
        arr[i] = temp;
    }
}

void insertion_sort(int arr[], int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

int main() {
    srand(time(NULL));

    int n = 10000;
    int arr[n];

    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 10000;
    }

    clock_t start = clock();
    bubble_sort(arr, n);
    clock_t end = clock();
    double bubble_time = ((double)(end - start)) / CLOCKS_PER_SEC;

    start = clock();
    selection_sort(arr, n);
    end = clock();
    double selection_time = ((double)(end - start)) / CLOCKS_PER_SEC;

    start = clock();
    insertion_sort(arr, n);
    end = clock();
    double insertion_time = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("Tempo de execucao do Bubble Sort: %f segundos\n", bubble_time);
    printf("Tempo de execucao do Selection Sort: %f segundos\n", selection_time);
    printf("Tempo de execucao do Insertion Sort: %f segundos\n", insertion_time);

    return 0;
}
