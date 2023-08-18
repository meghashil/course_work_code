#include<stdio.h>
#include<limits.h>
#include<stdbool.h>
//number of vertices
#define v 5
int print_mst(int parent[], int key []){
    printf("EDGE \tWeight\n");
    for(int i = 0;i<v;i++)
    {
        if (i != parent[i])
        {
        printf("%d - %d \t%d  \n", parent[i],i,key[i], parent[i]);
        }
    
    }int sum = 0;
    printf("Total cost ");
    for(int i = 0; i<v; i++)
    {
      sum = sum + key[i];
    }

      printf("%d\n",sum);


  }
//parent
int min_key(int key[], bool min_span_tree[]){
    int min = INT_MAX, min_index;
    for(int k = 0;k<v;k++){
        if(min_span_tree[k]== false && key[k]<min){
            min = key[k], min_index = k;
        }

    }
    return min_index;
}
void prims_mst(int graph[v][v]){
    int key[v]; //To store key value of each vertices
    int parent[v]; //To store constructed mst
    bool min_span_tree[v];//For maintaining track of all vertices

    for(int i=0;i<v; i++){  //  key is infinite and vertices are not visited;
    key[i] = INT_MAX, min_span_tree[i] = false;// here we will set the values of all key as INFINITE
                                             //and make sure that this vertices are not part of our MST set
    }
    // Always include first 1st vertex in MST.
    // Make key 0 so that this vertex is picked as first
    // vertex.
    key[4] = 0; // root node
    parent[4] = 4 ; // it has no parent
    // fetching the minimum index that we have generated in our min_key function
    for(int count=0;count<v-1;count++){
        int u = min_key(key, min_span_tree);
//we will include this least node to our MST set
      min_span_tree[u]= true;
      for(int k=0;k<v;k++){//traverse joined edges
        if( graph[u][k]!=0 && min_span_tree[k]==false && graph[u][k]< key[k])
            {
          parent[k]= u,key[k] = graph[u][k];
        }
      }

    }
 printf("created spanning tree for given graph is : \n ");
 print_mst(parent,key);
}
int main()
{
//we will make a 2d array as an input for the graph
    int graph[v][v]={   { 0, 2, 0, 2, 0 },
                        { 2, 0, 3, 2, 5 },
                        { 0, 3, 0, 0, 7 },
                        { 2, 2, 0, 0, 9 },
                        { 0, 5, 7, 9, 0 } };
    prims_mst(graph);
    return 0;
}
