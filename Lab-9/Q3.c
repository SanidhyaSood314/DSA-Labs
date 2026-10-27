#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node* createTree(){
    int ele;
    scanf("%d", &ele);

    if (ele == -1)
        return NULL;

    struct Node *tmp = malloc(sizeof(struct Node));
    tmp->data = ele;

    printf("Enter left child of %d (-1 for NULL): ", ele);
    tmp->left = createTree();

    printf("Enter right child of %d (-1 for NULL): ", ele);
    tmp->right = createTree();

    return tmp;
}

void inorder(struct Node *root, int arr[], int *n){
    if (root == NULL)
        return;

    inorder(root->left, arr, n);
    arr[(*n)++] = root->data;
    inorder(root->right, arr, n);
}

void closestK(int arr[], int n, int x, int k){
    int left = 0, right = n - 1;

    while (left <= right){
        int mid = left + (right - left) / 2;

        if (arr[mid] <= x)
            left = mid + 1;
        else
            right = mid - 1;
    }

    int i = right, j = left;

    printf("The %d closest values are: ", k);

    for (int count = 0; count < k; count++){
        if (i < 0){
            printf("%d ", arr[j++]);
        } else if (j >= n){
            printf("%d ", arr[i--]);
        } else if (abs(arr[i] - x) <= abs(arr[j] - x)){
            printf("%d ", arr[i--]);
        } else {
            printf("%d ", arr[j++]);
        }
    }

    printf("\n");
}

int main(){
    struct Node *root;
    int arr[1000], n = 0;
    int x, k;

    printf("Enter root value (-1 for NULL): ");
    root = createTree();

    inorder(root, arr, &n);

    printf("Enter target value: ");
    scanf("%d", &x);

    printf("Enter k: ");
    scanf("%d", &k);

    if (k <= 0 || k > n){
        printf("Invalid k.\n");
        return 0;
    }

    closestK(arr, n, x, k);

    return 0;
}
