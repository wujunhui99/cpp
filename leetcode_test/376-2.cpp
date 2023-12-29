#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> result;
        for(int i = 0;i<nums.size()/3;i++){
            int a = nums[3*i], b =  nums[3*i + 1], c = nums[3*i+2];
            if(c - b > k||b-a>k) 
                return {};
            result.push_back({a,b,c});
            
        }
        return result;
    }
};
int main(){
    Solution sol;
    vector<int> nums = {15,13,12,13,12,14,12,2,3,13,12,14,14,13,5,12,12,2,13,2,2};
    sol.divideArray(nums,2);
    return 0;
}