#include<stdio.h>
void swap(int*a,int*b)
{
    int t =*a;
    *a=*b;
    *b=t;
}
int median(int arr[],int low,int high)
{
    int mid=low+(high-low)/2;
    if(arr[low]>arr[mid])
        swap(&arr[low],&arr[mid]);
    if(arr[low]>arr[high])
        swap(&arr[low],&arr[high]);
    if(arr[mid]>arr[high])
        swap(&arr[mid],&arr[high]);
    swap(&arr[mid],&arr[high-1]);
    return arr[high-1];
}
int partition(int arr[],int low,int high)
{
    int pivot=median(arr,low,high);
    int i =low;
    int j=high-1;

    while(1)
    {
        while(arr[++i]<pivot);
        while(arr[--j]>pivot);
        if(i>=j)
            break;
        swap(&arr[i],&arr[j]);

    }
    swap(&arr[i],&arr[high-1]);
    return i;
}
void quicksort(int arr[],int low,int high)
{
    if(low<high)
    {
        int pi=partition(arr,low,high);
        quicksort(arr,low,pi-1);
        quicksort(arr,pi+1,high);
    }
}
void printarr(int arr[],int size)
{
    for(int i=0;i<size;i++)
        printf("%d",arr[i]);
    printf("\n");
}

int main()
{

    int arr[]={10,7,8,9,1,5};
    int n=sizeof(arr)/sizeof(arr[0]);
    printf("original array");
    printarr(arr,n);
    quicksort(arr,0,n-1);
    printf("Sorted array");
    printarr(arr,n);
}
