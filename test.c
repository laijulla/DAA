#include<stdio.h>
#include<stdio.h>

void display(int i,int n,int a[]);
typedef struct minmax
{
int max;
int min;
}minmax;

minmax maxmin(int i, int j,int max,int min,int a[])
{
    minmax m;
 int max1, min1, mid;
 if(i==j)
 {
  m.max = m.min = a[i];
   printf("max %d\t",m.max);
    printf("min %d\n",m.min);
  return m;
 
 }
 else
 {
  if(i == j-1)
  {
   if(a[i] <a[j])
   {
    m.max = a[j];
    m.min = a[i];
    printf("max %d\t",m.max);
    printf("min %d\n",m.min);
    return m;
  
   }
   else
   {
    m.max = a[i];
    m.min = a[j];
    printf("max %d\t",m.max);
    printf("min %d\n",m.min);
    return m;
   
   }
  }
  else
  {
   mid = (i+j)/2;
   printf("left Array\n");
   display(i,mid,a);
   m=maxmin(i, mid,m.max,m.min,a);
  
    max1=m.max; min1 = m.min;
    printf("right Array\n");
    display(mid+1,j,a);
   m=maxmin(mid+1, j,m.max, m.min,a);
  
   if(m.max <max1){
    m.max = max1;
      printf("\n\nmax %d\t",m.max);
    
  
    //return m;
    }
    else
    {
     printf("\n\nmax %d\t",m.max);
        //return m;
    }
   if(m.min > min1)
   {
    m.min = min1;
     
    printf("min %d\n",m.min);
    //return m;
   }
   else
   {
      printf("min %d\n",m.min);
       //return m;
   }
   return m;
  
  }
 }

}


void display(int i,int n,int a[])
{
	printf("\n\n{\t");
	for(i;i<=n;i++)
	{
		printf("%d\t",a[i]);
	}
	printf("}");
	printf("\n");
}
int main ()
{
 int i, num;
 int a[100],max,min;

 minmax k;

 printf ("\nEnter the total number of numbers : ");
 scanf ("%d",&num);

 printf ("Enter the numbers : \n");
 
 for (i=1;i<=num;i++)
  scanf ("%d",&a[i]);

 max = 0;
 min = 0;

 k=maxmin(1, num,max,min,a);

 printf ("\nMinimum element in an array : %d\n", k.min);
 printf ("Maximum element in an array : %d\n", k.max);
 return 0;
}

/*
cc test.c
[Student@localhost ~]$ ./a.out

Enter the total number of numbers : 9
Enter the numbers : 
9
8
6
10
3
2
1
23
34
left Array


{	9	8	6	10	3	}
left Array


{	9	8	6	}
left Array


{	9	8	}
max 9	min 8
right Array


{	6	}
max 6	min 6


max 9	min 6
right Array


{	10	3	}
max 10	min 3


max 10	min 3
right Array


{	2	1	23	34	}
left Array


{	2	1	}
max 2	min 1
right Array


{	23	34	}
max 34	min 23


max 34	min 1


max 34	min 1

Minimum element in an array : 1
Maximum element in an array : 34
*/
