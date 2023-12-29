#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> dp(m+1,vector<int>(n+1,0)); // the m is zero, the n is one
        for(string str:strs){
            int ones = 0, zeros = 0;
            for(char c: str){
                if(c == '0') zeros ++;
                else ones ++;
            }
            for(int i = m;i>=zeros;i--){
                for(int j = n;j>=ones;j--){
                    dp[i][j] = max(dp[i][j],dp[i-zeros][j-ones]+1 );
                }
            }
        }
        return dp[m][n];
    }
};
int main(){
    Solution sol;
    vector<string> strs = {"10","0001","111001","1","0"};
    sol.findMaxForm(strs,5,3);
    return 0;
}