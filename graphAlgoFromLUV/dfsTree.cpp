#include<iostream>
#include<vector>

using namespace std;

const int N = 1e3;
vector<int> g[N];

bool vis[N];

int depth[N];
int height[N]; 

void dfs(int vertex){
    vis[vertex] = true; 
    for(int child : g[vertex]){
        if(vis[child])  continue;
        dfs(child); 
    }
}

// we dont need visited array for tree dfs . though the 'dfs' code also work in case of tree. we can just optimize it. 

void tree_dfs(int vertex,int par=0){

    for(int child: g[vertex]){
        if(child==par)  continue;
        depth[child]= depth[vertex]+1; // take action on child before entering the child node 
        tree_dfs(child,vertex); 
        height[vertex] = max(height[vertex],height[child]+1); // take action on child after exiting the child node 
    }
}


int main(){
    int n;    cin>>n;
    int m = n-1; // a tree has n-1 edges where n is number of vertices
    while (m--)
    {
        int v1, v2; cin>>v1;
        g[v1].push_back(v2);
        g[v2].push_back(v1); 
    }
    tree_dfs(1); 
    for (int i = 1; i <=n; i++)
    {
        cout<< depth[i]<< " "<< height[i]<< endl; 
    }
    
    return 0;
}