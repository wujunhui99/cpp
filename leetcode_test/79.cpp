#include <bits/stdc++.h>
using namespace std;
class Solution {
private:
    int dir[4][2] = {0,1,0,-1,1,0,-1,0};
    bool backtracking(vector<vector<char>>& board, int x, int y, string word, int idx,vector<vector<bool>> &falgs){
        if(x <0 || y < 0 || x >= board.size() || y>=board[0].size()) return false;
        if(falgs[x][y] == true) return false;
        falgs[x][y] = true;
        
        if(board[x][y] != word[idx]){
            falgs[x][y] == false;
            return false;
        }
        if(idx == word.size()-1)  return true;
        bool result = false;
        for(int i = 0;i<4;i++){
            int nx = x + dir[i][0];
            int ny = y + dir[i][1];
            if(backtracking(board,nx,ny,word,idx + 1,falgs)) return true;
        }
        falgs[x][y] = false;
        return false;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        vector<vector<bool>> flags(board.size(),vector<bool>(board[0].size(),false));

        for(int i = 0;i<board.size();i++){
            for(int j = 0;j<board[0].size();j++)
                if(backtracking(board,i,j,word,0,flags)) return true;
        }
        return false;
    }
    bool test(vector<vector<char>>& board, string word) {
        vector<vector<bool>> flags(board.size(),vector<bool>(board[0].size(),false));

        return backtracking(board,0,0,word,0,flags);
    }
    
};
int main(){
    Solution sol;
    vector<vector<char>> board = {{'a','b'}};
    
    cout <<  sol.exist(board,"ba");
    return 0;
}