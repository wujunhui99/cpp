#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int> benifits(prices.size()-1,0);
        int total = 0;
        int maxSum = 0;
        int sum = 0;
        for(int i = 0;i<benifits.size();i++){
            benifits[i] = prices[i+1]-prices[i];
            sum += benifits[i];
            if(sum > maxSum) maxSum = sum;
            else if(sum <= 0 ){
                sum = 0;
                total += maxSum;
                maxSum = 0;
                }
        }
        if(sum > 0) total += maxSum;
        return total;
    }     
};

int main(){
    Solution sol;
    vector<int> vt = {7,1,5,3,6,4};
    sol.maxProfit(vt);
}