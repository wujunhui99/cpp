#include <unordered_map>
#include<unordered_set>
using namespace std;
class Solution {
public:
    int square_sum(int n){
        int sum = 0;
        while(n != 0){
            sum += (n % 10) * (n % 10);
            n /= 10;
        }
        return  sum;
    }
    bool isHappy(int n) {
        unordered_set<int> history;
        
        while(history.find(n) == history.end()){
            history.insert(n);
            n = square_sum(n);
            if(n == 1) return true;
        }
        return false;
        
    }
};

int main(int argc, char const *argv[])
{
    Solution sou;
    sou.isHappy(19);
    return 0;
}
