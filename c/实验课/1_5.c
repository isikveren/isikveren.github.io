#include<stdio.h>
#include<math.h>

int issushu(int num){   //判断素数函数 是返回1 否返回0
    int a=0;    //能被除个数
   
    int k=sqrt( (double)num );
    for(int i=2;i<=k;i++){
        if(num%i==0){
            a++;  
        }
    }
    if(a==0&&num>1){
        return 1;
    }else{
        return 0;
    }
}
int main(){
    int num,i = 1,sum = 0;
    while(1){
        printf("请输入第%d个整数:",i++);
        scanf("%d",&num);
        if(num == 0||sum>=100) break;
        if(issushu(num))  sum +=num;
    }
    printf("素数的累加和是:%d\n",sum);
    return 0;
}