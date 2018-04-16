#include<stdio.h>
#include<stdlib.h>
#define INFINITY 9999 

int lb,cost[10],path[10],rcount,visited[10],rnode[10],pcount=1,temp[20][20];

void init(int g[][20], int nov)
{
int i,j;
for(i=1;i<=nov;i++)			
	{
	for(j=1;j<=nov;j++)
	g[i][j]=INFINITY;
	}
}

void init_visited(int visited[10], int nov)
{
int i,j;
for(i=1;i<=nov;i++)			
	{
	visited[i]=0;
	}

}


void accept(int g[][20],int nov)
{
	int i,j,val;
	
	for(i=1;i<=nov;i++)			
	{
		for(j=1;j<=nov;j++)
		{
			if(i!=j)
			{
			printf("Enter the value for %d and %d\n",i,j);
			scanf("%d",&val);
			g[i][j]=val;
			}
		}
	}
	

}

void display(int g[][20],int nov)
{
int i,j;

	
	for(i=1;i<=nov;i++)			
	{
		printf("\n");
		for(j=1;j<=nov;j++)
			printf("%d \t",g[i][j]);
	}
}

void copy(int g[][20],int rm[][20],int nov)
{
int i,j;

	for(i=1;i<=nov;i++)
	{
		for(j=1;j<=nov;j++)
		{
			rm[i][j]=g[i][j];
		}
	}
}

int reduced(int rm[][20],int nov)
{
int i,j,totalrow=0,totalcol=0,min;
	for(i=1;i<=nov;i++)
	{
		min= INFINITY;
		for(j=1;j<=nov;j++)
		{
			if(min>rm[i][j])
			min =rm[i][j];
		}

		if(min !=0 && min != INFINITY)
		{
			for(j=1;j<=nov;j++)
			{
				if(rm[i][j] != INFINITY)
				rm[i][j]=rm[i][j] - min;
			}
			totalrow=totalrow + min;
		}
	}
	printf("\nrow reduced value is %d \n",totalrow);
	display(rm,nov);
	//column reduced logic same as row reduce logic,just change the loop-it will be opp
	
	for(j=1;j<=nov;j++)
	{
		min= INFINITY;
		for(i=1;i<=nov;i++)
		{
			if(min>rm[i][j])
			min =rm[i][j];
		}

		if(min !=0 && min != INFINITY)
		{
			for(i=1;i<=nov;i++)
			{
				if(rm[i][j] != INFINITY)
				rm[i][j]=rm[i][j] - min;
			}
			totalcol = totalcol + min;
		}
	}
return totalrow + totalcol;
}

void calrnodes(int rnode[],int nov)
{
int v;
	rcount=1;

	for(v=1;v<nov;v++)
	{
		
		if(visited[v]==0)
		{
			rnode[rcount]=v;
			rcount++;
		}
	}
}

void findmin(int cost[],int rnode[], int rcount)
{
int min=INFINITY;
int i,nextnode;
	for(i=1;i<rcount;i++)
	{
		if(min>cost[i])
                      {
                       min=cost[i];
		       nextnode=rnode[i];
                      }
	}
	visited[nextnode]=1;
	path[pcount]=nextnode;
	pcount++;
printf("\n\n Selected a node with mini cost is=%d",nextnode);
printf("\n-----------------------------------------------------");
}

void tsp(int rm[][20],int nov)
{
	int i,j,k,val,p,finalcost;

	for(i=1;i<rcount;i++)
	{
			copy(rm,temp,nov);
	

			for(j=1;j<pcount;j++)
			{	
				for(k=1;k<=nov;k++)
				{
				temp[path[j]][k]=INFINITY;
			
				if(j!=1)
					temp[k][path[j]]=INFINITY;			
				}			
			}
		
			for(k=1;k<=nov;k++)
			{
				temp[k][rnode[i]]=INFINITY;	
			}
		
			temp[rnode[i]][1]=INFINITY;
			val=reduced(temp,nov);

			cost[i]=lb+val;
		
		
			for(p=1;p<pcount-1;p++)
			{
			 cost[i]=cost[i]+rm[path[p]][path[p+1]];
		
			}
		        cost[i]=cost[i]+rm[path[p]][rnode[i]];
			printf("\n\t Cost of %d remaining node =  %d",rnode[i],cost[i]);
		
		}
			findmin(cost,rnode,rcount);
			calrnodes(rnode,nov);		

			if(rcount!=1)
			       tsp(rm,nov);
			else
			{
				printf("\nTSP path is :\n");
				for(k=1;k<pcount;k++)
				{
				      printf("%d->",path[k]);
				}
				printf("%d",path[1]);

				finalcost=lb;
				for(p=1;p<pcount-1;p++)
				      finalcost=finalcost+rm[path[p]][path[p+1]];
				printf("\nMinimum TSP path is :%d",finalcost);
			}
		
	
}

