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

void recoverBST(struct Node *root, struct Node **first,
                struct Node **middle, struct Node **last,
                struct Node **prev){
    if (root == NULL)
        return;

    recoverBST(root->left, first, middle, last, prev);

    if (*prev != NULL && root->data < (*prev)->data){
        if (*first == NULL){
            *first = *prev;
            *middle = root;
        } 
        else{
            *last = root;
        }
    }

    *prev = root;

    recoverBST(root->right, first, middle, last, prev);
}

void correctBST(struct Node *root){
    struct Node *first = NULL, *middle = NULL;
    struct Node *last = NULL, *prev = NULL;

    recoverBST(root, &first, &middle, &last, &prev);

    if (first != NULL && last != NULL){
        int temp = first->data;
        first->data = last->data;
        last->data = temp;
    } 
    else if (first != NULL && middle != NULL){
        int temp = first->data;
        first->data = middle->data;
        middle->data = temp;
    }
}

void inorder(struct Node *root){
    if (root == NULL)
        return;

    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

int main(){
    struct Node *root;

    printf("Enter root value (-1 for NULL): ");
    root = createTree();

    correctBST(root);

    printf("Corrected BST (inorder): ");
    inorder(root);
    printf("\n");

    return 0;
}
