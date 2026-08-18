#include <stdio.h>
#include <time.h>

void bubbleSort(int arr[], int n) {
    int temp;

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void insertionSort(int arr[], int n) {
    int key, j;

    for (int i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
}

int main() {
    int sizes[] = {1000, 2000, 5000, 10000};
    int arr1[10000], arr2[10000];

    for (int s = 0; s < 4; s++) {

        int n = sizes[s];

        for (int i = 0; i < n; i++) {
            arr1[i] = n - i;
            arr2[i] = n - i;
        }

        clock_t start, end;

        start = clock();
        bubbleSort(arr1, n);
        end = clock();

        double bubbleTime = (double)(end - start) / CLOCKS_PER_SEC;

        start = clock();
        insertionSort(arr2, n);
        end = clock();

        double insertionTime = (double)(end - start) / CLOCKS_PER_SEC;

        printf("\nInput Size = %d\n", n);
        printf("Bubble Sort Time    = %f seconds\n", bubbleTime);
        printf("Insertion Sort Time = %f seconds\n", insertionTime);
    }

    return 0;
}