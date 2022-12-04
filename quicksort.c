//to perform quick sort on user-input array
#include<stdio.h>
#include<stdlib.h>
void Qsort(int*,int,int);
int partition(int*arr,int low,int high)
{
    int temp,i=low+1,j=high,pivot=arr[low];
    do
    {
        while(arr[i]<=pivot)
        i++;
        while(arr[j]>pivot)
        j--;
        if(i<j)
        {
            temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
        }//end of if block
    } while(i<j);//end of do-while loop
    temp=arr[j];
    arr[j]=arr[low];
    arr[low]=temp;
    return(j);//returning index
}//end of fn.
void Qsort(int* arr,int low,int high)
{
    int pindex;
    if(low<high)
    {
        pindex=partition(arr,low,high);
        Qsort(arr,low,pindex-1);
        Qsort(arr,pindex+1,high);
    }//end of if block
}//end of fn.
void main()
{
    int n,*arr,i;
    printf("Enter the number of elements in the array: ");
    scanf("%d",&n);
    arr=(int*)malloc(n*sizeof(int));
    printf("Enter the elements of the array separated by spaces: ");
    for(i=0;i<n;i++)
    scanf("%d",&arr[i]);
    printf("The user-input array is as follows: ");
    for(i=0;i<n;i++)
    printf("%d ",arr[i]);
    printf("\n");
    Qsort(arr,0,n-1);
    printf("The sorted array is as follows: ");
    for(i=0;i<n;i++)
    printf("%d ",arr[i]);
    free(arr);
}//end of main