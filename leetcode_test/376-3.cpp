#include <bits/stdc++.h>
using namespace std;
class Solution {
private:
    bool rev(long long num){
        long long cp = num;
        long long result = 0;
        while(cp != 0){
            result *= 10;
            result += (cp % 10);
            cp /= 10;
        }
        return result == num;
    }
public:
    long long minimumCost(vector<int>& nums) {
        double avg = 0;
        avg += nums[0];
        for(int i = 1;i<nums.size();i++){
            avg = double(i)/(i+1) * avg + double(1)/(i+1) * nums[i];
        }
        long long avg_num = avg;
        int i = 0;
        long long rev_num;
        while(true){
            if(rev(avg_num+i)){
                rev_num = avg_num + i;
                break;
            }
            if(rev(avg_num-i)){
                rev_num = avg_num - i;
                break;
            }
            i++;
        }
        long long result = 0;
        for(int i = 0;i<nums.size();i++){
            result += abs(avg_num - nums[i]);
        }
        return result;
    }
};
int main(){
    Solution sol;
    vector<int> nums = {10,12,13,14,15};
    cout << sol.minimumCost(nums);
    return 0;
}