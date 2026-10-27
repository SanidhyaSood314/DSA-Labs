#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* left;
    struct Node* right;
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

struct QueueNode{
    struct Node *node;
    int hd;
};

void topView(struct Node *root){
    if (root == NULL)
        return;

    struct QueueNode queue[1000];
    int visited[1000] = {0};
    int values[1000];

    int front = 0, rear = 0;
    int offset = 500;

    queue[rear].node = root;
    queue[rear].hd = 0;
    rear++;

    while (front < rear){
        struct QueueNode curr = queue[front++];
        int index = curr.hd + offset;

        if (!visited[index]){
            visited[index] = 1;
            values[index] = curr.node->data;
        }

        if (curr.node->left != NULL){
            queue[rear].node = curr.node->left;
            queue[rear].hd = curr.hd - 1;
            rear++;
        }

        if (curr.node->right != NULL){
            queue[rear].node = curr.node->right;
            queue[rear].hd = curr.hd + 1;
            rear++;
        }
    }

    printf("Top view of the binary tree: ");

    for (int i = 0; i < 1000; i++){
        if (visited[i])
            printf("%d ", values[i]);
    }

    printf("\n");
}

int main(){
    struct Node *root;

    printf("Enter root value (-1 for NULL): ");
    root = createTree();

    topView(root);

    return 0;
}