#include <bits/stdc++.h>
using namespace std;

int n, bagweight;
void solve(){
    std::vector<int> weight(n,0) ;
    vector<int> value(n,0);
    for(int i = 0;i<n;i++){
        cin >> weight[i];
    }
    for(int j = 0;j<n;j++){
        cin >> value[j];
    }
    vector<vector<int>> dp(n,vector<int>(bagweight +1,0));
    for(int j = weight[0];j<bagweight;j++){
        dp[0][j] = value[0];
    }
    for(int i = 1;i<n;i++){ //科研物品
        for(int j = 0;j<=bagweight;j++){
            if(j<weight[i]) dp[i][j] = dp[i-1][j];
            else dp[i][j] = max(dp[i-1][j],dp[i-1][j-weight[i]] + value[i]);
        }
    }
    std::cout << dp[n-1][bagweight] << std::endl;
}
int main(){
    while(cin >> n >>bagweight){
        solve();
    }
    return 0;
}