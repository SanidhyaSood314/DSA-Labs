#include <stdio.h>

void printSubsetsWithSumBitmask(int arr[], int n, int target) {
    int totalSubsets = 1 << n; 
    for (int i = 0; i < totalSubsets; i++) {
        int currentSum = 0;

        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) {
                currentSum += arr[j];
            }
        }
        if (currentSum == target) {
            printf("[ ");
            for (int j = 0; j < n; j++) {
                if (i & (1 << j)) {
                    printf("%d ", arr[j]);
                }
            }
            printf("]\n");
        }
    }
}
int main() {
    int arr[] = {1,2,3,4,5,6,7,8,9};
    int target = 10;
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Subsets that sum up to %d :\n", target);
    printSubsetsWithSumBitmask(arr, n, target);

    return 0;
}
