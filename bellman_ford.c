//to implement Single-Source-Shortest-Path using Bellman-Ford Algorithm
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
void bellman_ford(int**,int,int,int);
void bellman_ford(int **graph,int V,int E,int src){
    int i,j,*distances=(int*)malloc(V*sizeof(int));
    for(i=0;i<V;i++)
    distances[i]=INT_MAX;
    distances[src]=0;
    for(i=0;i<V-1;i++)
    for(j=0;j<E;j++)
    if(distances[graph[j][0]]!=INT_MAX && distances[graph[j][0]]+graph[j][2]<distances[graph[j][1]])
    distances[graph[j][1]]=distances[graph[j][0]]+graph[j][2];
    for(i=0;i<E;i++){
        if(distances[graph[i][0]]!=INT_MAX && distances[graph[i][0]]+graph[i][2]<distances[graph[i][1]]){
            printf("The graph has Negative Edge Cycles.\nThe distances of such edges will keep decreasing.");
            break;
        }//end of if block
    }//end of for loop
    printf("Using BELLMAN-FORD ALGORITHM to determine Single-Source-Shortest-Path, we get");
    for(i=0;i<V;i++)
    printf("\nThe distance of Vertex %d from Source %d is %d",i,src,distances[i]);
}//end of fn.
void main()
{
    int V,E,**graph,i,src;
    printf("Enter the number of Vertices and Edges in the graph: ");
    scanf("%d %d",&V,&E);
    graph=(int**)malloc(E*sizeof(int*));
    for(i=0;i<E;i++)
    graph[i]=(int*)malloc(3*sizeof(int));
    printf("Accepting input as Adjacency List...\n");
    for(i=0;i<E;i++){
        printf("Enter the Source Node, Destination Node and Edge Weight for Edge-%d: ",i+1);
        scanf("%d %d %d",&graph[i][0],&graph[i][1],&graph[i][2]);
    }//end of for loop
    printf("The user-input graph edges are as follows:");
    for(i=0;i<E;i++)
    printf("\n%d --> %d (Edge Weight = %d) ",graph[i][0],graph[i][1],graph[i][2]);
    printf("\nEnter the Source Vertex: ");
    scanf("%d",&src);
    bellman_ford(graph,V,E,src);
}//end of main