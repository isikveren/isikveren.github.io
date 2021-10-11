#include<stdio.h>

int main(){
    int x,y;
    printf("请输入x:");
    scanf("%d",&x);
    if(x<10)    y = x*x;
    else if(x<=20)  y = 2*x +5;
    else    y = x*3 -7;
    printf("y = %d",y);
    return 0;
}