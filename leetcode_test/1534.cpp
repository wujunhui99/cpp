#include <bits/stdc++.h>
using namespace std;

int main(){
    int M,N; // M -> Material N -> size
    N = 5, M = 4;
    vector<int> costs = {1,2,3,4};
    vector<int> values = {1,2,3,4};
    vector<int> dp(N+1,0);
    for(int i = 0;i<=N;i++){
        for(int j = 0;j<M;j++){
            if(i - costs[j] >= 0){
                dp[i] = max(dp[i],dp[i - costs[j]] + values[j]);
            }
        }
    }
    cout << dp[N] << endl;
    return 0;
    
}