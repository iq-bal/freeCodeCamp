#include<iostream>
#include<vector>

using namespace std;

const int N = 1e5;
vector<int> g[N]; 
bool vis[N];

vector<vector<int>> cc; 
vector<int> current_cc; 

void dfs(int vertex){
    vis[vertex]=true; 
    current_cc.push_back(vertex); 
    for(int child:g[vertex]){
        if(vis[child])  continue;
        dfs(child); 
    }
}

int main(){
    int n,m;    cin>>n>>m;
    while (m--)
    {
        int v1,v2;  cin>>v1>>v2;
        g[v1].push_back(v2);
        g[v2].push_back(v1); 
    }
    // int count =0;
    for (int i = 1; i <= n; i++)
    {
        if(vis[i])  continue;
        current_cc.clear(); 
        dfs(i);
        cc.push_back(current_cc); 
        // count++; 
    }
    // cout<< count<< endl; 
    // no of connected components 
    cout<< cc.size()<<endl; 
    for(auto i : cc){
        for(int vertex : i){
            cout<< vertex << endl; 
        }
    }


}