
//程序有时候会出错
#include<stdio.h>
void swap(int* x,int* y);
int main(){

    printf("请输入四位数整数!");
    int num, a[4];
    scanf("%d",&num);
    if(num/1000<1){printf("输入的数字不符合要求！\n");}
    else{
        for(int i = 3;i>=0;i--){   //分离数字
            a[i] = num%10;
            num = num/10;
        }
        for(int i = 4;i>0;i--){   //冒泡排序
            //int flag = 0;
            for(int j = 0;j<i;j++){
                if(a[j]>a[j+1]){
                    swap(&a[j],&a[j+1]);
                   // flag++;
                }
            }
            //if(flag == 0) break;
        }
        printf("排序后升序显示：");  //打印显示
        for(int i = 0;i<4;i++){
        printf("\t%d,",a[i]);
    }
    printf("\n");
    int num2 = a[3]*10+a[1];      //合并数字
    printf("新组成的数字：%d",num2);
    }
    return 0;
}


void swap(int* x,int* y){     //地址传递
                                //c好像不能用引用 &a = b ==> *a = &b 代替;
    int t = *x;
    *x = *y;
    *y = t;
}