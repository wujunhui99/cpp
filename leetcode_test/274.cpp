#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(),citations.end());
        int cit = 0;
        for(int i = citations.size()-1;i>=0;i--){
            
            if(cit == citations[i]) return ++cit;
            if(cit > citations[i]) return cit;
            cit ++;
            
        }
        return citations.size();
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;
    vector<int> citations = {1,3,1};
    cout << sol.hIndex(citations);
    return 0;
}
