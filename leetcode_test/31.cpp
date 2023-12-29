#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int idx;
        for(int i = nums.size() - 1;i>=1;i--){
            if(nums[i] > nums[i-1]){
                swap(nums[i],nums[i-1]);
                idx = i;
                break;
            }

        }
        sort(nums.begin() + idx,nums.end());
    }
};
int main(){
    Solution sol;
    vector<int> nums = {1,2,3};
    sol.nextPermutation(nums);
    for(auto num : nums) cout << num << " ";
    return 0;
}