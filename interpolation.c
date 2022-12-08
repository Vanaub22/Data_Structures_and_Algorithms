//to perform Interpolation Search on an user-input array
//FORMULA FOR ENHANCEMENT IN BINARY SEARCH ALGORITHM: pos=low+(((key-arr[low])/(arr[high]-arr[low]))*(high-low))
#include<stdio.h>
#include<stdlib.h>
int interpolationSearch(int*,int,int);
int interpolationSearch(int* arr,int size,int key)
{
    int low=0,high=size-1,pos;
    while(low<high)
    {
        pos=low+(((key-arr[low])/(arr[high]-arr[low]))*(high-low));
        if(arr[pos]<key)
        low=pos+1;
        else if(arr[pos]>key)
        high=pos-1;        
        else
        return(pos);
    }//end of while loop
    return(-1);//element not found in the array
}//end of fn.
void main()
{
    int n,*arr,i,key,pos;
    printf("Enter the number of elements in the array: ");
    scanf("%d",&n);
    arr=(int*)malloc(n*sizeof(int));
    printf("Enter the elements of the sorted array separated by spaces: ");
    for(i=0;i<n;i++)
    scanf("%d",&arr[i]);
    printf("Enter the key value to be searched in the array: ");
    scanf("%d",&key);
    printf("The user-input array is as follows: ");
    for(i=0;i<n;i++)
    printf("%d ",arr[i]);
    pos=interpolationSearch(arr,n,key);
    if(pos!=-1)
    printf("\nSearch Succesful. The key value %d is present in the given array at index position %d.",key,pos);
    else
    printf("\nSearch failed. The element %d is not present in the given array.",key); 
}//end of main