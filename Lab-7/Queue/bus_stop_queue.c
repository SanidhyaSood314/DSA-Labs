#include <stdio.h>

#define MAX 100

int maxLength(int stress[],int n,int K){
    int maxDeque[MAX];
    int minDeque[MAX];

    int maxFront=0,maxRear=-1;
    int minFront=0,minRear=-1;

    int left=0;
    int answer=0;

    for(int right=0;right<n;right++){
        while(maxRear>=maxFront && stress[maxDeque[maxRear]]<=stress[right]){
            maxRear--;
        }

        maxDeque[++maxRear]=right;

        while(minRear>=minFront && stress[minDeque[minRear]]>=stress[right]){
            minRear--;
        }

        minDeque[++minRear]=right;

        while(stress[maxDeque[maxFront]]-stress[minDeque[minFront]]>K){
            if(maxDeque[maxFront]==left){
                maxFront++;
            }

            if(minDeque[minFront]==left){
                minFront++;
            }

            left++;
        }

        int length=right-left+1;

        if(length>answer){
            answer=length;
        }
    }

    return answer;
}

int main(){
    int stress[MAX];
    int n,K;

    printf("Enter number of elements: ");
    scanf("%d",&n);

    printf("Enter stress values: ");

    for(int i=0;i<n;i++){
        scanf("%d",&stress[i]);
    }

    printf("Enter K: ");
    scanf("%d",&K);

    int answer=maxLength(stress,n,K);

    printf("Maximum length = %d\n",answer);

    return 0;
}