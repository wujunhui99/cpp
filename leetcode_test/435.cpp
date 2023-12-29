// #include <vector>
// #include <algorithm>
// using namespace std;
// class Solution {
// public:
//     int eraseOverlapIntervals(vector<vector<int>>& intervals) {
//         vector<vector<int>> vt;
//         if(intervals.size() <= 1) return intervals.size();
//         sort(intervals.begin(),intervals.end(),[](vector<int> &a, vector<int> &b){return a[0] < b[0];});
//         vt.push_back(vt.end(),intervals.begin(),intervals.begin()+1);
//         int result = 1;
//         for(int i = 1;i<intervals.size();i++){
//             if(intervals[i][0] > vt.back()[1] ){
//                 result ++;
//                 vt.push_back(intervals[i]);
//             }else{
//                 vt.back()[1] = max(vt.back()[1],intervals[i][1]);
//             }
            
//         }
//         return result;
//     }
// };