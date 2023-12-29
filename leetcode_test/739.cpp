#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> st;
        vector<int> result(temperatures.size(),0);
        st.push(0);
        for(int i = 1;i<temperatures.size();i++){
            while(temperatures[i] > temperatures[st.top()]){
                result[st.top()] = i - st.top();
                st.pop(); 
            }
            st.push(i);
        }
        return result;
    }
};
int main(){
    Solution sol;
    vector<int> temp = {73,74,75,71,69,72,76,73};
    sol.dailyTemperatures(temp);
    return 0;
}