#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

void serialize(struct Node *root, char str[], int *index){
    if (root == NULL){
        *index += sprintf(str + *index, "# ");
        return;
    }

    *index += sprintf(str + *index, "%d ", root->data);

    serialize(root->left, str, index);
    serialize(root->right, str, index);
}

struct Node* deserialize(char str[], int *index){
    while (str[*index] == ' ')
        (*index)++;

    if (str[*index] == '\0')
        return NULL;

    if (str[*index] == '#'){
        (*index)++;
        return NULL;
    }

    int ele = 0;
    int sign = 1;

    if (str[*index] == '-'){
        sign = -1;
        (*index)++;
    }

    while (str[*index] >= '0' && str[*index] <= '9'){
        ele = ele * 10 + str[*index] - '0';
        (*index)++;
    }

    ele *= sign;

    struct Node *tmp = malloc(sizeof(struct Node));
    tmp->data = ele;

    tmp->left = deserialize(str, index);
    tmp->right = deserialize(str, index);

    return tmp;
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
    char str[10000];
    int index = 0;

    printf("Enter root value (-1 for NULL): ");
    root = createTree();

    serialize(root, str, &index);
    str[index] = '\0';

    printf("Serialized tree: %s\n", str);

    index = 0;
    struct Node *newRoot = deserialize(str, &index);

    printf("Inorder traversal of reconstructed tree: ");
    inorder(newRoot);
    printf("\n");

    return 0;
}