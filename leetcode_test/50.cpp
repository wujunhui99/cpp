#include <bits/stdc++.h>
using namespace std;
class Solution {
private:
    unordered_map<int,double> pow;
    double mpow(double x, int n){          
        if(n == 1) return x;
        if(pow.find(n) != pow.end()) return pow[n];
        pow[n] =  mpow(x, n/2) * mpow(x, n - n/2);
        return pow[n];
    }
public:
    double myPow(double x, int n) {
        int sig = 0;
        if(n < 0){
             n = -n;
             sig = 1;
        }
        if(n == 0) return 1;
        if(x == 0) return 0;
        if(n == 1) return x;
        if(n == 1) return 1/x;
        double r = mpow(x, n/2) * mpow(x, n - n/2);
        if(sig) return 1/r;
        return r;
    }
};
int main(){
    Solution sol;
    cout << sol.myPow(8.95371,-1);
    return 0;
}