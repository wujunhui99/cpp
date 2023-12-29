#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        auto p1 = nums1.begin();
        auto p2 = nums2.begin();
        while(p2!=nums2.end()){
            if(p1 == nums1.end()){
                while(p2 != nums2.end()){
                    nums1.push_back(*p2);
                    p2++;
                }
            }
            if(*p1 > *p2){
                nums1.insert(p1,*p2);
                p2++;
            }else{
                p1++;
            }

        }
    }
    
};

int main(int argc, char const *argv[])
{
    Solution sol;
    sol.merge()
    return 0;
}
