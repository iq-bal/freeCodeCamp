#include<iostream>
#include<vector>
#include<set>

using namespace std;

const int N = 1e5;
const int INF = 1e9;

vector<pair<int,int>> g[N]; 


void dijkstra(int source){
    vector<int> vis(N,0); 
    vector<int> dist(N,INF);
    set<pair<int,int>> st ; // weight , node 
    st.insert(0,source);
    dist[source]=0;
    while (!st.size()>0)
    {
        auto node = *st.begin();
        int v = node.second;
        int d = node.first;
        st.erase(st.begin()); 
        if(vis[v]==1)   continue;
        vis[v]=1;
        for(auto child: g[v]){
            int child_v = child.first;
            int wt = child.second;
            if(dist[v]+wt<dist[child_v]){
                dist[child_v]=dist[v]+wt;
                st.insert(dist[child_v],child_v);
            }
        }
    }
}

int main(){
    int n,m;    cin>>n>>m;
    for (int i = 0; i < n; i++)
    {
        int x,y,wt; cin>>x>>y>>wt;
        g[x].push_back({y,wt});
    }
}