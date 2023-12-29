#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> result;
        unordered_map<char,int> targetMap;
        unordered_map<char,int> curMap;
        for(char ch : p) targetMap[ch] ++;
        int slow = 0,fast = 0;
        curMap[s[0]] ++;
        while(fast<s.size()){
            if(targetMap.find(s[fast]) == targetMap.end()){
                fast ++;
                slow = fast;
                curMap.clear();
                curMap[s[slow]] ++;
            }else if(curMap[s[fast]] == targetMap[s[fast]] + 1){
                while(curMap[s[fast]] == targetMap[s[fast]] +  ){
                    curMap[s[slow]] --;
                    slow ++;
                }
                curMap[s[fast]] ++;
                fast++;
            }else{
                curMap[s[fast]] ++;
                fast++;
            }
            if(fast - slow == p.size()) result.push_back(slow);
        }
        return result;
    }
};
int main(){
    Solution sol;
    string a = "abab";
    string b = "ab";
    auto p = sol.findAnagrams(a,b);
    for (auto x : p) cout << x << "  ";
    return 0;
}
