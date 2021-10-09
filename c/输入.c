#include<stdio.h>
int main(){
    int x,sum,max;
    int n = 0;
    float average;
    printf("请输入一组整数，以0为结束：");
    printf("输入第%d个整数：",n+1);
    scanf("%d",&x);
    max = x;
    sum = 0;

    while(x!=0){
        sum +=x;
        n++;
        if(max<x){
            max = x;
        }
        printf("输入第%d个整数：",n);
        scanf("%d",&x);

    }
    if(n!=0){
    average = (float)sum/n;
    printf("平均数：%f\n",average);
    printf("sum:%d,N:%d\n",sum,n);
    printf("max:%d\n",max);
    printf("%f",(float)n);}
    else printf("未输入有效数据！");
    return 0;
}