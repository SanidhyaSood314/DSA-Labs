#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node* createTree() {
    int ele;
    scanf("%d", &ele);

    if (ele == -1)
        return NULL;

    struct Node *tmp = malloc(sizeof(struct Node));

    if (tmp == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }

    tmp->data = ele;

    printf("Enter left child of %d (-1 for NULL): ", ele);
    tmp->left = createTree();

    printf("Enter right child of %d (-1 for NULL): ", ele);
    tmp->right = createTree();

    return tmp;
}

void smallest(struct Node *root, int k, int *count, int *ans) {
    if (root == NULL || *count >= k)
        return;

    smallest(root->left, k, count, ans);

    if (*count < k) {
        (*count)++;

        if (*count == k)
            *ans = root->data;
    }

    smallest(root->right, k, count, ans);
}

void largest(struct Node *root, int k, int *count, int *ans) {
    if (root == NULL || *count >= k)
        return;

    largest(root->right, k, count, ans);

    if (*count < k) {
        (*count)++;

        if (*count == k)
            *ans = root->data;
    }

    largest(root->left, k, count, ans);
}

int main() {
    struct Node *root;
    int k, count = 0;
    int small = 0, large = 0;

    printf("Enter root value (-1 for NULL): ");
    root = createTree();

    printf("Enter k: ");
    scanf("%d", &k);

    if (k <= 0) {
        printf("Invalid k.\n");
        return 0;
    }

    smallest(root, k, &count, &small);

    if (count < k) {
        printf("Invalid k.\n");
        return 0;
    }

    count = 0;
    largest(root, k, &count, &large);

    printf("%d-th smallest key: %d\n", k, small);
    printf("%d-th largest key: %d\n", k, large);

    return 0;
}