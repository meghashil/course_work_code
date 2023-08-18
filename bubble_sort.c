#include<stdio.h>
#include<stdlib.h>
void bubble_sort_array();
void using_linkedlist();
void create();
void bubble_sort_linkedlist();
void display();
typedef struct node{
    int data;
    struct node *next;
}NODE;
NODE *head=NULL;
int main(){
    int choice;
    printf("Menu\n 1.Bubble sort using Array\n 2.Bubble sort using Linkedlist\n");
    printf("Enter your choice:-");
    scanf("%d",&choice);
    switch(choice){
        case 1:bubble_sort_array();
            break;
        case 2: using_linkedlist();
            break;

    }

}
void bubble_sort_array(){
int a[20],n,i,j;
int temp;
printf("Enter the size of an array:-");
scanf("%d",&n);
printf("Enter the elements of an array:-");
for(i=0;i<n;i++){
scanf("%d",&a[i]);
}
//Bubble sort
for(i=0;i<n-1;i++){
    for(j=0;j<n-i-1;j++){
        if(a[j]>a[j+1]){
            temp=a[j];
            a[j]=a[j+1];
            a[j+1]=temp;
        }
    }
}
//Display sorted array
printf("After Sorting\n");

for(i=0;i<n;i+++){
    printf("%d ",a[i]);
}
}
void using_linkedlist(){
    create();
    bubble_sort_linkedlist();
    printf("After Sorting\n");
    display();
}
void create(){
    int data,num=1;
    NODE *ptr;
    while(num){
        printf("Enter the data:-");
        scanf("%d",&data);
        NODE *newnode=(NODE*)(malloc(sizeof(NODE)));
        newnode->data=data;
        newnode->next=NULL;
        if(head==NULL){
            head=newnode;
        }
        else{
            ptr=head;
            while(ptr->next!=NULL){
                ptr=ptr->next;
            }
            ptr->next=newnode;
        }
        printf("Enter 1 to continue or 0 to exit:-");
        scanf("%d",&num);
    }
}
void bubble_sort_linkedlist(){
    NODE *i,*j;
    int temp;
    for(i=head;i->next!=NULL;i=i->next){
        for(j=i->next;j!=NULL;j=j->next){
            if(i->data > j->data){
                temp=i->data;
                i->data=j->data;
                j->data=temp;

            }
        }
    }
}
void display(){
    NODE *temp=head;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
}
