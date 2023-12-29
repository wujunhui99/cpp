#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        int min = INT_MAX;
        for(int num : arr) 
            if(num < min) min = num;
        for(int &num : arr)
            num -= min;
        int d = INT_MAX;
        for(int num : arr) 
            if(d<num && num != 0) d = num;
        for(int num : arr) 
            if(num % d != 0) 
                return false;
        return true;
    }
};
int main(){
    Solution sol;
    vector<int> arr = {1,3,5};
    sol.canMakeArithmeticProgression(arr);
    return 0;
}