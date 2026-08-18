#include <stdio.h>
int main() {
    int n;
    scanf("%d", &n);
    int arr[n + 1];
    // Taking input
    for (int i = 0; i < n + 1; i++) {
        scanf("%d", &arr[i]);
    }
    // Finding sum
    int sum = 0;
    for (int i = 0; i < n + 1; i++) {
        sum += arr[i];
    }
    int expected_sum = n * (n + 1) / 2;
    int duplicate_number = sum - expected_sum;

    printf("Duplicate number is: %d\n", duplicate_number);

    return 0;
}