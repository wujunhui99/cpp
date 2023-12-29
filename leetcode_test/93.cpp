#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> result;
    string path;
    bool isvaild(string &s, int start, int end){
        if(start > end) return false;
        if(s[start] == '0' && start != end) return false;
        int num = 0;
        for(int i = start;i<=end;i++){
            if(s[i] > '9' || s[i] <'0') return false;
            num *= 10;
            num += s[i] - '0';
        }
        if(num > 255) return false;
        return  true;
    }
    void backtracking(string &s,int startIndex,int pointNum){
        if(pointNum == 3){
            if(isvaild(s,startIndex,s.size()-1)){
                result.push_back(s);
                return;
            }
        }
        for(int i = startIndex;i<s.size();i++){
            if(isvaild(s,startIndex,i)){
                s.insert(s.begin()+i+1,'.');
                pointNum ++;
                backtracking(s,i+1,pointNum);
                pointNum--;
                s.erase(s.begin()+i+1);
            }else break;
        }
    }
    vector<string> restoreIpAddresses(string s) {
        backtracking(s,0,0);
        return result;
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;
    sol.restoreIpAddresses("0000");
    return 0;
}
