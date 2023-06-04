#include<stdio.h>
int n,capacity,m[20][20],x[20],w[20],v[20];
int max(int a,int b)
{
	if(a>b)
		return a;
	else
		return b;
}
void getsubset()
{
	int i=n,j=capacity;
	while(i!=0 && j!=0)
	{
		if(m[i][j]!=m[i-1][j])
		{
			x[i]=1;
			j=j-w[i];
		}
		i--;
	}
}
void knapsack()
{
	int i,j;
	for(i=0;i<=n;i++)
	{
		for(j=0;j<=capacity;j++)
		{
			if(i==0 || j==0)
				m[i][j]=0;
			else if(j<w[i])
				m[i][j]=m[i-1][j];
			else
				m[i][j]=max(m[i-1][j],v[i]+m[i-1][j-w[i]]);
		}
	}
}
int main()
{
	int i;
	printf("Enter no. of item : ");
	scanf("%d",&n);
	printf("Enter capacity of knapsack : ");
	scanf("%d",&capacity);
	for(i=0;i<n;i++)
		scanf("%d%d",&w[i],&v[i]);
	knapsack();
	getsubset();
	for(i=0;i<n;i++)
	{
		if(x[i]==1)
			printf("%d\t%d\t%d\n",i+1,w[i],v[i]);
	}
	printf("Maximum profit is %d",m[n][capacity]);
	return 0;
}
