/*
https://leetcode.com/problems/flood-fill/ 
*/
#include<iostream>
#include<vector>

using namespace std;

void dfs(int i,int j, int initialColor, int newColor, vector<vector<int>> &image){
    int n= image.size();
    int m = image[0].size(); 
    if(i<0 || j<0)  return;
    if(i>=n || j>=m)    return; 
    if(image[i][j]!=initialColor)   return; 
    image[i][j]=newColor; 
    dfs(i-1,j,);
    dfs(i+1,j);
    dfs(i,j+1);
    dfs(i,j-1);
}

vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int initialColor = image[sr][sc];
        if(initialColor!=newColor){
            dfs(sr,sc,intitialColor,newColor, image); 
        }
        return image; 
}

int main(){
    
}