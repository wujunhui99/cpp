#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n+1,0);
        dp[2] = 1;
        for(int i = 3; i <= n ; i++){
            for(int j = 1;j<=i/2;j++){
                dp[i] = max(dp[i], max((i - j) * j, dp[i - j] * j));
                
            }
            cout << "i: " << i <<" "<< dp[i] <<endl;
        }
        return dp[n];

    }
};

int main(int argc, char const *argv[])
{
    Solution sol;
    sol.integerBreak(10);
    return 0;
}
