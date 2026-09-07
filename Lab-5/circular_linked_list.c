#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* link;
};

void print(struct node* start){
    struct node* ptr= start;
    printf("%d ",ptr->data);
    ptr = ptr->link;
    while(ptr!= start){
        printf("%d ",ptr->data);
        ptr = ptr->link;
    }
    printf("\n");
}

struct node* insertAtBeginning(struct node* start, int ele){
    struct node* tmp = (struct node*) malloc(sizeof(struct node));
    tmp-> data = ele;
    tmp-> link = start;
    start = tmp;
    struct node* ptr;
    ptr = start ->link;
    while(ptr->link != start->link){
        ptr = ptr->link;
    }
    ptr ->link = start;

    return start;
}

struct node* insertInBetween(struct node* start, int ele, int pos){
    struct node* tmp = (struct node*) malloc(sizeof(struct node));
    tmp-> data = ele;

    if(pos == 1) return insertAtBeginning(start,ele);
    struct node* ptr = start;
    int cnt = 0;
    while(ptr -> link  != start ){
        cnt ++;
        if(cnt == pos-1){
            tmp-> link = ptr -> link;
            ptr -> link = tmp;
            return start; 
        }
        ptr = ptr -> link;
    }
    if(cnt + 2 == pos){
        tmp -> link = ptr->link;
        ptr -> link = tmp;
    }
    return start;
}


struct node* insertAtLast(struct node* start,int ele){
    struct node* tmp = (struct node*) malloc(sizeof(struct node));
    tmp -> data = ele;
    struct node* ptr = start;
    while(ptr->link != start){
        ptr = ptr -> link;
    }
    tmp -> link = ptr -> link;
    ptr -> link = tmp;
    return start;
}

struct node* deleteAtBeginning(struct node* start){
    struct node* tmp = start, *ptr = start;
    start = start -> link;
    while(ptr->link != tmp){
        ptr = ptr -> link;
    }
    ptr -> link = start;
    free(tmp);
    return start;
}

struct node* deleteinBetween(struct node* start, int pos){
    struct node* ptr = start, *ptr1;
    if(pos == 1) return deleteAtBeginning(start);
    int cnt = 1;
    while(ptr->link != start){
        ptr1 = ptr;
        ptr = ptr -> link;
        cnt ++;

        if(cnt == pos){
            ptr1 -> link = ptr -> link;
            free(ptr);
            return start;
        }
    }
    return start;
}

struct node* deleteAtLast(struct node* start){
    struct node* ptr = start, * ptr1;
    while(ptr->link != start){
        ptr1 = ptr;
        ptr = ptr -> link;
    }
    ptr1 -> link = ptr -> link;
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
        tmp -> link = NULL;
        
        if(start == NULL){
            start = tmp;
            ptr = tmp;
        }
        else{
            ptr->link = tmp;
            ptr = tmp;
        }
    }
    ptr -> link = start;


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
    start = deleteinBetween(start,k2);
    print(start);

    printf("Element at end is deleted now\n");
    start = deleteAtLast(start);
    print(start);
}