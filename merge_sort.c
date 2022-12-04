//to perform merge sort on an user-input array
#include<stdio.h>
#include<stdlib.h>
void Msort(int*,int,int);
void merging(int*,int,int,int);
void Msort(int* arr,int left,int right)
{
    int mid;
    if(left!=right)
    {
        mid=(left+right)/2;
        Msort(arr,left,mid);
        Msort(arr,mid+1,right);
        merging(arr,left,mid,right);
    }//end of if block
}//end of fn.
void merging(int* arr,int left,int mid,int right)
{
    int k=0,i,j,aux[30];
    // int* aux=(int*)malloc(n*sizeof(int));
    for(i=left,j=mid+1;i<=mid&&j<=right;k++)
    {
        if(arr[i]<arr[j])
        aux[k]=arr[i++];
        else
        aux[k]=arr[j++];
    }
    for(;i<=mid;i++)
    aux[k++]=arr[i];
    for(;j<=right;j++)
    aux[k++]=arr[j];
    for(i=0;i<k;i++)
    arr[left++]=aux[i];
    // free(aux);
}//end of fn.
void main()
{
    int n,*arr,i;
    printf("Enter the number of elements in the array: ");
    fflush(stdin);
    scanf("%d",&n);
    arr=(int*)malloc(n*sizeof(int));
    printf("Enter the elements of the array separated by spaces: ");
    fflush(stdin);
    for(i=0;i<n;i++)
    scanf("%d",&arr[i]);
    printf("The user-input array is as follows: ");
    for(i=0;i<n;i++)
    printf("%d ",arr[i]);
    printf("\n");
    Msort(arr,0,n-1);
    printf("The sorted array is as follows: ");
    for(i=0;i<n;i++)
    printf("%d ",arr[i]);
    free(arr);
}//end of main
