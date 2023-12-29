#include <bits/stdc++.h>
using namespace std;
class Solution {
private:
    int dir[4][2] = {0,1,0,-1,1,0,-1,0};
    int dfs(vector<vector<int>>& grid,vector<vector<bool>>& visited,int x,int y){
        int result = 1;
        for(int i = 0;i<4;i++){
            int nx = x + dir[i][0];
            int ny = y + dir[i][1];
            if(nx < 0 || ny < 0 || nx >= grid.size() || ny >= grid[0].size()) continue;
            if(grid[nx][ny] == 1 && !visited[nx][ny]){
                visited[nx][ny] = true;
                result += dfs(grid,visited,nx,ny);
            }
        }
        return result;
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int result = 0;
        vector<vector<bool>> visited(n,vector<bool>(m,false));
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(grid[i][j] == 1 && !visited[i][j]){
                    result = max (dfs(grid,visited,i,j), result);
                }
            }
        }
        return result;
    }
};
int main(){
    Solution sol;
    vector<vector<int>> grid = {{1,0,0},{1,1,1},{1,0,0}};
    cout << sol.maxAreaOfIsland(grid);

    return 0;
}