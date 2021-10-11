#include <stdio.h>
#include<math.h>

int issushu(int num){
    int a=0;    //能被除个数
    int k=(int)sqrt( (double)num );
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
    int x;
    scanf("%d",&x);
    printf("%d",issushu(x));
    return 0;
}
