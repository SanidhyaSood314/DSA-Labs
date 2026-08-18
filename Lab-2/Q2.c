#include <stdio.h>

int main() {
    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int i = 1;

    while (i < n && arr[i] == arr[0])
        i++;

    int largest, secondLargest;
    int smallest, secondSmallest;

    if (arr[0] > arr[i]) {
        largest = arr[0];
        secondLargest = arr[i];
    } else {
        largest = arr[i];
        secondLargest = arr[0];
    }

    if (arr[0] < arr[i]) {
        smallest = arr[0];
        secondSmallest = arr[i];
    } else {
        smallest = arr[i];
        secondSmallest = arr[0];
    }

    for (i = i + 1; i < n; i++) {

        if (arr[i] > largest) {
            secondLargest = largest;
            largest = arr[i];
        }
        else if (arr[i] > secondLargest && arr[i] != largest) {
            secondLargest = arr[i];
        }

        if (arr[i] < smallest) {
            secondSmallest = smallest;
            smallest = arr[i];
        }
        else if (arr[i] < secondSmallest && arr[i] != smallest) {
            secondSmallest = arr[i];
        }
    }

    printf("Second Largest Element = %d\n", secondLargest);
    printf("Second Smallest Element = %d\n", secondSmallest);

    return 0;
}