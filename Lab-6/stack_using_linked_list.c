#include<stdio.h>
#include<stdlib.h>


struct node{
    int data;
    struct node* link;
};

struct node* top_idx = NULL;

void push(int x){
    struct node* newNode = (struct node*) malloc(sizeof(struct node));
    if(newNode == NULL){
        printf("Stack Overflow");
    }
    else{
        newNode -> data = x;
        newNode -> link = top_idx;
        top_idx = newNode;
    }
}

void pop(){
    if(top_idx == NULL){
        printf("Stack Underflow");
    }
    else{
        struct node* tmp = top_idx;
        top_idx = top_idx -> link;
        free(tmp);
    }
}

int top(){
    if(top_idx == NULL){
        printf("Stack is empty");
    }
    else{
        return top_idx->data;
    }
}


void print(){
    if(top_idx == NULL){
        printf("Stack is empty");
    }
    else{
        struct node* tmp = top_idx;
        while(tmp != NULL){
            printf("%d ",tmp->data);
            tmp = tmp->link;
        }
        printf("\n");
    }
}

int main(){
    int n;

    printf("Enter number of elements: ");
    scanf("%d",&n);

    for(int i=0; i<n; i++){
        int ele;
        scanf("%d", &ele);
        push(ele);
    }
    printf("%d", top());
    printf("\n");
    print();

    pop();
    print();
    return 0;
}