#include<stdio.h>
#include<limits.h>
#define V 4
#define x INT_MAX/2

int min(int a,int b){
    if(a<b)
    return a;

    return b;
}

int main(){
    int D[V][V]={
                 { 0 , 8 , x , 1 },
                 { x , 0 , 1 , x },
                 { 4 , x , 0 , x },
                 { x , 2 , 9 , 0 }
            };
    for(int k=0;k<V;k++){
        for(int u=0;u<V;u++){
            for(int v=0;v<V;v++){
                D[u][v]=min(D[u][v],D[u][k]+D[k][v]);
            }
        }
    }
    for(int i=0;i<V;i++){
        printf("\nFrom %d:\n",i);
        for(int j=0;j<V;j++){
            if(i!=j){
            printf("%d-%d  %d\n",i,j,D[i][j]);
            }
        }
    }
    return 0;
}
