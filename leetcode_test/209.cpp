#include <vector>
#include <iostream>
#include <stdint.h>
using namespace std;
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int min = INT32_MAX;
        int sum = 0;
        int subIndex = 0;
        for(int i = 0;i<nums.size();i++){
            if(i+subIndex >= nums.size()) return min;
            while(sum < target ){
                if(i+subIndex >= nums.size()) return min;
                sum += nums[i + subIndex];
                subIndex ++;
                
            }
            subIndex --;
            sum-=nums[i+subIndex];
            if(subIndex +1   < min) min = subIndex +1;
            sum -= nums[i];
            subIndex--;
        }
        if(min == 2147483647) min = 0;
        return min;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    
    vector<int> v2 = {1,1,1,1,1,1,1,1};
    int ret2 = solution.minSubArrayLen(11,v2);
    cout << ret2 << endl;
    
    return 0;
}
