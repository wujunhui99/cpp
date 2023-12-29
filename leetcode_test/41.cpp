#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canPartition(vector<int>& nums) {
       int sum = 0;
       for(int &num:nums)
            sum += num;
        if(sum %2 == 1) return false;
        sum /= 2;
        vector<int> dp(sum+1,0);
        for(int i = 0;i<nums.size();i++){  //物品
            for(int j = nums.size();j>=nums[i];j--){  //背包
                dp[j] = max(dp[j],dp[j-nums[i]] + nums[i]);
            }
        }
        return dp.back() == sum;
    }
};
int main(int argc, char const *argv[])
{
    Solution sol;
    vector<int> nums = {1,5,11,5};
    sol.canPartition(nums);
    return 0;
}
