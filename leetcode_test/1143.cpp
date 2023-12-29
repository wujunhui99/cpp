#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp(text1.size() + 1, vector<int>(text2.size() + 1, 0));
        for(int i = 1;i<dp.size();i++){
            for(int j = 1;j<dp[0].size();j++){
                if(text1[i-1] == text2[j-1]){
                    dp[i][j] = dp[i][j-1] + 1;
                } 
                else{
                    dp[i][j] = max(dp[i][j-1],dp[i-1][j]);
                }
            }
        }
        for(auto &v1 : dp){
            for(auto num : v1) cout << num << " ";
            cout << endl;
        }
        return dp[text1.size()][text2.size()];
    }
};
int main(){
    Solution sol;
    string text1 = "abcba";
    string text2 = "abcbcba";
    sol.longestCommonSubsequence(text1,text2);
    return 0;
}