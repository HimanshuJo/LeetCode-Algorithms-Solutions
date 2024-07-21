/*
https://leetcode.com/problems/find-valid-matrix-given-row-and-column-sums/description/?envType=daily-question&envId=2024-07-20
*/

class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        int rws=rowSum.size(), cols=colSum.size();
        vector<int>curRowSum(rws, 0), curColSum(cols, 0);
        vector<vector<int>>resultantMatrix(rws, vector<int>(cols, 0));
        for(int i=0; i<rws; ++i){
            for(int j=0; j<cols; ++j){
                resultantMatrix[i][j]=min(rowSum[i]-curRowSum[i], colSum[j]-curColSum[j]);
                curRowSum[i]+=resultantMatrix[i][j];
                curColSum[j]+=resultantMatrix[i][j];
            }
        }
        return resultantMatrix;
    }
};