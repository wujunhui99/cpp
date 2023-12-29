#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        unordered_set<int> numSet;
        int a,b;
        int result = 0;
        int i = 1;
        for(auto &vt : grid){
            for(int &num:vt){
                result -= i*i;
                i++;
                result += num * num;
                if(numSet.count(num) == 1) a = num;
            }
        }
        b = abs(result - a*a);
        return {a,b};
    }
};
int main(){
    Solution sol;
    vector<vector<int>> grid = {{1,3},{2,2}};
    sol.findMissingAndRepeatedValues(grid);
    return 0;
}