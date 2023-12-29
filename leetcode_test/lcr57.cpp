#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        for(int i = 0;i<nums.size()-k;i++){
            for(int j = i+1;j<= i+k  && j<nums.size();j++){
                if(abs((long long)nums[i] - nums[j]) <= t) 
                    return true;
            }
        }
        return false;
    }
};
int main(int argc, char const *argv[])
{
    Solution sol;
    vector<int> vt = {4,1,-1,6,5};
    int k =3, t = 1;
    sol.containsNearbyAlmostDuplicate(vt,k,t);
    return 0;
}
