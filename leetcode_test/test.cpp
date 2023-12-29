#include <bits/stdc++.h>
using namespace std;
class Solution {

private:
    vector<int> father;
    int find(int u){
        return u == father[u] ? u : father[u] = find(father[u]);
    }
    void join(int u,int v){
        u = find(u);
        v = find(v);
        father[v] = u;
    }
    bool isSame(int u,int v,vector<int> &father){
        return find(u) == find(v);
    }
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        father.resize(n);
        for(int i = 0;i<father.size();i++) father[i] = i;
        for(vector<int> &edge : edges){
            join(edge[0],edge[1]);
        }
        return isSame(source,destination,father);
    }
};

int main(){
    Solution sol;
    vector<vector<int>> edges = {{0,1},{1,2},{2,0}};
    cout << sol.validPath(3,edges,0,2);
    return 0;
}