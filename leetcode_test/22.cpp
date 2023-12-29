#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int N = 0;
    vector<string> result;
    
public:
    void backtrack( string str,int n, int left, int cnt){
        if(n == 0){
            result.push_back(str);
            return ;
        } 
        if(left<n/2){
            backtrack(str + "(", n-1,left+1,cnt+1);
        }
        if(cnt > 0){
            backtrack(str + ")",n-1,left,cnt-1);
        }
        
    }
    vector<string> generateParenthesis(int n) {
        N = 2 * n;
        backtrack("",n*2, 0 , 0);
        return result;
    }
};
int main(){
    Solution sol;
    auto ret = sol.generateParenthesis(3);
    for(string st : ret) cout << st << " || ";
    return 0;
}