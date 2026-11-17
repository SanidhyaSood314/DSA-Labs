#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *left;
    struct Node *right;
    struct Node *parent;
    int visited;
};

struct Node* createNode(int ele){
    struct Node *tmp = malloc(sizeof(struct Node));
    if(tmp == NULL){
        printf("Memory allocation failed\n");
        exit(1);
    }
    tmp->data = ele;
    tmp->left = NULL;
    tmp->right = NULL;
    tmp->parent = NULL;
    tmp->visited = 0;
    return tmp;
}

struct Node* createTree(int arr[], int n){
    if(n == 0 || arr[0] == -1)
        return NULL;

    struct Node *root = createNode(arr[0]);
    struct Node *queue[100005];
    int front = 0, rear = 0, i = 1;

    queue[rear++] = root;

    while(front < rear && i < n){
        struct Node *curr = queue[front++];

        if(i < n && arr[i] != -1){
            curr->left = createNode(arr[i]);
            curr->left->parent = curr;
            queue[rear++] = curr->left;
        }
        i++;

        if(i < n && arr[i] != -1){
            curr->right = createNode(arr[i]);
            curr->right->parent = curr;
            queue[rear++] = curr->right;
        }
        i++;
    }

    return root;
}

struct Node* findTarget(struct Node *root, int s){
    if(root == NULL)
        return NULL;

    if(root->data == s)
        return root;

    struct Node *temp = findTarget(root->left, s);
    if(temp != NULL)
        return temp;

    return findTarget(root->right, s);
}

void distanceK(struct Node *root, int s, int k){
    struct Node *target = findTarget(root, s);

    if(target == NULL){
        printf("Target not found.\n");
        return;
    }

    struct Node *queue[100005];
    int front = 0, rear = 0, level = 0;

    queue[rear++] = target;
    target->visited = 1;

    while(front < rear){
        if(level == k)
            break;

        int size = rear - front;

        for(int i = 0; i < size; i++){
            struct Node *curr = queue[front++];

            if(curr->left != NULL && !curr->left->visited){
                curr->left->visited = 1;
                queue[rear++] = curr->left;
            }

            if(curr->right != NULL && !curr->right->visited){
                curr->right->visited = 1;
                queue[rear++] = curr->right;
            }

            if(curr->parent != NULL && !curr->parent->visited){
                curr->parent->visited = 1;
                queue[rear++] = curr->parent;
            }
        }

        level++;
    }

    if(level == k){
        printf("Nodes at distance %d: ", k);
        for(int i = front; i < rear; i++)
            printf("%d ", queue[i]->data);
        printf("\n");
    }
    else{
        printf("No nodes found at distance %d.\n", k);
    }
}

int main(){
    int n, s, k;
    int arr[100005];

    printf("Enter number of elements: ");
    scanf("%d", &n);

    if(n <= 0 || n > 100000){
        printf("Invalid number of elements.\n");
        return 0;
    }

    printf("Enter level-order elements (-1 for NULL): ");
    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    struct Node *root = createTree(arr, n);

    printf("Enter target value: ");
    scanf("%d", &s);

    printf("Enter distance K: ");
    scanf("%d", &k);

    if(k < 0){
        printf("Invalid distance.\n");
        return 0;
    }

    distanceK(root, s, k);

    return 0;
}
