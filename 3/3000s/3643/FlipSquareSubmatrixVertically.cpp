/*
https://leetcode.com/problems/flip-square-submatrix-vertically/description/?envType=daily-question&envId=2026-03-21
*/

class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
       stack<vector<int>>stk;
       int rws=grid.size(), cols=grid[0].size();
       int maxI=x+k-1, maxJ=y+k-1;
       for(int i=x; i<=maxI; ++i){
        vector<int>curr;
        for(int j=y; j<=maxJ; ++j){
            curr.push_back(grid[i][j]);
        }
        stk.push(curr);
       }
       for(int i=x; i<=maxI; ++i){
        vector<int>curr=stk.top();
        stk.pop();
        int idx=0;
        for(int j=y; j<=maxJ; ++j){
            grid[i][j]=curr[idx++];
        }
       }
       return grid; 
    }
};