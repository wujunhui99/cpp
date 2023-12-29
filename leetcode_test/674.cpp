#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        if(nums.size() <= 1) return nums.size();
        vector<int> dp(nums.size(),1);
        int result = 1;
        for(int i = 1;i<dp.size();i++){
            if(dp[i] > dp[i-1]) 
                dp[i] = dp[i-1] + 1;
            if(dp[i] > result) 
                result = dp[i];
        }
        return result;
    }
};
int main(){
    Solution sol;
    vector<int> nums = {1,3,5,4,7};
    sol.findLengthOfLCIS(nums);
    return 0;
}