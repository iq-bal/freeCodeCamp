/*
given Q queries,
in each query given v,
print 1) subtree sum of v, 2)Number of even numbers
in subtree of v 
*/

#include<iostream>
#include<vector>

const int N = 1e5;
vector<int> g[N];

// dfs in tree

int subtree_sum[N];
int even_ct[N]; 

void dfs(int vertex, int par=0){

    subtree_sum[vertex]+= vertex;
    if(vertex%2==0) even_ct[vertex]++; 
    for(int child: g[vertex]){
        if(child==par)  continue;
        dfs(child,vertex);
        subtree_sum[vertex] += subtree_sum[child];
        even_ct[vertex] += even_ct[child]; 
    }
}

using namespace std;

int main(){
    int n;  cin>>n;
    for (int i = 0; i < n-1; i++)
    {
        int v1,v2;  cin>>v1>>v2;
        g[v1].push_back(v2); 
        g[v2].push_back(v1); 
    }
    int q;  cin>>q;
    // we will precompute 
    dfs(1); 
    while (q--)
    {
        int v;
        cin>>v;
        cout<< subtree_sum[v]<< " "<< even_ct[v]<< endl; 
        // in order to count subtree sum of v 
        // dfs(v);
        // in order to count number of even numbers of subtree of v 
        // dfs2(v); 
        // this will get time complexity, so we will use the concept of precompute 
    }
}