// #include <cstdio>
// #include <iostream>
// using namespace std;
// int main(){
//     int a,b,c;
//     while(scanf("%d%d%d",&a,&b,&c) != EOF){
//         int min_n = min(a,min(b,c));
//         int max_n = max(a,max(b,c));
//         int mid = a + b + c - min_n - max_n;
//         if(min_n*min_n + mid*mid == max_n*max_n){
//             printf("直角三角形\n");
//         }
//         else if(min_n*min_n + mid*mid > max_n*max_n){
//             printf("锐角三角形\n");
//         }
//         else{
//             printf("钝角三角形\n");
//         }
//     }
// }

// #include <cstdio>
// #include <string>
// using namespace std;
// int su(int n){
//     if(n % 10 != 1) return 0;
//     int ret = 1;
//     for(int i = 2; i * i <= n;i++){
//         if(n % i == 0){
//             ret = 0;
//             break;
//         }
//     }
//     return ret;
// }
// int main(){
//     int n;
//     while(scanf("%d",&n) != EOF){
//         for(int i = 2;i<n;i++){
//             if(su(i))
//                 printf("%d ",i);
//         }
//     }
// }

#include <cstdio>
#include <vector>
using namespace std;
int main(){
    int n;
    while(scanf("%d",&n) != EOF){
        int arr[n];
        for(int i = 0;i<n;i++){
            scanf("%d",arr+i);
        }
        int aim;
        scanf("%d",&aim);
        int idx = -1;
        for(int i = 0;i<n;i++){
            if(arr[i] == aim)
                idx = i;
                break;
        }
        printf("%d\n",idx);

    }
}