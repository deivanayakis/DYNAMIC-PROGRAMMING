#include<stdio.h>
int g[10][10],n;
int min(int a,int b)
{
	if(a>b)
		return b;
	else
		return a;
}
void floyd()
{
	int i,j,k;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			for(k=0;k<n;k++)
				g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
		}
	}
}
int main()
{
	int i,j;
	printf("Enter no. of vertices : ");
	scanf("%d",&n);
	printf("Enter adjacency matrix : ");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%d",&g[i][j]);
		}
	}
	floyd();
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("%d\t",g[i][j]);
		}
		printf("\n");
	}
}
