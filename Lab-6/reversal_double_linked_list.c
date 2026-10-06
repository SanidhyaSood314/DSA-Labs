#include<stdio.h>
#include<stdlib.h>


struct node{
    int data;
    struct node* next;
    struct node* prev;
};

void print(struct node* start){
    struct node* ptr = start;
    while(ptr != NULL){
        printf("%d ", ptr->data);
        ptr = ptr -> next;
    }
    printf("\n");
}

struct node* reverseDoublyLL(struct node* start){
    struct node*curr= start, *tmp = NULL;
    while(curr != NULL){
        tmp = curr -> prev;
        curr -> prev = curr-> next;
        curr -> next = tmp;
        curr = curr->prev;
    }
    return tmp->prev;

}


int main(){
    int n;
    struct node* tmp,*start = NULL,*ptr;

    printf("Enter the number of elements: ");
    scanf("%d",&n);

    for(int i=0; i<n;i++){
        tmp = (struct node*) malloc(sizeof(struct node));
        scanf("%d",&tmp->data);
        tmp -> next = NULL;
        tmp -> prev = NULL;
        if(start== NULL){
            start = tmp;
            ptr = tmp;
        }
        else{
            tmp -> prev = ptr;
            ptr -> next = tmp;
            ptr = tmp;
        }
    }

    print(start);

    start = reverseDoublyLL(start);
    print(start);
    return 0;
}