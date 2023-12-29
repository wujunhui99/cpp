#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int index = g.size() - 1; // 孩子数组的下标
        int result = 0;
        for(int i = s.size()-1;i>=0;i--){ //饼干
            while(g[index] > s[i]){
                index --;
                if(index < 0) 
                    return result;         
            } 
            
            result ++;
            index --;
        }
        return result;
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;
    vector<int> g = {1,2,3};
    vector<int> s = {1,1};
    cout <<sol.findContentChildren(g,s);
    return 0;
}
