#include <cmath>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
bool cmp(int a, int b) {
    return abs(a) > abs(b);
}
int main(){
    vector<int> a = {4,6,1,8,6,9};
    sort(a.begin(),a.end(),cmp);
    for(auto x : a) cout << x << " ";
}