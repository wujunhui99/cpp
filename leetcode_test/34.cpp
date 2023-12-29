#include <bits/stdc++.h>
using namespace std;
class Solution {
private:
    int binSearch(vector<int>& nums,int target, int left, int right){
        if(left > right) return -1;
        int mid = (left + right) / 2;
        if(nums[mid] == target) return mid;
        else if(nums[mid] > target) return binSearch(nums,target,left,mid-1);
        else return binSearch(nums,target,mid+1, right);
    }
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int idx = binSearch(nums,target,0,nums.size()-1);
        if(idx == -1) return {-1,-1};
        int left = idx, right = idx;
        while(nums[left] == target && left >= 0){
            if(nums[left-1] == target) left --;
            else break;
        }
        while(nums[right] == target && right <= nums.size()-1){
            if(nums[right+1] == target) right ++;
            else break;
        }
        return {left,right};
    }
};
int main(){
    Solution sol;
    vector<int> nums = {1};
    cout << sol.searchRange(nums,1)[0] << " " << sol.searchRange(nums,1)[1  ];
    return 0;
}