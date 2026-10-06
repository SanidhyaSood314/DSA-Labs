#include <stdio.h>
#include <string.h>
#include <ctype.h>

int precedence(char ch){
    if(ch=='^'){
        return 3;
    }
    if(ch=='*' || ch=='/' || ch=='%'){
        return 2;
    }
    if(ch=='+' || ch=='-'){
        return 1;
    }
    return 0;
}

void infixToPostfix(char infix[],char postfix[]){
    char stack[100];
    int top=-1;
    int k=0;

    for(int i=0;infix[i]!='\0';i++){
        char ch=infix[i];

        if(isalnum(ch)){
            postfix[k++]=ch;
        }
        else if(ch=='('){
            stack[++top]=ch;
        }
        else if(ch==')'){
            while(top!=-1 && stack[top]!='('){
                postfix[k++]=stack[top--];
            }

            if(top!=-1){
                top--;
            }
        }
        else{
            while(top!=-1 && stack[top]!='(' &&
                  precedence(stack[top])>=precedence(ch)){
                postfix[k++]=stack[top--];
            }

            stack[++top]=ch;
        }
    }

    while(top!=-1){
        postfix[k++]=stack[top--];
    }

    postfix[k]='\0';
}

int main(){
    char infix[100];
    char postfix[100];

    printf("Enter infix expression: ");
    scanf("%99s",infix);

    infixToPostfix(infix,postfix);

    printf("Postfix expression: %s\n",postfix);

    return 0;
}   