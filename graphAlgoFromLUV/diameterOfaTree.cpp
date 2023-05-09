#include<iostream>
#include<vector>

using namespace std;

const int N=1e3;
int depth[N];

vector<int> g[N]; 

void dfs(int v,int par=-1){
    for(int child:g[v]){
        if(child==par)  continue;
        depth[child]=depth[v]+1;
        dfs(child,v); 
    }
}

int main(){
    // max(number of edges between any two vertices is called diameter )
    // with any root find max depth node
    // with that node as root find max depth 
    int n;  cin>>n;
    for (int i = 0; i < n-1; i++)
    {
        int x,y;    cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x); 
    }
    dfs(1);
    int mx_depth =*max_element(depth,depth+N);
    int mx_d_node= max_element(depth,depth+N)-depth+1; 
    // +1 because 1 based indexing to represent node in an array
    // re setting the depth array 
    for (int i = 0; i < N; i++)
    {
        depth[i]=0;
    }
    dfs(mx_d_node); 
    cout<< *max_element(depth,depth+N)<< endl; 
}