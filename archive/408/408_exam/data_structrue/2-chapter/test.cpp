using namespace std;
#include <iostream>
int main(){
    int *p = new int[10];
    for(int i = 0;i<10;i++) p[i] = i;
    cout << p[5] <<endl;
}