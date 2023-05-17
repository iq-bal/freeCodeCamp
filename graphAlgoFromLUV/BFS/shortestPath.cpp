/*
https://www.spoj.com/problems/NAKANJ/
*/
#include<iostream>
#include<vector>
#include<queue>

using namespace std;

const int N = 1e5+10;
int vis[8][8]; 
int level[8][8];

int get_x(string s){
    return s[0]-'a'; 
}

int get_y(string s){
    return s[1]-'1'; 
}

bool isValid(int x, int y){
    return x>=0 && y>=0 && x<8 && y<8 ;
}

void reset(){
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            vis[i][j]=0; 
            level[i][j]=0; 
        }
    }
}

vector<pair<int,int>> movements ={
    {-1,2},{1,2},
    {-1,-2},{1,-2},
    {2,-1},{2,1},
    {-2,-1},{-2,1}
}; 

int bfs(string source,string dest){
    int sourceX = get_x(source);
    int sourceY = get_y(source);
    int destX = get_x(dest);
    int destY = get_y(dest);
    queue<pair<int,int>>q; 
    q.push({sourceX,sourceY});
    vis[sourceX][sourceY]=1; 
    while (!q.empty())
    {
        pair<int,int> v = q.front();
        int x = v.first;
        int y = v.second; 
        q.pop();

        // we can do this . but it looks messy . so we will use a smart way . 
        // q.push({x+2,y+1});
        // q.push({x+2,y-1});
        // q.push({x+1,y+2});
        // q.push({x-1,y+2});
        // q.push({x-2,y+1});
        // q.push({x-2,y-1});
        // q.push({x+1,y-2});
        // q.push({x-1,y-2}); 

        for(auto movement: movements){
            int childX = movement.first +x;
            int childY = movement.second +y; 
            if(!isValid(childX,childY)) continue;
            if(!vis[childX,childY]){
                q.push({childX,childY});
                vis[childX][childY]=1; 
                level[childX][childY] = level[x][y]+1; 
            }
        }
    }
    return level[destX][destY];   
}

/*
level is basically distance from the root node . minimum level number will be always traversed first. 
so from level we can get the shortest path in case unweighted graph 
*/

int main(){
    int n;  cin>>n;
    while (n--)
    {
        reset(); 
        string s1,s2;
        cin>>s1>>s2;
        cout<< bfs(s1,s2)<< endl; 
    }
}