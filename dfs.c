// to implement dfs
// using recursion so as to use implicit stack i.e. recursive function call stack
#include <stdio.h>
#include <stdlib.h>
void dfs(int[7], int[7][7], int);
void main()
{
    int node;
    int visited[7] = {0, 0, 0, 0, 0, 0, 0};
    int adj[7][7] = {
        {0, 1, 1, 1, 0, 0, 0},
        {1, 0, 1, 0, 0, 0, 0},
        {1, 1, 0, 1, 1, 0, 0},
        {1, 0, 1, 0, 1, 0, 0},
        {0, 0, 1, 1, 0, 1, 1},
        {0, 0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 1, 0, 0}};
    printf("\nChoose a node to begin with: ");
    scanf("%d", &node);
    dfs(visited, adj, node);
} // end of main
void dfs(int visited[7], int adj[7][7], int node)
{
    visited[node] = 1;
    printf("%d ", node);
    for (int j = 0; j < 7; j++)
    {
        if (adj[node][j] && !visited[j])
            dfs(visited, adj, j);
    } // end of for loop
} // end of fn.