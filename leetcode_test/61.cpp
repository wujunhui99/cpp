#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    vector<vector<string>> result;
    bool isValid(int row, int col, vector<string>& chessboard, int n){
        for(int i = 0;i<row;i++)
            if(chessboard[i][col] == 'Q') return false;
        for(int i = row-1, j = col - 1; j>= 0 && i >= 0 ;j--,i--)
            if(chessboard[i][j] == 'Q') return false;
        for(int i = row-1, j = col + 1; j<= n-1 && i >= 0 ;j++,i--)
            if(chessboard[i][j] == 'Q') return false; 
        return true;
    }
    void backtracking(int n,int row,vector<string> &chessboard){
        if(row == n){
            result.push_back(chessboard);
            return;
        }
        for (int col = 0; col < n; col++){
            if(isValid(row,col,chessboard,n)){
                chessboard[row][col] = 'Q';
                backtracking(n,row+1,chessboard);
                chessboard[row][col] = '.';
            }
        }
    }
    
    
    vector<vector<string>> solveNQueens(int n) {
        vector<string> chessboard(n, string(n, '.'));
        backtracking(n,0,chessboard);
        return result;
    }
};