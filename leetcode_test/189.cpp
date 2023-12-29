#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void reverse(vector<int>& nums, int beg, int end){
        for(int i = 0;i<(end-beg + 1)/2;i++){
            swap(nums[i+beg],nums[end-i]);
        }
    }
    void rotate(vector<int>& nums, int k) {
        reverse(nums,0,nums.size()-1-k);
        reverse(nums,nums.size()-k,nums.size()-1); //  4  6
        reverse(nums,0,nums.size()-1);
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;
    vector<int> nums = {1,2,3,4,5,6,7};
    sol.rotate(nums,3);
    for(int i : nums) cout << i << endl;
    return 0;
}
