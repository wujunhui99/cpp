#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> result (nums.size(),1);
        vector<int> left (nums.size(),1);
        vector<int> right (nums.size(),1);
        int lm = 1,rm = 1;
        for(int i = 1;i<nums.size();i++){
            lm *= nums[i-1];
            left[i] = lm;
        }
        for(int j = nums.size()-2;j>=0;j--){
            rm *= nums[j-1];
            right[j] = rm;
        }
        nums[0] = right[1];
        nums[nums.size()-1] = left[nums.size()-2];
        for(int i = 1;i<nums.size()-2;i++){
            nums[i] = left[i-1] * right[i+1];
        }
        return result;

    }
};
int main(){
    Solution sol;
    vector<int> nums = {1,2,3,4};
    auto ret = sol.productExceptSelf(nums);
    for(int r : ret) cout << r << " ";
    return 0;
}