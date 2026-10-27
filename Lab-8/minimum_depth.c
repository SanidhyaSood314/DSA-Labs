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
    tmp->data = ele;

    printf("Enter left child of %d (-1 for NULL): ", ele);
    tmp->left = createTree();

    printf("Enter right child of %d (-1 for NULL): ", ele);
    tmp->right = createTree();

    return tmp;
}

int minDepth(struct Node *root) {
    if (root == NULL)
        return 0;

    if (root->left == NULL && root->right == NULL)
        return 1;

    if (root->left == NULL)
        return 1 + minDepth(root->right);

    if (root->right == NULL)
        return 1 + minDepth(root->left);

    int leftDepth = minDepth(root->left);
    int rightDepth = minDepth(root->right);

    return 1 + (leftDepth < rightDepth ? leftDepth : rightDepth);
}

int main() {
    struct Node *root;

    printf("Enter root value (-1 for NULL): ");
    root = createTree();

    printf("Minimum depth: %d\n", minDepth(root));

    return 0;
}