#include<iostream>
using namespace std;

int min(int a,int b){
	if(a<b){
		return a;
	}
	return b;
}
void sorting(float D[],int n,int sort[]){
	for(int i=0;i<n;i++){
		sort[i]=i;
	}
	for(int i=0;i<n-1;i++){
		for(int j=0;j<n-i-1;j++){
			if(D[j]<D[j+1]){
				float temp=D[j];
				D[j]=D[j+1];
				D[j+1]=temp;
				int temp2=sort[j];
				sort[j]=sort[j+1];
				sort[j+1]=temp2;
			}
		}
	}
}
void knapsack(int w[],float p[],int W,int n ){
	int sort[n];//array used to store index
	float D[n];//array used to store ratio
	float tp=0;//total profit
	for(int i=0;i<n;i++)
	{
		D[i]=(p[i]/float(w[i]));1
	}
	sorting(D,n,sort);
	int i=0,solution[n],count=0;//count used to calculate the no. of items in knapsack
	while(W>0){
		int index=sort[i];
		int amount=min(W,w[index]);
		solution[i]=amount;
		W=W-amount;
		i++;
		count++;
	}
	for(int i=0;i<count;i++){
		int index=sort[i];
		if(i==count-1){
			tp=tp+(D[i]*solution[i]);//fraction condition
			
		}
		else{
			tp=tp+p[index];
		}
	}
	cout<<"Item\tQuantity\tProfit\n";
	for(int i=0;i<count;i++){
		int index=sort[i];
		if(i==count-1){
			cout<<sort[i]+1<<"\t"<<solution[i]<<"\t       "<<D[i]*solution[i]<<endl;
		}
		else
		cout<<sort[i]+1<<"\t"<<solution[i]<<"\t       "<<p[index]<<endl;
			}
		cout<<"Total Profit="<<tp;
	
}
int main(){
	int w[20],n,W;
	float p[20];
	cout<<"enter the number of item: ";
	cin>>n;
	cout<<"Enter the weight of item\n";
	for(int i=0;i<n;i++){
		cin>>w[i];
	}
	cout<<"Enter the profit  of item\n";
	for(int i=0;i<n;i++){
		cin>>p[i];
	}
	cout<<"Enter the capacity of knapsack: ";
    cin>>W;
knapsack(w,p,W,n);

}


