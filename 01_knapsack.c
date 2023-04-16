//to solve the 0/1 Knapsack Problem (Dynamic Programming Approach)
#include<stdio.h>
#include<stdlib.h>
void main(){
	int i,j,W,n,*weights,*values,**DP;
	printf("Enter the number of items: ");
	scanf("%d",&n);
	printf("Enter the capacity of knapsack: ");
	scanf("%d",&W);
	weights=(int*)malloc(n*sizeof(int));
	values=(int*)malloc(n*sizeof(int));
    printf("Enter the values: ");
	for(i=0;i<n;i++)
	scanf("%d",&values[i]);
	printf("Enter the weights: ");
	for(i=0;i<n;i++)
	scanf("%d",&weights[i]);
    DP=(int**)malloc((n+1)*sizeof(int*));
    for(i=0;i<=n;i++)
    DP[i]=(int*)malloc((W+1)*sizeof(int));
    for(i=0;i<=n;i++)
    for(j=0;j<=W;j++)
    if(i==0||j==0)
    DP[i][j]=0;
    else if(j>=weights[i-1])
    DP[i][j]=(DP[i-1][j]>=DP[i-1][j-weights[i-1]]+values[i-1])?(DP[i-1][j]):(DP[i-1][j-weights[i-1]]+values[i-1]);
    else
    DP[i][j]=DP[i-1][j];
    printf("The optimal profit result for the given 0/1 Knapsack Problem would be %d\n",DP[n][W]);
}//end of main