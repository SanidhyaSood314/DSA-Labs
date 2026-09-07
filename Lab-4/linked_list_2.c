#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *link;
};

void beginning(struct node **start) {
    struct node *tmp = *start;
    *start = tmp->link;
    free(tmp);
}

void ending(struct node *start) {
    struct node *ptr = start;

    while (ptr->link->link)
        ptr = ptr->link;

    free(ptr->link);
    ptr->link = NULL;
}

void inbetween(struct node *start) {
    struct node *slow = start, *fast = start->link, *tmp;

    while (fast->link && fast->link->link) {
        fast = fast->link->link;
        slow = slow->link;
    }

    tmp = slow->link;
    slow->link = tmp->link;
    free(tmp);
}

int main() {
    int n;
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

    beginning(&start);
    ending(start);
    inbetween(start);

    for (ptr = start; ptr; ptr = ptr->link)
        printf("%d ", ptr->data);

    return 0;
}