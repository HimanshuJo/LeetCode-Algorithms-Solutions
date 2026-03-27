/*
https://leetcode.com/problems/matrix-similarity-after-cyclic-shifts/description/?envType=daily-question&envId=2026-03-27
*/

class Solution {
public:

    void shiftRight(vector<int>&matrw, const int cols){
        int prev=matrw[0];
        matrw[0]=matrw[cols-1];
        for(int j=1; j<=cols-1; ++j){
            int next=matrw[j];
            matrw[j]=prev;
            prev=next;
        }
    }

    void shiftLeft(vector<int>&matrw, const int cols){
        int prev=matrw[cols-1];
        matrw[cols-1]=matrw[0];
        for(int j=cols-2; j>=0; --j){
            int next=matrw[j];
            matrw[j]=prev;
            prev=next;
        }
    }

    bool areSimilar(vector<vector<int>>& mat, int k) {
        vector<vector<int>>matcpy=mat;
        int rws=mat.size(), cols=mat[0].size();
        while(k--){
            for(int i=0; i<rws; ++i){
                if(i%2==0){
                    shiftLeft(mat[i], cols);
                } else{
                    shiftRight(mat[i], cols);
                }
            }
        }
        return mat==matcpy;
    }
};