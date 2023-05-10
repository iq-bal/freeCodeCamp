/*
https://www.interviewbit.com/problems/delete-edge/
*/
#include<iostream>
#include<vector>

using namespace std;

const int N = 1e3;
vector<int> g[N]; 
const int M = 1e9+7; 

int subtree_sum[N]; 

void dfs(int v, int p=-1){
    subtree_sum[v] += val[v];  
    // val array te edge er weight deya thakbe 
    for(int child:g[v]){
        if(child==p)  continue;
        dfs(child,v); 
        subtree_sum[v] += subtree_sum[child]; 
    }
}

int main(){
    int n;  cin>>n;
    for (int i = 0; i < n-1; i++)
    {
        int x,y;    cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x); 
    }
    dfs(1); 
    int ans =0;
    for (int i = 2; i <= n; i++)
    {
        int part1 = subtree_sum[i];
        int part2 = subtree_sum[1]-subtree_sum[i]; 
        ans = max(ans, ((part1*part2)%M)); 
    }
    cout<< ans << endl; 
}