#include<stdio.h>
#include<math.h>
//#include<conio.h>
int main()
{
	int n;
	double sum=0.0,nume,deno,term;
	printf("请输入一个数：");
	scanf("%d",&n);
	term=0.25;
	while(term>0.001)
	{
		nume=2*n-1;
	    deno=(2*n)*(2*n);
		term=nume/deno;
		sum=sum+term;
		n++;
	}
	n=n-1;
	printf("n=%d,sum=%f\n",n,sum);
	//getch();
	return 0;
}