void main()
{
int opt,nov,x[20],g[20][20],rm[20][20];
	do
	{
	printf("\nEnter your choice:\n 1.Accept the graph\n 2.display\n 3.Reduce \n 4.TSP \n 5.stop\n");
	scanf("%d",&opt);

		switch(opt)
		{
		case 1:
		printf("Enter no of vertices: \n");	//accept no of vertices
		scanf("%d",&nov);
		init(g,nov);
		accept(g,nov);
		break;
		case 2:
		display(g,nov);
		break;
		case 3:
		copy(g,rm,nov);
		lb=reduced(rm,nov);
		
		display(rm,nov);
		printf("\nLower Bound on tsp is %d",lb);
		break;
		case 4:
		init_visited(visited,nov);
			pcount=1;
			path[1]=1;
			pcount++;
			visited[1]=1;
		
			calrnodes(rnode,nov);
			tsp(rm,nov);
		break;
		}
	}while(opt!=5);
}

/*Output:
[student@localhost ]$ gcc ass6.c
[student@localhost ]$ ./a.out

Enter your choice:
 1.Accept the graph
 2.display
 3.Reduce 
 4.TSP 
 5.stop
1
Enter no of vertices: 
5
Enter the value for 1 and 2
20
Enter the value for 1 and 3
30
Enter the value for 1 and 4
10
Enter the value for 1 and 5
11
Enter the value for 2 and 1
15
Enter the value for 2 and 3
16
Enter the value for 2 and 4
4
Enter the value for 2 and 5
2
Enter the value for 3 and 1
3
Enter the value for 3 and 2
5
Enter the value for 3 and 4
2
Enter the value for 3 and 5
4
Enter the value for 4 and 1
19
Enter the value for 4 and 2
6
Enter the value for 4 and 3
18
Enter the value for 4 and 5
3
Enter the value for 5 and 1
16
Enter the value for 5 and 2
4
Enter the value for 5 and 3
7
Enter the value for 5 and 4
16

Enter your choice:
 1.Accept the graph
 2.display
 3.Reduce 
 4.TSP 
 5.stop
2

9999 	20 	30 	10 	11 	
15 	9999 	16 	4 	2 	
3 	5 	9999 	2 	4 	
19 	6 	18 	9999 	3 	
16 	4 	7 	16 	9999 	
Enter your choice:
 1.Accept the graph
 2.display
 3.Reduce 
 4.TSP 
 5.stop
3
reduced matrix is 

9999 	10 	20 	0 	1 	
13 	9999 	14 	2 	0 	
1 	3 	9999 	0 	2 	
16 	3 	15 	9999 	0 	
12 	0 	3 	12 	9999 	
reduced matrix is 

9999 	10 	17 	0 	1 	
12 	9999 	11 	2 	0 	
0 	3 	9999 	0 	2 	
15 	3 	12 	9999 	0 	
11 	0 	0 	12 	9999 	
Lower Bound on tsp is 25
Enter your choice:
 1.Accept the graph
 2.display
 3.Reduce 
 4.TSP 
 5.stop
4
reduced matrix is 

9999 	9999 	9999 	9999 	9999 	
9999 	9999 	11 	2 	0 	
0 	9999 	9999 	0 	2 	
15 	9999 	12 	9999 	0 	
11 	9999 	0 	12 	9999 	
 

	 Cost of 2 remaining node =  35
	 reduced matrix is 

9999 	9999 	9999 	9999 	9999 	
12 	9999 	9999 	2 	0 	
9999 	3 	9999 	0 	2 	
15 	3 	9999 	9999 	0 	
11 	0 	9999 	12 	9999 	
 

	 Cost of 3 remaining node =  53
	 reduced matrix is 

9999 	9999 	9999 	9999 	9999 	
12 	9999 	11 	9999 	0 	
0 	3 	9999 	9999 	2 	
9999 	3 	12 	9999 	0 	
11 	0 	0 	9999 	9999 	


	 Cost of 4 remaining node =  25
	 reduced matrix is 

9999 	9999 	9999 	9999 	9999 	
10 	9999 	9 	0 	9999 	
0 	3 	9999 	0 	9999 	
12 	0 	9 	9999 	9999 	
9999 	0 	0 	12 	9999 	
 

	 Cost of 5 remaining node =  31
	 reduced matrix is 

9999 	9999 	9999 	9999 	9999 	
12 	9999 	11 	2 	0 	
0 	3 	9999 	0 	2 	
15 	3 	12 	9999 	0 	
11 	0 	0 	12 	9999 	
 

	 Cost of 0 remaining node =  25

 Selected a node with mini cost is=4
-----------------------------------------------------
reduced matrix is 

9999 	9999 	9999 	9999 	9999 	
9999 	9999 	11 	9999 	0 	
0 	9999 	9999 	9999 	2 	
9999 	9999 	9999 	9999 	9999 	
11 	9999 	0 	9999 	9999 	
 

	 Cost of 2 remaining node =  28
	 reduced matrix is 

9999 	9999 	9999 	9999 	9999 	
12 	9999 	9999 	9999 	0 	
9999 	1 	9999 	9999 	0 	
9999 	9999 	9999 	9999 	9999 	
11 	0 	9999 	9999 	9999 	
r 

	 Cost of 3 remaining node =  50
	 reduced matrix is 

9999 	9999 	9999 	9999 	9999 	
1 	9999 	0 	9999 	9999 	
0 	3 	9999 	9999 	9999 	
9999 	9999 	9999 	9999 	9999 	
9999 	0 	0 	9999 	9999 	


	 Cost of 5 remaining node =  36
	 reduced matrix is 

9999 	9999 	9999 	9999 	9999 	
1 	9999 	0 	9999 	9999 	
0 	3 	9999 	9999 	9999 	
9999 	9999 	9999 	9999 	9999 	
9999 	0 	0 	9999 	9999 	
 

	 Cost of 5 remaining node =  36

 Selected a node with mini cost is=2
-----------------------------------------------------reduced matrix is 

9999 	9999 	9999 	9999 	9999 	
9999 	9999 	9999 	9999 	9999 	
9999 	9999 	9999 	9999 	0 	
9999 	9999 	9999 	9999 	9999 	
0 	9999 	9999 	9999 	9999 	
 

	 Cost of 3 remaining node =  52
	 reduced matrix is 

9999 	9999 	9999 	9999 	9999 	
9999 	9999 	9999 	9999 	9999 	
0 	9999 	9999 	9999 	9999 	
9999 	9999 	9999 	9999 	9999 	
9999 	9999 	0 	9999 	9999 	


	 Cost of 5 remaining node =  28
	 reduced matrix is 

9999 	9999 	9999 	9999 	9999 	
9999 	9999 	9999 	9999 	9999 	
0 	9999 	9999 	9999 	9999 	
9999 	9999 	9999 	9999 	9999 	
9999 	9999 	0 	9999 	9999 	
 

	 Cost of 5 remaining node =  28

 Selected a node with mini cost is=5
-----------------------------------------------------
reduced matrix is 

9999 	9999 	9999 	9999 	9999 	
9999 	9999 	9999 	9999 	9999 	
9999 	9999 	9999 	9999 	9999 	
9999 	9999 	9999 	9999 	9999 	
9999 	9999 	9999 	9999 	9999 	
 

	 Cost of 3 remaining node =  28
	 reduced matrix is 

9999 	9999 	9999 	9999 	9999 	
9999 	9999 	9999 	9999 	9999 	
0 	9999 	9999 	9999 	9999 	
9999 	9999 	9999 	9999 	9999 	
9999 	9999 	9999 	9999 	9999 	


	 Cost of 5 remaining node =  10027

 Selected a node with mini cost is=3
-----------------------------------------------------
TSP path is :
1->4->2->5->3->1
Minimum TSP path is :28
Enter your choice:
 1.Accept the graph
 2.display
 3.Reduce 
 4.TSP 
 5.stop


*/

