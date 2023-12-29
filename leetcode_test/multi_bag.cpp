
#include <iostream>
#include <vector>
using namespace std;

// int main(){
//     int bagSize,n;
//     vector<int> weight(n,0);
//     vector<int> value(n,0);
//     vector<int> nums(n,0);
//     for(int i = 0;i<n;i++) cin >> weight[i];
//     for(int i = 0;i<n;i++) cin >> value[i];
//     for(int i = 0;i<n;i++) cin >> nums[i];
    
//     vector<int> dp(bagSize+1,0);
//     for(int i = 0;i<n;i++){
//         for(int j = bagSize;j>=weight[i];j--){
//             for(int k = 1; k <= nums[i] && (j - k * weight[i]) >= 0; k++)
//                 dp[j] = max(dp[j], dp[j - k * weight[i]] + k * value[i]);
//         }
//     }
//     cout << dp[bagSize] << endl;
// }
int main(int argc, char const *argv[])
{
    int x;
    cin >> x;
    cout << x;
    return 0;
}
