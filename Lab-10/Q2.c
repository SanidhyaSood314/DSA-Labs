#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *left;
    struct Node *right;
    int lthread;
    int rthread;
};

struct Node* createTree(){
    int ele;
    scanf("%d", &ele);

    if(ele == -1)
        return NULL;

    struct Node *tmp = malloc(sizeof(struct Node));

    if(tmp == NULL){
        printf("Memory allocation failed\n");
        exit(1);
    }

    tmp->data = ele;

    printf("Enter left child of %d (-1 for NULL): ", ele);
    tmp->left = createTree();

    printf("Enter right child of %d (-1 for NULL): ", ele);
    tmp->right = createTree();

    tmp->lthread = 0;
    tmp->rthread = 0;

    return tmp;
}

void convert(struct Node *root, struct Node **prev){
    if(root == NULL)
        return;

    convert(root->left, prev);

    if(root->left == NULL){
        root->left = *prev;
        root->lthread = 1;
    }

    if(*prev != NULL && (*prev)->right == NULL){
        (*prev)->right = root;
        (*prev)->rthread = 1;
    }

    *prev = root;

    if(root->rthread == 0)
        convert(root->right, prev);
}

struct Node* leftMost(struct Node *root){
    if(root == NULL)
        return NULL;

    while(root->lthread == 0)
        root = root->left;

    return root;
}

void inorder(struct Node *root){
    struct Node *curr = leftMost(root);

    while(curr != NULL){
        printf("%d ", curr->data);

        if(curr->rthread == 1)
            curr = curr->right;
        else
            curr = leftMost(curr->right);
    }
}

int main(){
    struct Node *root;
    struct Node *prev = NULL;

    printf("Enter root value (-1 for NULL): ");
    root = createTree();

    convert(root, &prev);

    if(prev != NULL)
        prev->rthread = 1;

    printf("Inorder traversal: ");
    inorder(root);

    printf("\n");

    return 0;
}