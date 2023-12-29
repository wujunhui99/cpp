#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minimumNumbers(int num, int k) {
        int result = 0;
        bool flag = true;
        while(num % 10 != 0){
            num -=k;
            if(num < 0){
                flag = false;
                break;
            }
            result ++;
        }
        if(flag == false) return -1;
        return result;
    }
};


int main(int argc, char const *argv[])
{
   Solution sol;
   sol.minimumNumbers(10,8);
    return 0;
}
