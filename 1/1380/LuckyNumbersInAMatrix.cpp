/*
https://leetcode.com/problems/lucky-numbers-in-a-matrix/description/?envType=daily-question&envId=2024-07-19
*/

class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int rws=matrix.size(), cols=matrix[0].size();
        vector<int>res;
        for(int j=0; j<cols; ++j){
            vector<int>frcurcol;
            unordered_map<int, int>frrw;
            for(int i=0; i<rws; ++i){
                frcurcol.push_back(matrix[i][j]);
                frrw[matrix[i][j]]=i;
            }
            sort(frcurcol.begin(), frcurcol.end());
            int curmaxeleincol=frcurcol.back(), rwtochk=frrw[curmaxeleincol], nwmin=INT_MAX;
            for(int jj=0; jj<cols; ++jj){
                nwmin=min(nwmin, matrix[rwtochk][jj]);
            }
            if(curmaxeleincol==nwmin) res.push_back(nwmin);
        }
        return res;
    }
};