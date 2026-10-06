#include <stdio.h>
#include <string.h>

void removeGroups(char board[]){
    int n=strlen(board);

    for(int i=0;i<n;){
        int j=i;

        while(j<n && board[j]==board[i]){
            j++;
        }

        if(j-i>=3){
            int k=i;

            while(j<n){
                board[k++]=board[j++];
            }

            board[k]='\0';
            n=k;
            i=0;
        }
        else{
            i=j;
        }
    }
}

void insertBall(char board[],char ball,int pos,char result[]){
    int n=strlen(board);

    for(int i=0;i<pos;i++){
        result[i]=board[i];
    }

    result[pos]=ball;

    for(int i=pos;i<n;i++){
        result[i+1]=board[i];
    }

    result[n+1]='\0';
}

int solve(char board[],char hand[]){
    if(strlen(board)==0){
        return 0;
    }

    if(strlen(hand)==0){
        return -1;
    }

    int min=1000;

    for(int h=0;h<strlen(hand);h++){
        if(h>0 && hand[h]==hand[h-1]){
            continue;
        }

        char ball=hand[h];

        for(int pos=0;pos<=strlen(board);pos++){
            if(pos>0 && board[pos-1]==ball){
                continue;
            }

            char newBoard[100];

            insertBall(board,ball,pos,newBoard);
            removeGroups(newBoard);

            char newHand[100];
            int k=0;

            for(int i=0;i<strlen(hand);i++){
                if(i!=h){
                    newHand[k++]=hand[i];
                }
            }

            newHand[k]='\0';

            int result=solve(newBoard,newHand);

            if(result!=-1 && result+1<min){
                min=result+1;
            }
        }
    }

    if(min==1000){
        return -1;
    }

    return min;
}

int main(){
    char board[100];
    char hand[100];

    printf("Enter board: ");
    scanf("%99s",board);

    printf("Enter hand: ");
    scanf("%99s",hand);

    int result=solve(board,hand);

    printf("Minimum number of balls required: %d\n",result);

    return 0;
}