
#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node* insert(struct Node *root, int ele){
    if(root == NULL){
        struct Node *tmp = malloc(sizeof(struct Node));
        if(tmp == NULL){
            printf("Memory allocation failed\n");
            exit(1);
        }
        tmp->data = ele;
        tmp->left = NULL;
        tmp->right = NULL;
        return tmp;
    }
    if(ele < root->data)
        root->left = insert(root->left, ele);
    else if(ele > root->data)
        root->right = insert(root->right, ele);
    return root;
}

void inorder(struct Node *root, int arr[], int *count){
    if(root == NULL)
        return;
    inorder(root->left, arr, count);
    arr[*count] = root->data;
    (*count)++;
    inorder(root->right, arr, count);
}

int kthSmallest(int arr[], int n, int k){
    if(k <= 0 || k > n)
        return -1;
    return arr[k - 1];
}

int main(){
    int n, ele, q, k;
    int arr[100005];
    int count = 0;
    struct Node *root = NULL;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    if(n <= 0 || n > 100000){
        printf("Invalid number of elements.\n");
        return 0;
    }

    printf("Enter elements: ");
    for(int i = 0; i < n; i++){
        scanf("%d", &ele);
        root = insert(root, ele);
    }

    inorder(root, arr, &count);

    printf("Enter number of queries: ");
    scanf("%d", &q);

    if(q <= 0 || q > 100000){
        printf("Invalid number of queries.\n");
        return 0;
    }

    printf("Enter k values: ");
    for(int i = 0; i < q; i++){
        scanf("%d", &k);
        int ans = kthSmallest(arr, count, k);

        if(ans == -1)
            printf("Invalid k.\n");
        else
            printf("%d-th smallest element: %d\n", k, ans);
    }

    return 0;
}
