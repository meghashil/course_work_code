#include <stdio.h>
#include <stdbool.h>

#define V 4 // number of vertices
#define MAX_COLOR 3 // maximum number of colors

int graph[V][V] = {{0, 1, 1, 1},
                   {1, 0, 1, 0},
                   {1, 1, 0, 1},
                   {1, 0, 1, 0}}; // adjacency matrix
                 

int colors[V]; // array to store colors for each vertex

bool is_safe(int v, int color) 
{
    for (int i = 0; i < V; i++) 
    {
        
        if (graph[v][i] && color == colors[i]) 
        {
            return false;
        }
    }
    return true;
}

bool graph_coloring(int v) 
{
    if (v == V) {
        return true; // all vertices are colored
    }
    
    for (int c = 1; c <= MAX_COLOR; c++) 
    {
        if (is_safe(v, c))
        {
            colors[v] = c; // assign color c to vertex v
            
            if (graph_coloring(v+1)) {
                return true;
            }
            
            colors[v] = 0; // backtrack
        }
    }
    
    return false;
}

int main() 
{
    for (int i = 0; i < V; i++) {
        colors[i] = 0; // initialize colors to 0
    }
    
    if (graph_coloring(0)) {
        printf("Solution exists!\n");
        
        for (int i = 0; i < V; i++) {
            printf("Vertex %d -> Color %d\n", i, colors[i]);
        }
    }
    else {
        printf("Solution does not exist!");
    }
    return 0;
}
