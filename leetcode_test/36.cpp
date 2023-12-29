#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<char> chSet;
        for(int i = 0;i<9;i++){
            chSet.clear();
            for(int j = 0;j<9;j++){
                if(board[i][j] == '.') continue;
                if(chSet.count(board[i][j]) == 0) chSet.insert(board[i][j]);
                else return false;
            }
        }
        for(int j = 0;j<9;j++){
            chSet.clear();
            for(int i = 0;i<9;i++){
                if(board[i][j] == '.') continue;
                if(chSet.count(board[i][j]) == 0) chSet.insert(board[i][j]);
                else return false;
            }
        }
        for(int i = 0;i<3;i++){
            for(int j = 0;j<3;j++){
                chSet.clear();
                for(int m = 0;m<3;m++){
                    for(int n = 0;n<3;n++){
                        if(board[i * 3 + m][j * 3 + n] == '.') continue;
                        if(chSet.count(board[i * 3 + m][j * 3 + n]) == 0)
                            chSet.insert(board[i * 3 + m][j * 3 + n]);
                        else return false;
                    }
                }
            }
        }
        return true;
    }
};

int main(){
    Solution sol;
    vector<vector<char>> board = {  {'.','.','.','.','5','.','.','1','.'},
                                    {'.','4','.','3','.','.','.','.','.'},
                                    {'.','.','.','.','.','3','.','.','1'},
                                    {'8','.','.','.','.','.','.','2','.'},
                                    {'.','.','2','.','7','.','.','.','.'},
                                    {'.','1','5','.','.','.','.','.','.'},
                                    {'.','.','.','.','.','2','.','.','.'},
                                    {'.','2','.','9','.','.','.','.','.'},
                                    {'.','.','4','.','.','.','.','.','.'}};
    sol.isValidSudoku(board);
    return 0;
}