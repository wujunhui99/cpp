using namespace std;
#include <unordered_map>
#include <vector>
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> dict;
        for(int i = 0;i<nums.size();i++){
            dict.insert(pair<int,int>(nums[i],i));
        }
        for(int i = 0;i<nums.size();i++){
            int tmp = target - nums[i];
            if(dict.find(tmp) != dict.end()){
                if(dict.find(tmp)->second != i) return {i,dict.find(tmp)->second};
            }
        }
        return {};
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;
    vector<int> v = {2,7,11,15};
    sol.twoSum(v,9);
    return 0;
}
