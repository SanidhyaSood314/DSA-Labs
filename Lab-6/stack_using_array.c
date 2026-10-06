#include <stdio.h>
#define max 100
int stack[max];
int top_idx = -1;


void push(int x){
    if (top_idx == max - 1){
        printf("Stack Overflow");
    }
    else{
        top_idx ++;
        stack[top_idx] = x;
    }
}

void pop(){
    if(top_idx == -1){
        printf("Stack Underflow");
    }
    else{
        int x = stack[top_idx];
        top_idx --;
    }
}

int top(){
    if(top_idx == -1){
        printf("Stack is empty");
        return -1;
    }
    else{
        return stack[top_idx];
    }
}

void print(){
    if(top_idx == -1){
        printf("Stack is empty");
    }
    else{
        for(int i= top_idx; i>=0; i--){
            printf("%d ", stack[i]);
        }
    }
    printf("\n");
}

int main(){
    int n;

    printf("Enter number of elements: ");
    scanf("%d",&n);

    for(int i=0; i<n;i++){
        int ele;
        scanf("%d", &ele);
        push(ele);
    }
    printf("%d",top());
    printf("\n");
    print();

    pop();
    print();

    return 0;
}