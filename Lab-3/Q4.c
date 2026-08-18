#include <stdio.h>
int main()
{
    int n;
    scanf("%d", &n);

    int arr[n];

    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    int totalSum = 0;

    for(int i = 0; i < n; i++)
        totalSum += arr[i];
    int leftSum = 0;
    printf("Equilibrium Index: ");
    for(int i = 0; i < n; i++)
    {
        totalSum -= arr[i];  
        if(leftSum == totalSum){
            printf("%d ", i);
        }

        leftSum += arr[i];
    }

    return 0;
}