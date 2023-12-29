#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void sw(vector<int>& nums, int index, int k){
        swap(nums[k-1],nums[index]);
        int idx = k-1;
        while(idx != 0 && nums[idx] > nums[idx-1]){
            swap(nums[idx],nums[idx-1]);
            idx--;
        }
    }
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(),nums.begin() + k-1,[](int &lhs, int &rhs){return lhs>rhs;});
        for(int i = k;i<nums.size();i++){
            if(nums[i] <= nums[k-1]) continue;
            sw(nums,i,k);
        }
        return nums[k-1];
    }
};
int main(){
    Solution sol;
    vector<int> nums = {-1,2,0};
    cout << sol.findKthLargest(nums,2);
    return 0;
}