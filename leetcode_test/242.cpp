#include <iostream>
#include <string>
using namespace std;


class Solution {
public:
    bool isAnagram(string s, string t) {
        int nums[26] = {0};
        if(s.size() != t.size()) return 0;
        for(int i = 0;i<s.size();i++){
            nums[s[i]-'a'] ++;
            nums[t[i]-'a'] --;
        }
        bool ret = 1;
        for(int i = 0;i<s.size();i++){
            if(nums[i] != 0) return 0;
        }
        return 1;
    }
};

int main(){
    string s = "nl",t="cx";
    Solution mysol;
    mysol.isAnagram(s,t);
    return 0;
}