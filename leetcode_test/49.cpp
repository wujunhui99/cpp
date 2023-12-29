#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> ret;
        for(int i = 0;i<strs.size();i++){
            string tmp = strs[i];
            sort(strs[i].begin(),strs[i].end(),[](char a, char b){return a > b;});
             if(ret.find(tmp) == ret.end()){
                 ret[tmp] = {strs[i]};
             }else{
                 ret[tmp].push_back(strs[i]);
             }
        }
        vector<vector<string>> result;
        for(auto& x : ret) {
            result.push_back(x.second);
        }
        return result;
    }
};
int main(){
    Solution sol;
    vector<string> strs = {"eat","tea","tan","ate","nat","bat"};
    sol.groupAnagrams(strs);
    return 0;
}