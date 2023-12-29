
#include <cmath>
#include <climits>
class Solution {
public:
    int reverse(int x) {
        int sig = x < 0 ? 1 : 0;
        int y = abs(x);
        int ret = 0;
        while(y != 0){
            if(ret > INT_MAX/10) return 0;
            ret *= 10;
            ret += y % 10;
            y /= 10;
        }
        if(sig) return -ret;
        return ret;
        

    }
};

int main(int argc, char const *argv[])
{
    Solution sol;
    sol.reverse(-2147483648);
    return 0;
}
