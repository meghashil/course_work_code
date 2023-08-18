#include<iostream>
using namespace std;
#define N 8
bool isSafe(int A[N][N],int x,int y){
	for(int row=0;row<x;row++){
		if(A[row][y]){
			return false;
		}
	}
	int row=x,col=y;
	while(row>=0 && col>=0)
	 
	{
		if(A[row][col]==1){
			return false;
		}
		row--;
		col--;
	}
	row=x,col=y;
	while(row>=0 && col<N){
		if(A[row][col]==1){
			return false;
		}
		row--;
		col++;
	}
	return true;
}
bool nqueen(int A[N][N],int x){
	if(x>=N){
		return true;
	}
	for(int col=0;col<N;col++){
		if(isSafe(A,x,col)){
			A[x][col]=1;
			
			if(nqueen(A,x+1)){
				return true;
			}    
			A[x][col]=0;//backtracking
		}
	}
	return false;
}
int main(){
	int A[N][N]; 
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			A[i][j]=0;
		}
	}
	if(nqueen(A,0)){
		for(int i=0;i<N;i++){
			for(int j=0;j<N;j++){
				cout<<A[i][j]<<" ";
			}
			cout<<endl;
		}
	}
	else{
		cout<<"Queen cannot be placed";
	}
}
