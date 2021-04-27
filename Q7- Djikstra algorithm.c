#include<stdio.h>


#define INFINITY 9999

#define MAX 10

void dijkstra(int G[MAX][MAX],int n,int start)

{

    int cost[MAX][MAX],dist[MAX],pred[MAX];

    int visited[MAX],count,min,next,i,j;

    for(i=0;i<n;i++)

    for(j=0;j<n;j++)

    { if(G[i][j]==0)

    cost[i][j]=INFINITY;

    else

    cost[i][j]=G[i][j];

    }

   

    for(i=0;i<n;i++)

    {

    dist[i]=cost[start][i];

    pred[i]=start;

    visited[i]=0;

    }

    dist[start]=0;

    visited[start]=1;

    count=1;

    while(count<n-1)

    {

     min=INFINITY;

    //nextnode gives the node at minimum distance

    for(i=0;i<n;i++)

    if(dist[i]<min&&!visited[i])

    {

    min=dist[i];

    next=i;

    }

    //check if a better path exists through nextnode

    visited[next]=1;

    for(i=0;i<n;i++)

    if(!visited[i])

    if(min+cost[next][i]<dist[i])

    {

     dist[i]=min+cost[next][i];

     pred[i]=next;

    }

   count++;

    }

    //print the path and distance of each node

    for(i=0;i<n;i++)

    if(i!=start)

{

    printf("\nDistance of node%d=%d",i,dist[i]);

    printf("\nPath=%d",i);

    j=i;

    do

    {

      j=pred[j];

      printf("<-%d",j);

    }while(j!=start);

      }

}

int main()

{


    int Arr[MAX][MAX],i,j,n,u;

    printf("Enter no. of vertices you want:\n");

    scanf("%d",&n);

    printf("\nEnter the weights:\n");

    for(i=0;i<n;i++)

    for(j=0;j<n;j++)

    scanf("%d",&Arr[i][j]);

    printf("\nEnter the start node:");

    scanf("%d",&u);

    dijkstra(Arr,n,u);

    getch();

    return 0;

}


