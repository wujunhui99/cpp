#include <bits/stdc++.h>
using namespace std;
class Solution {
private:
    static const int N = 1010; 
     int father[N];
     int n ;
     void init(){
         for(int i = 0;i<N;i++){
             father[i] = i;
         }
     }
     void join(int u,int v){
         u = find(u);
         v = find(v);
         father[u] = v;
     }
     bool same(int u, int v){
         u = find(u);
         v = find(v);
         return u == v;
     }
     int find(int u){
         return u == father[u] ? u : father[u] = find(father[u]);
     }
     bool isTreeAfterRemoveEdge(const vector<vector<int>>& edges, int deleteEdge) {
        init(); // 初始化并查集

        for (int i = 0; i < n; i++) {
            if (i == deleteEdge) continue;
            if (same(edges[i][0], edges[i][1])) { // 构成有向环了，一定不是树
                return false;
            }
            join(edges[i][0], edges[i][1]);
        }
        return true;
    }
     vector<int> getRemoveEdge(vector<vector<int>>& edges){
         init();
         int n = edges.size();
         for(int i = 0;i<n;i++){
             if(same(edges[i][0],edges[i][1]))
                return edges[i];
            join(edges[i][0],edges[i][1]);
         }
         return {};
     }
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int inDegree[N] = {0}; // 记录节点入度
        n = edges.size(); // 边的数量
        for (int i = 0; i < n; i++) {
            inDegree[edges[i][1]]++; // 统计入度
        }
        vector<int> vec; // 记录入度为2的边（如果有的话就两条边）
        for(int i = n - 1; i >= 0; i-- ){
            if(inDegree[edges[i][1] == 2])
            if(inDegree[edges[i][1]] == 2)
                vec.push_back(i);
        }
        if(vec.size() > 0){
            if(isTreeAfterRemoveEdge(edges,vec[0]))
                return edges[vec[0]];
            else
                return edges[vec[1]];
        }
        return getRemoveEdge(edges);
    }
};
int main(){
    Solution sol;
    vector<vector<int>> edges = {{1,2},{2,3},{3,4},{4,1},{1,5}};
    auto ret = sol.findRedundantDirectedConnection(edges);
    cout << ret[0] << " "<< ret[1] << endl;
    return 0;
}