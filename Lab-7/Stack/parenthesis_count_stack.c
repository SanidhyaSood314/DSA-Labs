#include <stdio.h>

int parentheses_count(char st[]){
    int stack[100];
    int top = -1;
    int max_stack_size = 0;
    int length = 0;
    int max_length = 0;

    for (int i = 0; st[i] != '\0'; i++){
        if (st[i] == '('){
            stack[++top] = i;

            if (top + 1 > max_stack_size){
                max_stack_size = top + 1;
            }
        }
        else if (st[i] == ')'){
            if (top == -1){
                printf("Invalid ')' at index %d\n", i);
            }
            else{
                top--;
                length += 2;

                if (length > max_length){
                    max_length = length;
                }
            }
        }
    }

    while (top != -1){
        printf("Invalid '(' at index %d\n", stack[top]);
        top--;
    }

    printf("Maximum stack size = %d\n", max_stack_size);

    return max_length;
}

int main(){
    char st[100];

    printf("Enter the string containing '(' and ')': ");
    scanf("%99s", st);

    int len = parentheses_count(st);

    printf("Length of longest valid parentheses substring = %d\n", len);

    return 0;
}   