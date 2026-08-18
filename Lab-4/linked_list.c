#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* link;
};

void beginning(struct node** ptr_to_start, int ele){
    struct node* tmp;
    tmp = (struct node*) malloc(sizeof(struct node));
    tmp->data = ele;
    tmp->link = *ptr_to_start;
    *ptr_to_start = tmp;
}

void ending(struct node* start, int ele){
    struct node* tmp, *ptr;
    tmp = (struct node*) malloc(sizeof(struct node));
    tmp->data = ele;
    tmp->link = NULL;

    ptr = start;
    while(ptr->link != NULL){
        ptr = ptr->link;
    }
    ptr->link = tmp;
}

void inbetween(struct node* start, int ele){
    struct node *tmp, *slow, *fast;

    slow = start;
    fast = start;

    tmp = (struct node*) malloc(sizeof(struct node));
    tmp->data = ele;

    while(fast != NULL && fast->link != NULL){
        fast = fast->link->link;
        slow = slow->link;
    }

    tmp->link = slow->link;
    slow->link = tmp;
}

int main(){
    printf("Enter the number of elements in the linked list: ");

    int n;
    scanf("%d",&n);

    struct node *ptr, *tmp, *start;
    start = NULL;
    ptr = NULL;

    for(int i = 0; i < n; i++){
        tmp = (struct node*) malloc(sizeof(struct node));

        scanf("%d",&tmp->data);
        tmp->link = NULL;

        if(start == NULL){
            start = tmp;
            ptr = tmp;
        }
        else{
            ptr->link = tmp;
            ptr = tmp;
        }
    }

    // Insert the element at the beginning
    printf("Enter the element to be inserted at the beginning: ");

    int ele;
    scanf("%d",&ele);

    beginning(&start, ele);

    // Insert the element at the end
    printf("Enter the element to be inserted at the end: ");
    scanf("%d",&ele);

    ending(start, ele);

    // Insert the element in between
    printf("Enter the element to be inserted in between: ");
    scanf("%d",&ele);

    inbetween(start, ele);

    // Printing the linked list
    ptr = start;

    while(ptr != NULL){
        printf("%d ", ptr->data);
        ptr = ptr->link;
    }

    return 0;
}