#include<stdio.h>
#define max 100
int queue[max];
int front = -1;
int rear = -1;

void enqueue(int val){
    if(rear == max - 1){
        printf("Overflow condition\n");
        return;
    }
    if(front == -1){
        front = 0;
    }
    rear++;
    queue[rear] = val;
}

int dequeue(){
    if(front == -1 || front == rear + 1){
        printf("Underflow condition\n");
        return;
    }
       int x = queue[front];
      front ++;
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
}