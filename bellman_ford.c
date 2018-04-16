#include<stdio.h>

struct edge
{
	int u;
	int v;
	int w;
};

struct output
{
	int vertex;
	int weight;
	int pi;
};

struct edge edge[10];
struct output output[10];
int ed,vertex;

void accept()
{
	int i;
	printf("Enter number of vertex:");
	scanf("%d",&vertex);
	printf("Enter number of edges:");
	scanf("%d",&ed);
	for(i=1;i<=ed;i++)
	{
		printf("Enter source , destinatiion and weight :");
		scanf("%d",&edge[i].u);
		
		
		scanf("%d",&edge[i].v);
		
		
		scanf("%d",&edge[i].w);
	}
}

void display()
{
	int i;
	printf("Source\tDestination\tWeight\n");
	for(i=1;i<=ed;i++)
	{
		printf("%d\t\t%d\t\t\t%d",edge[i].u,edge[i].v,edge[i].w);
		printf("\n");
	}
}

void bellman_ford()
{
	int i,j,V,U,WT;
	int flag=0;
	int iteration=ed-1;
	for(i=1;i<=iteration;i++)
	{
		output[i].vertex=i;
		output[i].weight=1000;
		output[i].pi=1;
	}
	
	output[1].weight=0;
	output[1].pi=1;
	
	for(i=1;i<=iteration;i++)
	{
		for(j=1;j<=ed;j++)
		{
			U=edge[j].u;
			V=edge[j].v;
			WT=edge[j].w;
			
			if((output[U].weight+edge[j].w)<output[V].weight)
			{
				output[V].weight=output[U].weight+edge[j].w;
				output[V].pi=U;
			}
		}
	}
	
	/// ya pudhe vachayacha aahe
	
	for(i=1;i<=1;i++)
	{
		for(j=1;j<=ed;j++)
		{
			if(flag!=1)
			{
				U=edge[j].u;
				V=edge[j].v;
				WT=edge[j].w;
			
				if((output[U].weight+edge[j].w)<output[V].weight)
				{
					printf("Negative cycle is present.\n");
					flag=1;
				}
			}
		}	
	}
	if(flag==0)
	{
		printf("Vertex\tDistance\tPath\n");
		for(i=1;i<=vertex;i++)
		{
			printf("%d\t%d\t\t%d",output[i].vertex,output[i].weight,output[i].pi);
			printf("\n");
		}
	}	
}

void main()
{

	int i,opt;
	do
	{
		printf("\nMenu\n1.Accept graph.\n2.Display graph.\n3.Shotest path.\n4.Exit.\n");
		printf("Enter your choice:\n");
		scanf("%d",&opt);
		
		switch(opt)
		{
			case 1:
					accept();
					break;
			case 2:
					display();
					break;
			case 3:
					bellman_ford();
					break;
		}
		
	}while(opt!=4);

}

/*OUTPUT:




[snehal@localhost ~]$ gcc bellmanford.c
[snehal@localhost ~]$ ./a.out

Menu
1.Accept graph.
2.Display graph.
3.Shotest path.
4.Exit.
Enter your choice:
1
Enter number of vertex:6
Enter number of edges:10
Enter source , destinatiion and weight :1 2 2
Enter source , destinatiion and weight :1 3 -4
Enter source , destinatiion and weight :2 3 -3
Enter source , destinatiion and weight :2 5 5
Enter source , destinatiion and weight :2 4 1
Enter source , destinatiion and weight :3  5 -2
Enter source , destinatiion and weight :3 4 4
Enter source , destinatiion and weight :5 4 4
Enter source , destinatiion and weight :5 6 6
Enter source , destinatiion and weight :4 6 8

Menu
1.Accept graph.
2.Display graph.
3.Shotest path.
4.Exit.
Enter your choice:
2
Source	Destination	Weight
1		2			2
1		3			-4
2		3			-3
2		5			5
2		4			1
3		5			-2
3		4			4
5		4			4
5		6			6
4		6			8

Menu
1.Accept graph.
2.Display graph.
3.Shotest path.
4.Exit.
Enter your choice:
3
Vertex	Distance	Path
1	0		1
2	2		1
3	-4		1
4	-2		5
5	-6		3
6	0		5

Menu
1.Accept graph.
2.Display graph.
3.Shotest path.
4.Exit.
Enter your choice:


*/
