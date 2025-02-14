/*
https://leetcode.com/problems/convert-1d-array-into-2d-array/description/?envType=daily-question&envId=2024-09-01
*/

class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        vector<vector<int>>res(m, vector<int>(n, -1));
        int sz=original.size(), currw=0, curcol=0;
        if(sz%m!=0||sz/m!=n||(m==sz&&n!=1||(m>sz||n>sz))){
            res.clear();
            return res;
        }
        for(int i=0; i<sz; ++i){
            if(curcol==n-1){
                res[currw][curcol]=original[i];
                curcol=0;
                currw++;
            } else{
                res[currw][curcol]=original[i];
                curcol++;
            }
        }
        return res;
    }
};