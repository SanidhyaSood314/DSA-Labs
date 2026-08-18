#include <stdio.h>
int insert(int arr[], int n) {
    int num, pos;
    printf("Enter value to insert: ");
    scanf("%d", &num);
    printf("Enter position: ");
    scanf("%d", &pos);
    for (int i = n; i > pos; i--) {
        arr[i] = arr[i - 1];
    }
    arr[pos] = num;
    printf("\nArray after insertion:\n");
    for (int i = 0; i <= n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return n + 1;
}
int delete(int arr[], int n) {
    int num, loc = -1;
    printf("\nEnter element to delete: ");
    scanf("%d", &num);
    for (int i = 0; i < n; i++) {
        if (arr[i] == num) {
            loc = i;
            break;
        }
    }
    if (loc == -1) {
        printf("Element not found.\n");
        return n;
    }
    for (int i = loc; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    printf("\nArray after deletion:\n");
    for (int i = 0; i < n - 1; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return n - 1;
}
int main() {
    int arr[100];
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    n = insert(arr, n);
    n = delete(arr, n);
    return 0;
}
