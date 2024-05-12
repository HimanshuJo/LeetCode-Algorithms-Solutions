/*
https://leetcode.com/problems/largest-local-values-in-a-matrix/description/?envType=daily-question&envId=2024-05-12
*/

class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        vector<vector<int>>res;
        int rws=grid.size(), cols=grid[0].size();
        for(int i=0; i<rws; ++i){
            vector<int>curr;
            for(int j=0; j<cols; ++j){
                if(i+2<=rws-1&&j+2<=cols-1){
                    int curmax=INT_MIN;
                    for(int k=i; k!=i+3; ++k){
                        for(int l=j; l!=j+3; ++l){
                            curmax=max(curmax, grid[k][l]);
                        }
                    }
                    curr.push_back(curmax);
                } else break;
            }
            if(curr.size()>=1)
                res.push_back(curr);
        }
        return res;
    }
};