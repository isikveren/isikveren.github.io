#include<stdio.h>

int main(){

    int i = 1,sum = 0;
    int N; 
    printf("请输入N：");
    scanf("%d",&N);
   
    while(i<=N){
        sum+=i++;
    }
    if(N>=4){
    printf("1+2+……+%d = %d\n",N,sum);
    }
    if(N==1){
        printf("%d = %d\n",N,sum);
    }
    if(N==2){
        printf("1+%d = %d\n",N,sum);
    }
    if(N==3){
        printf("1+2+%d = %d\n",N,sum);
    }
    return 0;

}
