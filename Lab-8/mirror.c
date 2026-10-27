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

int isMirror(struct Node *x, struct Node *y) {
    if (x == NULL && y == NULL)
        return 1;

    if (x == NULL || y == NULL)
        return 0;

    if (x->data != y->data)
        return 0;

    return isMirror(x->left, y->right) &&
           isMirror(x->right, y->left);
}

int isSymmetric(struct Node *root) {
    if (root == NULL)
        return 1;

    return isMirror(root->left, root->right);
}

int main() {
    struct Node *root;

    printf("Enter root value (-1 for NULL): ");
    root = createTree();

    if (isSymmetric(root))
        printf("The tree is symmetric.\n");
    else
        printf("The tree is not symmetric.\n");

    return 0;
}