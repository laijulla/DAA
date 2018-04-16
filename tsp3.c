#include<stdio.h>
int G[10][10],completed[10],n,cost=0;
void accept()
	{
		int i,j;
	printf("Enter the number of cities\n");
	scanf("%d",&n);
	
	printf("Enter the cost matrix\n");
	for(i=0;i<n;i++)
		{
		printf("\nEnter the elements of Row #: %d\n",i+1);
		for(j=0;j<n;j++)
			scanf("%d",&G[i][j]);
		completed[i]=0;
				
		}
		printf("\n\nThe cost list is:");
			for(i=0;i<n;i++)
			{
				printf("\n");
			for(j=0;j<n;j++)
				
				printf("\t%d",G[i][j]);
				
			}
	}
void mincost(int city)
	{
	int i,ncity;
	completed[city]=1;
	printf("%d--->",city+1);
	ncity=least(city);
	
	if(ncity==999)
		{
		ncity=0;
		printf("%d",ncity+1);	
		cost=cost+G[city][ncity];
		return;

		}
	mincost(ncity);	
	}
int least(int c)
	{
	int i,nc=999;
	int min=999,kmin;
	for(i=0;i<n;i++)
		{
		if((G[c][i]!=0)&&(completed[i]==0))
			
			if(G[c][i]<min)
				{
				min=G[i][0]+G[c][i];
				kmin=G[c][i];
				nc=i;
				}
			
		}
	if(min!=999)
		cost=cost+kmin;
		return nc;	
	}
int main()
	{
	accept();
	printf("\n\nThe path is:\n");
	mincost(0);
	printf("The minimum cost is %d\n",cost);
	return 0;
	}
	
/*OUTPUT:
[student@master te69]$ cd ..
[student@master ~]$ gcc tsp.c
[student@master ~]$ ./a.out
Enter the number of cities
4
Enter the cost matrix

Enter the elements of Row #: 1
0 10 15 20

Enter the elements of Row #: 2
5 0 9 10

Enter the elements of Row #: 3
6 13 0 12

Enter the elements of Row #: 4
8 8 9 0


The cost list is:
	0	10	15	20
	5	0	9	10
	6	13	0	12
	8	8	9	0

The path is:
1--->2--->4--->3--->1The minimum cost is 35
*/	
	
