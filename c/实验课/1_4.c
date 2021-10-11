#include<stdio.h>

int main(){
    long int x,y = 0;
    printf("请输入一个长整数：");
    scanf("%ld",&x);
    int t,i = 1;
    while(x!=0){
        t = x%10;
        x /=10;
        if(t%2 == 0)
        {
            y  +=t*i;
            i *=10;
        }
    }
    if(y!=0)    printf("%ld\n",y);
    else printf("为空\n");
    return 0;
}