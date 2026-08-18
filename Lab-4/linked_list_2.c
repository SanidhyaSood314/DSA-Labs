#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* link;
};

void beginning(struct node** ptr_to_start){
    struct node* tmp;

    tmp = *ptr_to_start;
    *ptr_to_start = tmp->link;

    free(tmp);
}

void ending(struct node* start){
    struct node *ptr;

    ptr = start;

    while(ptr->link->link != NULL){
        ptr = ptr->link;
    }
    free(ptr->link);
    ptr->link = NULL;
}

void inbetween(struct node* start){
    struct node *slow, *fast, *tmp;

    slow = start;
    fast = start->link;

    while(fast->link != NULL && fast->link->link != NULL){
        fast = fast->link->link;
        slow = slow->link;
    }

    tmp = slow->link;
    slow->link = tmp->link;

    free(tmp);
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

    // Delete the element at the beginning
    beginning(&start);

    // Delete the element at the end
    ending(start);

    // Delete the element in between
    inbetween(start);

    // Printing the linked list
    ptr = start;

    while(ptr != NULL){
        printf("%d ", ptr->data);
        ptr = ptr->link;
    }

    return 0;
}