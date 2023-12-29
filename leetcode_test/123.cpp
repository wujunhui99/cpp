#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    // 5 state  0unpos 1first pos 2first sold 3second pos 4second sold
    int maxProfit(vector<int>& prices) {
        if (prices.size() == 0) return 0;
        vector<int> dp(4, 0);
        dp[0] = -prices[0];
        dp[2] = -prices[0];
        for (int i = 1; i < prices.size(); i++) {
            dp[0] = max(dp[0], - prices[i]);
            dp[1] = max(dp[1], dp[0] + prices[i]);
            dp[2] = max(dp[2], dp[1] - prices[i]);
            dp[3] = max(dp[3], dp[2] + prices[i]);
        }
        return dp[3];                   
    }
};
int main(){
    Solution sol;
    vector<int> prices = {3,3,5,0,0,3,1,4};
    cout << sol.maxProfit(prices);
    return 0;
}