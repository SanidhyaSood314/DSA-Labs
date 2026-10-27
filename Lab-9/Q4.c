#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

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

struct Info{
    int isBST;
    int min;
    int max;
    int sum;
};

int maxSum = INT_MIN;

struct Info maxSumBST(struct Node *root){
    struct Info info;

    if (root == NULL){
        info.isBST = 1;
        info.min = INT_MAX;
        info.max = INT_MIN;
        info.sum = 0;
        return info;
    }

    struct Info left = maxSumBST(root->left);
    struct Info right = maxSumBST(root->right);

    if (left.isBST && right.isBST &&
        root->data > left.max && root->data < right.min){

        info.isBST = 1;
        info.sum = left.sum + right.sum + root->data;

        if (root->data < left.min)
            info.min = root->data;
        else
            info.min = left.min;

        if (root->data > right.max)
            info.max = root->data;
        else
            info.max = right.max;

        if (info.sum > maxSum)
            maxSum = info.sum;
    } else {
        info.isBST = 0;
        info.min = INT_MIN;
        info.max = INT_MAX;
        info.sum = 0;
    }

    return info;
}

int main(){
    struct Node *root;

    printf("Enter root value (-1 for NULL): ");
    root = createTree();

    maxSumBST(root);

    printf("Maximum BST subtree sum = %d\n", maxSum);

    return 0;
}
