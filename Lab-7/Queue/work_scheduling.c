#include <stdio.h>

#define MAX 100

void sort(int arr[],int n){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
}

int canComplete(int tasks[],int n,int workers[],int m,int pills,int strength,int count){
    int used[MAX]={0};
    int remainingPills=pills;

    for(int i=count-1;i>=0;i--){
        int assigned=0;

        for(int j=m-1;j>=0;j--){
            if(used[j]){
                continue;
            }

            if(workers[j]>=tasks[i]){
                used[j]=1;
                assigned=1;
                break;
            }
        }

        if(assigned){
            continue;
        }

        if(remainingPills==0){
            return 0;
        }

        for(int j=0;j<m;j++){
            if(!used[j] && workers[j]+strength>=tasks[i]){
                used[j]=1;
                remainingPills--;
                assigned=1;
                break;
            }
        }

        if(!assigned){
            return 0;
        }
    }

    return 1;
}

int main(){
    int tasks[MAX],workers[MAX];
    int n,m,pills,strength;

    printf("Enter number of tasks: ");
    scanf("%d",&n);

    printf("Enter tasks: ");
    for(int i=0;i<n;i++){
        scanf("%d",&tasks[i]);
    }

    printf("Enter number of workers: ");
    scanf("%d",&m);

    printf("Enter workers: ");
    for(int i=0;i<m;i++){
        scanf("%d",&workers[i]);
    }

    printf("Enter number of pills: ");
    scanf("%d",&pills);

    printf("Enter strength of each pill: ");
    scanf("%d",&strength);

    sort(tasks,n);
    sort(workers,m);

    int answer=0;

    for(int count=1;count<=n && count<=m;count++){
        if(canComplete(tasks,n,workers,m,pills,strength,count)){
            answer=count;
        }
        else{
            break;
        }
    }

    printf("Maximum number of tasks completed = %d\n",answer);

    return 0;
}