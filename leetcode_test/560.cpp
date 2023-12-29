#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int left = 0, right = 1;
        int sum = nums[left];
        int result = 0;
        while(right <=nums.size()){
            if(sum == k) {
                result ++;
                
                sum -= nums[left];
                left ++;
                if(left == right) right ++;
            }
            else if(sum < k){
                sum += nums[right];
                right ++;
            }else{
                while(sum > k){
                    if(left > nums.size()-1) break;
                    sum -= nums[left];
                    left++;
                    if(left == right){
                        right ++;
                    }
                }
            }
        }
        return result;
    }
};
int main(){
    Solution sol;
    vector<int> nums = {1};
    cout << sol.subarraySum(nums,1);
    return 0;
}