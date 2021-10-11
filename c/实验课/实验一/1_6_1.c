#include<stdio.h>

int main(){
    char c = 'A';
    int j = 1,x,t = j,t2 = 3;
    for(int i = 1;i<=16;i++){
      if(i == 1){
          for(int i2 = t2;i2>0;i2--){
            printf(" ");
        }
      }
        if(i%6<=3)  printf("%c",c);
        else printf("%c",c+32);
        if(i%3!=0)  c++;  
        else c = c-2;
    
        if(i%t == 0){
            
            printf("\n");
            j+=2;
            t+=j;
            t2--;
        for(int i2 = t2;i2>0;i2--){
            printf(" ");
        }
        }
        }
    
    return 0;
}