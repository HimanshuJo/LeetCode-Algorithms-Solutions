/*
https://leetcode.com/problems/final-value-of-variable-after-performing-operations/description/?envType=daily-question&envId=2025-10-20
*/

class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int res=0;
        for(auto &vals: operations){
            if(vals=="++X"||vals=="X++"){
                res++;
            } else res--;
        }
        return res;
    }
};