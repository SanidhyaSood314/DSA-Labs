#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* link;
};


void print(struct node* start){
    struct node* ptr = start;

    printf("%d ", ptr->data);
    ptr = ptr -> link;
    while(ptr!= start){
        printf("%d ", ptr->data);
        ptr = ptr->link;
    }
    printf("\n");
}

struct node* reverseCircularLL(struct node* start){
    struct node* curr = start, *next, * prev = NULL;

    next = curr -> link;
    curr -> link = prev;
    prev = curr;
    curr = next;
    while(curr != start){
        next = curr -> link;
        curr -> link = prev;
        prev = curr;
        curr = next;
    }
    curr -> link = prev;
    return prev;
}

int main(){
    int n;
    struct node* start= NULL, *tmp, *ptr;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    for(int i=0; i<n;i++){
        tmp = (struct node*) malloc(sizeof(struct node));
        scanf("%d",&tmp->data);
        tmp -> link = NULL;

        if(start == NULL){
            start = tmp;
            ptr = tmp;
        }
        else{
            ptr-> link = tmp;
            ptr = tmp;
        }
    }
    ptr -> link = start;

    print(start);
    start = reverseCircularLL(start);
    print(start);
    return 0;
}