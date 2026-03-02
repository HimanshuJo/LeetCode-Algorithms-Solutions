/*
https://leetcode.com/problems/minimum-swaps-to-arrange-a-binary-grid/description/?envType=daily-question&envId=2026-03-02
*/

class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int sz=grid.size();
        vector<int>pos(sz, -1);
        for(int i=0; i<sz; ++i){
            for(int j=sz-1; j>=0; --j){
                if(grid[i][j]==1){
                    pos[i]=j;
                    break;
                }
            }
        }
        int res=0;
        for(int i=0; i<sz; ++i){
            int k=-1;
            for(int j=i; j<sz; ++j){
                if(pos[j]<=i){
                    res+=j-i;
                    k=j;
                    break;
                }
            }
            if(~k){
                for(int j=k; j>i; --j){
                    swap(pos[j], pos[j-1]);
                }
            } else return -1;
        }
        return res;
    }
};