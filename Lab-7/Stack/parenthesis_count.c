#include <stdio.h>
#include <string.h>

int parentheses_count(char st[]){
    int count = 0;
    int length = 0;
    int max_length = 0;
    int flag = 0;

    for (int i = 0; st[i] != '\0'; i++){
        if (st[i] == '('){
            count++;
        }
        else{
            count--;

            if (count < 0){
                count = 0;
                length = 0;
                flag = 1;
            }
            else{
                length += 2;
                if (length > max_length){
                    max_length = length;
                }
            }
        }
    }
    if (flag){
        printf("Invalid String");
    }
    return max_length;
}

int main()
{
    char st[100];

    printf("Enter the string containing '(' and ')': ");
    scanf("%99s", st);
    int len = parentheses_count(st);
    printf("Length of longest valid parentheses substring = %d\n", len);

    return 0;
}