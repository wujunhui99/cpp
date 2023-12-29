#include <iostream>
#include <string>
using namespace std;


class Solution {
public:
    string rev(string &s,int start,int end){
        for(int i = 0;i<(end-start + 1)/2;i++){
            char tmp = s[start + i];
            s[start+i] = s[end-i];
            s[end-i] = tmp;
        }
        return s;
    }
    string reverseStr(string s, int k) {
        int cnt = 0;
        if(s.size()<k) rev(s,0,s.size()-1);
        while(cnt < s.size()){
            if(cnt+k-1 > s.size()) rev(s,cnt,s.size()-1);
            else rev(s,cnt,cnt+k-1);
            cnt += 2*k;
        }
        return s;
    }
};

int main(int argc, char const *argv[])
{
    string s = "a";
    Solution sol;
    string s2 = sol.reverseStr(s,2);
    cout << s2 << endl;
    return 0;
}
