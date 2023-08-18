#include<stdio.h>
int binary_search();
int main(){
    int a[20],start,end,key,i,size,index,j;
    printf("Enter the size of an array\n");
    scanf("%d",&size);
    printf("Enter the elements of an array\n");
    for(i=0;i<size;i++){
     scanf("%d",&a[i]);
    }
    for(i=0;i<=size-1;i++){
        for(j=0;j<=size-i-1;j++){
            if(a[j]>a[j+1]){
                int temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
               
            }
            
        }
       }
    printf("Enter an elements to be searched\n");
    scanf("%d",&key);
    index=binary_search(a,0,size,key,size,0);
    if(index==-1){
        printf("Element not found\n");
    }
    else{
        printf("Element found at %d\n",index+1);
    }
    return 0;
}
int binary_search(int a[],int beg,int end,int key,int size,int count){
    int mid;
   
    if(beg>end){
        printf("No. of comparisions required = %d\n",count);
        return -1;
    }
     mid=(beg+end)/2;
    count++;
    if(a[mid]==key){
        printf("No. of comparisions required = %d\n",count);
        return mid;
    }
    else if(a[mid]>key){
        return (binary_search(a,0,mid-1,key,size,count));
    }
    else if(a[mid]<key){
        return (binary_search(a,mid+1,size,key,size,count));
    }
    return -1;
}
