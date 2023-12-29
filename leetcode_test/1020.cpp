#include <bits/stdc++.h>
using namespace std;
class Solution {
private:
    int dir[4][2] = {0,1,0,-1,1,0,-1,0};
    int dfs(vector<vector<int>>& grid,vector<vector<bool>>& visited,int x,int y){
        bool ret = false;
        int result = 1;
        if(x == 0 || y == 0 || x == grid.size()-1 || y == grid[0].size() - 1)
            ret = true;
        for(int i = 0;i<4;i++){
            int nx = x + dir[i][0];
            int ny = y + dir[i][1];
            if(nx < 0 || ny < 0 || nx >= grid.size() || ny >= grid[0].size()) continue;
            if(grid[nx][ny] == 1 && !visited[nx][ny]){
                visited[nx][ny] = true;
                if(nx == 0 || ny == 0 || nx == grid.size()-1 || ny == grid[0].size() - 1)
                    ret = true;
                int df = dfs(grid,visited,nx,ny);
                if(df == 0)
                    result = 0;
                if(result != 0)
                    result += df;
            }
        }
        if(ret ) return 0;
        return result;
    }
    
public:

    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int result = 0;
        vector<vector<bool>> visited(n,vector<bool>(m,false));
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(grid[i][j] == 1 && !visited[i][j]){
                    visited[i][j] = true;
                    result += dfs(grid,visited,i,j);                  
                }
            }
        }
        return result;
    }
};
int main(){
    Solution sol;
    // vector<vector<int>> grid1 ={{0,0,0,1,1,1,0,1,0,0},

    //                             {1,1,0,0,0,1,0,1,1,1},
  // 1
    //                             {0,0,0,1,1,1,0,1,0,0},

    //                             {0,1,1,0,0,0,1,0,1,0},
  // 2
    //                             {0,1,1,1,1,1,0,0,1,0},

    //                             {0,0,1,0,1,1,1,1,0,1},

    //                             {0,1,1,0,0,0,1,1,1,1},

    //                             {0,0,1,0,0,1,0,1,0,1},

    //                             {1,0,1,0,1,1,0,0,0,0},

    //                             {0,0,0,0,1,1,0,0,0,1}};
    // vector<vector<int>> grid2 = {{0,0,0,0},

    //                              {1,0,1,0},

    //                              {0,1,1,0},

    //                              {0,0,0,0}};
    // cout << sol.numEnclaves(grid1) << endl;
    // cout << sol.numEnclaves(grid2);
    vector<vector<int>> grid = {{0,0,0,1,1,1,0,1,0,0},
                                {1,1,0,0,0,1,0,1,1,1},
                                {0,0,0,1,1,1,0,1,0,0},
                                {0,1,1,0,0,0,1,0,1,0},
                                {0,1,1,1,1,1,0,0,1,0},
                                {0,0,1,0,1,1,1,1,0,1},
                                {0,1,1,0,0,0,1,1,1,1},
                                {0,0,1,0,0,1,0,1,0,1},
                                {1,0,1,0,1,1,0,0,0,0},
                                {0,0,0,0,1,1,0,0,0,1}};
    cout << sol.numEnclaves(grid);
    return 0;
}