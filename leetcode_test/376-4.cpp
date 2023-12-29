#include <bits/stdc++.h>
// #include <algorithm>
// #include <cmath>
using namespace std;
class Solution {
public:
    int maxFrequencyScore(vector<int>& nums, long long k) {
        int result = 0;
        sort(nums.begin(),nums.end());
        vector<vector<int>> dp(nums.size(),vector<int>(nums.size(),0));
        for(int i = 0;i<nums.size() - 1;i++){
                dp[i][i+1] = nums[i+1] - nums[i];
                if(dp[i][i+1]<=k) result = max(result,2);
        }
        for(int diff = 2;diff<nums.size();diff++){
            int i = 0, j = diff;
            while(i < nums.size() && j < nums.size()){
                if( dp[i+1][j] == 0 || dp[i][j-1] == 0) dp[i][j] = 2 * (dp[i+1][j] + dp[i][j-1]);
                else dp[i][j] = dp[i+1][j] + dp[i][j-1] - dp[i+1][j-1];
                if(dp[i][j] <= k) 
                    result = max(result , j-i+1);
                i ++;
                j ++;
            }
        }
        // for(int num : nums ) cout << num << "\t";
        cout << endl;  
        for(int i = 0;i<dp.size();i++){
            for(int j = 0;j<dp.size();j++) 
                cout << dp[i][j] << "\t";
            cout << endl;
        }
        return result;
    }
};
int main(){
    Solution sol;
    vector<int> nums = {3,20,13,2,3,15,24,19,8,13,19,20,21};
    int k = 45;
    cout << sol.maxFrequencyScore(nums,k);
    return 0;
}