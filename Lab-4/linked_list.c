#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *link;
};

void beginning(struct node **start, int ele) {
    struct node *tmp = malloc(sizeof(struct node));
    tmp->data = ele;
    tmp->link = *start;
    *start = tmp;
}

void ending(struct node *start, int ele) {
    struct node *tmp = malloc(sizeof(struct node));
    tmp->data = ele;
    tmp->link = NULL;

    while (start->link)
        start = start->link;

    start->link = tmp;
}

void inbetween(struct node *start, int ele) {
    struct node *tmp = malloc(sizeof(struct node));
    struct node *slow = start, *fast = start;

    tmp->data = ele;

    while (fast && fast->link) {
        slow = slow->link;
        fast = fast->link->link;
    }

    tmp->link = slow->link;
    slow->link = tmp;
}

int main() {
    int n, ele;
    struct node *start = NULL, *ptr, *tmp;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        tmp = malloc(sizeof(struct node));
        scanf("%d", &tmp->data);
        tmp->link = NULL;

        if (!start)
            start = ptr = tmp;
        else {
            ptr->link = tmp;
            ptr = tmp;
        }
    }

    printf("Element at beginning: ");
    scanf("%d", &ele);
    beginning(&start, ele);

    printf("Element at end: ");
    scanf("%d", &ele);
    ending(start, ele);

    printf("Element in between: ");
    scanf("%d", &ele);
    inbetween(start, ele);

    for (ptr = start; ptr; ptr = ptr->link)
        printf("%d ", ptr->data);

    return 0;
}