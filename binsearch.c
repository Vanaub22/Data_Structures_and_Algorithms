//to implement binary search
#include<stdio.h>
#include<stdlib.h>
int binarySearch(int arr[], int l, int r, int x)
{
	if (r >= l) {
		int mid = l + (r - l) / 2;
		if (arr[mid] == x)
			return mid;
		if (arr[mid] > x)
			return binarySearch(arr, l, mid - 1, x);
		return binarySearch(arr, mid + 1, r, x);
	}//end of if block
	return -1;
}//end of fn.
void main()
{
	int result,n,*arr,i,x;
	printf("\nEnter the number of elements in the array: ");
	scanf("%d",&n);
	arr=(int*)malloc(n*sizeof(int));
	printf("\nEnter the elements of the array:");
	for(i=0;i<n;i++)
	scanf("%d",&arr[i]);
	printf("\nEnter the element to be searched for: ");
	scanf("%d",&x);
	result = binarySearch(arr, 0, n - 1, x);
	(result == -1)? printf("\nElement is not present in array\n"): printf("\nElement is present at index %d\n",result);
}//end of main
