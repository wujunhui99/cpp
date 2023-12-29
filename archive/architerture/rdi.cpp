#include <random>
#include <iostream>
#include <chrono>
using namespace std;
int gen(int n){
    // 默认随机数生成器
    auto now = std::chrono::steady_clock::now();
    auto now_ms = std::chrono::time_point_cast<std::chrono::milliseconds>(now);
    auto now_val = now_ms.time_since_epoch().count();
    std::default_random_engine generator(now_val);

    // 生成均匀分布的随机数
    std::uniform_int_distribution<int> distribution(0, 128);
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            cout << distribution(generator) << " ";
        }
        cout  << endl;
    }
    
    return 0;
}

int main(int argc, char const *argv[])
{
    int n = 8192;
    cout << n << " " << n << endl;;
    gen(n);
}
