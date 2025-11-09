#include<bits/stdc++.h>
using namespace std;

bool helper(vector<string>&ans, vector<vector<int>>& grid, int n, int i, int j, string res){
    if(i==n-1 && j==n-1){
        ans.push_back(res);
        return 1;
    }
    if(i<0 || i>=n || j<0 || j>=n || grid[i][j]==0)return 0;
    grid[i][j]=0;
    bool found=helper(ans, grid, n, i+1, j, res+'D')||
    helper(ans, grid, n, i-1, j, res+'U')||
    helper(ans, grid, n, i, j+1, res+'R')||
    helper(ans, grid, n, i, j-1, res+'L');
    grid[i][j]=1;
    return found;
}
vector<string> maze(int n, vector<vector<int>>& grid){
    vector<string>ans;
    if(grid[0][0]==0)return ans;
    helper(ans, grid, n, 0, 0, "");
    return ans;
}

int main(){
    int n=4;
    vector<vector<int>>grid= { {1, 0, 0, 0} , {1, 1, 0, 1}, {1, 1, 0, 0}, {0, 1, 1, 1} };
    
}