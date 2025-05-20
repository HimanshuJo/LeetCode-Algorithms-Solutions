/*
https://leetcode.com/problems/zero-array-transformation-i/description/?envType=daily-question&envId=2025-05-20
*/

class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int sz1=nums.size(), sz2=queries.size();
        vector<int>diffVec(sz1+1, 0);
        for(int i=0; i<sz2; ++i){
            int lft=queries[i][0], rght=queries[i][1];
            diffVec[lft]++, diffVec[rght+1]--;
        }
        vector<int>allAvlOperations;
        int curOperations=0;
        for(auto &vals: diffVec){
            curOperations+=vals;
            allAvlOperations.push_back(curOperations);
        }
        for(int i=0; i<sz1; ++i){
            if(allAvlOperations[i]<nums[i]) return false;
        }
        return true;
    }
};