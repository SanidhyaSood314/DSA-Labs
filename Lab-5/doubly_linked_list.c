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
        printf("%d ",ptr -> data);
        ptr = ptr -> next;
    }
    printf("\n");
}

struct node* insertAtBeginning(struct node* start, int ele){
    struct node* tmp = (struct node*) malloc(sizeof(struct node));
    tmp -> data = ele;
    tmp -> next = start;
    start -> prev = tmp;
    start = tmp;
    return start;
}

struct node* insertInBetween(struct node* start,int ele, int pos){
    struct node* tmp = (struct node*) malloc(sizeof(struct node));
    tmp -> data = ele;

    if(pos == 1) return insertAtBeginning(start,ele);
    struct node* ptr = start;
    int cnt = 0;
    while(ptr!= NULL){
        cnt ++;
        if(cnt == pos -1){
            tmp -> next = ptr -> next;
            ptr -> next = tmp;
            tmp -> prev = ptr;
            tmp->next->prev = tmp; 
            return start;
        }
        ptr = ptr-> next;
    }
    return start;
}


struct node* insertAtLast(struct node* start, int ele){
    struct node* tmp = (struct node*) malloc(sizeof(struct node));
    tmp -> data = ele;

    struct node* ptr = start;
    while(ptr->next != NULL){
        ptr = ptr -> next;
    }

    ptr -> next = tmp;
    tmp -> prev = ptr;
    tmp -> next = NULL;

    return start;
}

struct node* deleteAtBeginning(struct node* start){
    struct node* tmp = start;
    start = start -> next;
    start -> prev = NULL;
    free(tmp);
    return start;
}


struct node* deleteInBetween(struct node* start, int pos){
    struct node* ptr = start, *ptr1;
    if(pos == 1) return deleteAtBeginning(start);
    int cnt = 1;
    while(ptr->next!= NULL){
        ptr1 = ptr;
        ptr = ptr -> next;
        cnt ++;

        if(cnt == pos){
            ptr ->next ->prev = ptr1;
            ptr1 -> next = ptr-> next;
            free(ptr);
            return start;
        }
    }
    return start;
}

struct node* deleteAtLast(struct node* start){
    struct node* ptr = start, *ptr1;
    while(ptr->next != NULL){
        ptr1 = ptr;
        ptr = ptr->next;
    }
    ptr1 -> next = NULL;
    free(ptr);
    return start;    
}

int main(){
    int n, ele;
    struct node* start = NULL, *tmp, *ptr;

    printf("Enter number of elements: ");
    scanf("%d",&n);


    for(int i=0; i<n;i++){
        tmp = (struct node*) malloc(sizeof(struct node));
        scanf("%d",&tmp->data);
        tmp -> next = NULL;
        
        if(start == NULL){
            start = tmp;
            ptr = tmp;
            start -> prev = NULL;
        }
        else{
            ptr->next = tmp;
            tmp -> prev = ptr;
            ptr = tmp;

        }
    }

    print(start);

    int ele1;
    printf("Enter the element to be inserted in the beginning: ");
    scanf("%d",&ele1);
    start = insertAtBeginning(start,ele1);
    print(start);

    int ele2,k;
    printf("Enter the element to be inserted in between: ");
    scanf("%d",&ele2);
    printf("Enter the position where element is to be inserted: ");
    scanf("%d", &k);
    start = insertInBetween(start,ele2,k);
    print(start);

    int ele3;
    printf("Enter the element to be inserted at the last: ");
    scanf("%d",&ele3);
    start = insertAtLast(start,ele3);
    print(start);

    printf("Element at beginning is deleted now\n");
    start = deleteAtBeginning(start);
    print(start);

    int k2;
    printf("Enter the position which element is to be deleted: ");
    scanf("%d",&k2);
    start = deleteInBetween(start,k2);
    print(start);

    printf("Element at end is deleted now\n");
    start = deleteAtLast(start);
    print(start);

    return 0;
}