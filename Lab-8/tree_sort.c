#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node* insert(struct Node *root, int ele) {
    if (root == NULL) {
        struct Node *tmp = malloc(sizeof(struct Node));

        if (tmp == NULL) {
            printf("Memory allocation failed\n");
            exit(1);
        }

        tmp->data = ele;
        tmp->left = NULL;
        tmp->right = NULL;

        return tmp;
    }

    if (ele < root->data)
        root->left = insert(root->left, ele);
    else
        root->right = insert(root->right, ele);

    return root;
}

void inorder(struct Node *root) {
    if (root == NULL)
        return;

    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

int main() {
    int n, ele;
    struct Node *root = NULL;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Invalid number of elements.\n");
        return 0;
    }

    printf("Enter elements: ");

    for (int i = 0; i < n; i++) {
        scanf("%d", &ele);
        root = insert(root, ele);
    }

    printf("Sorted array: ");
    inorder(root);

    printf("\n");

    return 0;
}