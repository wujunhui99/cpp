#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int> dp(amount + 1,0);
        dp[0] = 1;
        
        for (int j = 0; j <= amount; j++) { // 遍历背包容量
            for (int i = 0; i < coins.size(); i++) { // 遍历物品
                if (j - coins[i] >= 0) dp[j] += dp[j - coins[i]];
            }
            for(int d : dp) cout << d << " ";
            cout << endl;
        }

        return dp[amount];
    }
};
int main(){
    Solution sol;
    vector<int> coins = {1,2,5};
    sol.change(5,coins);
    return 0;
}