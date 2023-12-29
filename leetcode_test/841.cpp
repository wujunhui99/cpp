#include <bits/stdc++.h>
using namespace std;
class Solution {
private:
    void dfs(vector<vector<int>> &rooms, int key, vector<bool> visited){
        vector<int> keys = rooms[key];
        for(int newKey :keys){
            if(!visited[newKey]){
                visited[newKey] = true;
                dfs(rooms,newKey,visited);
            }
        }
    }
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<bool> visited(rooms.size(),false);
        visited[0] = true;
        dfs(rooms,0,visited);
        for(bool v : visited){
            if(!v) return false;
        }
        return true;
    }
};
int main(){
    Solution sol;
    vector<vector<int>> rooms = {{1},{2},{3},{}};
    sol.canVisitAllRooms(rooms);
    return 0;
}