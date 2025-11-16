#include<stdio.h>
#include<stdlib.h>
void merge(int arr[],int l,int r, int mid){
    int i=l;
    int j=mid+1;
    int k=0;
    int temp[r-l+1];
    while(i<=mid && j<=r){
        if(arr[i]<=arr[j]){
            temp[k++]=arr[i++];
        }
        else{
            temp[k++]=arr[j++];
        }
    }
    while(i<=mid){
        temp[k++]=arr[i++];
    }
    while(j<=r){
        temp[k++]=arr[j++];
    }
    for(int x=0;x<k;x++){
        arr[l+x]=temp[x];
    }
}
void mergesort(int arr[],int l,int r){
    if(l>=r){
        return;
    }
    int mid=(l+r)/2;
    mergesort(arr,l,mid);
    mergesort(arr,mid+1,r);
    merge(arr,l,r, mid);
}
int main()
{
    int n;
    printf("enter the size of the array:");
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    for(int i=0;i<n;i++){
        printf("%d\t",arr[i]);
    }
    printf("the sorted aray after the mergesort implemention is :");
    mergesort(arr,0,n-1);
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    return 0;

}