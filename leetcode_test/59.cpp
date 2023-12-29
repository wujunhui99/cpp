#include <vector>
using namespace std;
#include <iostream>
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n,vector<int>(n,0));
        int x = 0, y = 0, count = 0;
        for(int t = 0;t< n/2;t++){
            
            for(;y < n - t -1; y ++){
                count ++;
                res[x][y] = count;
            }
            
            for(;x<n- t - 1;x++){
                count ++;
                res[x][y] = count;
            }
            
            for(;y>t;y--){
                count ++;
                res[x][y] = count;
            }
            
            for(;x>t;x--){
                count ++;
                res[x][y] = count;
            }
            x++,y++;
        }
        if(n % 2 == 1) res[n/2 ][n/2] = count + 1;
        return res;
    }
    
    
    
};
int main(int argc, char const *argv[])
{
    Solution solution;
    int n = 4;
    auto mtx = solution.generateMatrix(n);
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            cout << mtx[i][j]<< " ";
        }
        cout << endl;
    }
    return 0;
}
