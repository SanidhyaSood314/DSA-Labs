#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    int arr[n];
    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    int min = arr[0];
    int minidx = 0;
    int maxProfit = 0;
    int buyDay = 0;
    int sellDay = 0;

    for(int i = 1; i < n; i++)
    {
        if(arr[i] - min > maxProfit)
        {
            maxProfit = arr[i] - min;
            buyDay = minidx;
            sellDay = i;
        }

        if(arr[i] < min)
        {
            min = arr[i];
            minidx = i;
        }
    }

    printf("Buy on Day %d at price %d\n", buyDay, arr[buyDay]);
    printf("Sell on Day %d at price %d\n", sellDay, arr[sellDay]);
    printf("Maximum Profit = %d", maxProfit);
    

    return 0;
}