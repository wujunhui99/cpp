#include <vector>
using namespace std;
#include <unordered_set>
class Solution {
public:
    vector<vector<int>> result;
    vector<int> path;
    void backstracking(vector<int>& nums, int startIndex){
        if(path.size() > 1) result.push_back(path);
        unordered_set<int> uset;
        for(int i = startIndex;i<nums.size();i++){
            if ((!path.empty() && nums[i] <path.end())
            || uset.find(nums[i]) != uset.end()) {
                    continue;
            }
            uset.insert(nums[i]);
            path.push_back(nums[i]);
            backstracking(nums,i+1);
            path.pop_back();

        }
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        backstracking(nums,0);
        return result;
    }
};