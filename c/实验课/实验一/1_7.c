#include<stdio.h>

int main(){
    int n = 1;
    double s = 0,d,d1,d2;
    while(1){

        d1 = 2*n-1;
        d2 = (2*n)*(2*n);
        d = d1/d2;
        s+=d;
        if(d<=0.001) break;
        n++;
    }
       printf("n = %d, s = %lf\n",n,s);
    return 0;
}