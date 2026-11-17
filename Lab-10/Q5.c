
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node{
    int data;
    struct Node *left;
    struct Node *right;
    int lthread;
    int rthread;
};

struct Node* insert(struct Node *root, int ele){
    if(root == NULL){
        struct Node *tmp = malloc(sizeof(struct Node));
        if(tmp == NULL){
            printf("Memory allocation failed\n");
            exit(1);
        }
        tmp->data = ele;
        tmp->left = NULL;
        tmp->right = NULL;
        tmp->lthread = 0;
        tmp->rthread = 0;
        return tmp;
    }
    if(ele < root->data)
        root->left = insert(root->left, ele);
    else if(ele > root->data)
        root->right = insert(root->right, ele);
    return root;
}

void convert(struct Node *root, struct Node **prev){
    if(root == NULL)
        return;

    if(root->lthread == 0)
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

struct Node* findNode(struct Node *root, int x){
    while(root != NULL){
        if(x == root->data)
            return root;
        if(x < root->data){
            if(root->lthread == 1)
                return NULL;
            root = root->left;
        }
        else{
            if(root->rthread == 1)
                return NULL;
            root = root->right;
        }
    }
    return NULL;
}

struct Node* leftMost(struct Node *root){
    if(root == NULL)
        return NULL;
    while(root->lthread == 0)
        root = root->left;
    return root;
}

struct Node* rightMost(struct Node *root){
    if(root == NULL)
        return NULL;
    while(root->rthread == 0)
        root = root->right;
    return root;
}

struct Node* successor(struct Node *root){
    if(root == NULL)
        return NULL;
    if(root->rthread == 1)
        return root->right;
    return leftMost(root->right);
}

struct Node* predecessor(struct Node *root){
    if(root == NULL)
        return NULL;
    if(root->lthread == 1)
        return root->left;
    return rightMost(root->left);
}

struct Node* lowerBound(struct Node *root, int x){
    struct Node *ans = NULL;

    while(root != NULL){
        if(root->data >= x){
            ans = root;
            if(root->lthread == 1)
                break;
            root = root->left;
        }
        else{
            if(root->rthread == 1)
                return root->right;
            root = root->right;
        }
    }
    return ans;
}

void nextValue(struct Node *root, int x){
    struct Node *tmp = findNode(root, x);

    if(tmp == NULL)
        printf("NEXT %d = NULL\n", x);
    else{
        tmp = successor(tmp);
        if(tmp == NULL)
            printf("NEXT %d = NULL\n", x);
        else
            printf("NEXT %d = %d\n", x, tmp->data);
    }
}

void prevValue(struct Node *root, int x){
    struct Node *tmp = findNode(root, x);

    if(tmp == NULL)
        printf("PREV %d = NULL\n", x);
    else{
        tmp = predecessor(tmp);
        if(tmp == NULL)
            printf("PREV %d = NULL\n", x);
        else
            printf("PREV %d = %d\n", x, tmp->data);
    }
}

void rangeValue(struct Node *root, int l, int r){
    struct Node *curr = lowerBound(root, l);
    int first = 1;

    printf("RANGE = [");

    while(curr != NULL && curr->data <= r){
        if(first == 0)
            printf(", ");
        printf("%d", curr->data);
        first = 0;
        curr = successor(curr);
    }

    printf("]\n");
}

void kthSmallest(struct Node *root, int n, int k){
    if(k <= 0 || k > n){
        printf("KTH %d = NULL\n", k);
        return;
    }

    struct Node *curr = leftMost(root);

    for(int i = 1; i < k; i++)
        curr = successor(curr);

    printf("KTH %d = %d\n", k, curr->data);
}

int main(){
    int n, ele, q, x, l, r, k;
    char op[20];
    struct Node *root = NULL;
    struct Node *prev = NULL;

    printf("Enter number of scores: ");
    scanf("%d", &n);

    if(n <= 0){
        printf("Invalid number of scores.\n");
        return 0;
    }

    printf("Enter scores: ");
    for(int i = 0; i < n; i++){
        scanf("%d", &ele);
        root = insert(root, ele);
    }

    convert(root, &prev);

    if(prev != NULL){
        prev->right = NULL;
        prev->rthread = 1;
    }

    printf("Enter number of queries: ");
    scanf("%d", &q);

    for(int i = 0; i < q; i++){
        scanf("%s", op);

        if(strcmp(op, "NEXT") == 0){
            scanf("%d", &x);
            nextValue(root, x);
        }
        else if(strcmp(op, "PREV") == 0){
            scanf("%d", &x);
            prevValue(root, x);
        }
        else if(strcmp(op, "RANGE") == 0){
            scanf("%d%d", &l, &r);
            rangeValue(root, l, r);
        }
        else if(strcmp(op, "KTH") == 0){
            scanf("%d", &k);
            kthSmallest(root, n, k);
        }
    }

    return 0;
}
