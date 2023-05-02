#include<iostream>
#include<vector>
using namespace std;

// a matrix of vertex * vertex in case of adjacency matrix 

const int N = 1e3;
int graph1[N][N]; 


// adjacency list 
vector<int> graph2[N]; 
vector<pair<int,int>> weighted_graph[N]; 

int main(){
    int n,m;    cin>>n>>m;
    // int graph[n+1][n+1]; we will declare the graph globally so that all the elements in it are already zero . 
    for (int i = 0; i < m; i++)
    {
        int v1,v2;  cin>>v1>>v2;
        graph1[v1][v2]=1; // or weight 
        graph1[v2][v1]=1; // as it is a bidirectional graph
    }
    // this is the graph representation through adjeceny matrix. but it has a large space complexity 
    // space O(n*n)
    // maximum array limit is 10^7 or 10^8



    /* lets see adjacency list*/
    // no of vertices = number of list 
    // space complexity O(V+E)

    for (int i = 0; i < m; i++)
    {
        int v1,v2;  cin>>v1>>v2;
        // int w;  cin>>w; 
        graph2[v1].push_back(v2); 
        graph2[v2].push_back(v1); 

        // weighted_graph[v1].push_back({v2,w}); 
        // weighted_graph[v2].push_back({v1,w}); 
    }
    


    return 0;
}