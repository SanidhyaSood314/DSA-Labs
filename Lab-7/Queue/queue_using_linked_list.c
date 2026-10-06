#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* link;
};

struct Node* front = NULL;
struct Node* rear = NULL;

void enqueue(int val){
    struct Node* temp = (struct Node*) malloc(sizeof(struct Node));
    if(temp == NULL){
        printf("Overflow condition");
        return;
    }

    temp -> data = val;
    temp -> link = NULL;

    if(front == NULL){
        front = temp;
        rear = temp;
    }

    else{
        rear -> link = temp;
        rear = temp;
    }
}

int dequeue(){
    if(front == NULL){
        printf("Underflow Condition\n");
        return INT_MAX;
    }
    struct Node* temp = front;
    front = front -> link;
    int x = temp -> data;
    free(temp);
    return x;
}

int main(){
    dequeue();
    enqueue(10);
    enqueue(20);
    enqueue(30);
    dequeue();
    dequeue();
    dequeue();
    dequeue();
    enqueue(100);
    dequeue();
    return 0;
}