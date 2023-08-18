#include<stdio.h>
#include<stdlib.h>
void merge_sort(int a[],int left,int right);
void merge(int a[],int left,int mid,int right);
int main()
{
    int a[10],i,j,n;
    printf("enter the size of array");
    scanf("%d",&n);
     printf("enter the elements of array");
    for(i=0;i<n;i++){
       
        scanf("%d",&a[i]);
}
merge_sort(a,0,n-1);
    printf("sorted array elements are:");
    for(i=0;i<n;i++){
        printf("%d ",a[i]);
    }
    return 0;
}
void merge_sort(int a[],int left,int right){
int mid;
    if(left<right){
        mid=left+(right-left)/2;
        merge_sort(a,left,mid);    //recursively callling merge sort
        merge_sort(a,mid+1,right);
        merge(a,left,mid,right);
         }
}
         void merge(int a[],int left,int mid,int right)
         {
int n1=mid-left+1;
int n2=right-mid;
int i,j,k;
    int left_sorted[n1],right_sorted[n2];     //creating left subarray and right subarray
    for(i=0;i<n1;i++){
        left_sorted[i]=a[left+i];       //coping elements to left subarray
         }
    for(j=0;j<n2;j++)
    {
        right_sorted[j]=a[mid+1+j];      //coping elements to right suarray
    }
i=0;
 j=0;
 k=left;
while(i<n1 && j<n2)
{
    if(left_sorted[i]<right_sorted[j]){
        a[k]=left_sorted[i];
        i++;
    }
    else{
        a[k]=right_sorted[j];
        j++;
    }
    k++;
}
while(i<n1){
    a[k]=left_sorted[i];
    i++;
    k++;
}
while(j<n2)
{
    a[k]=right_sorted[j];
    j++;
    k++;
}
         }

