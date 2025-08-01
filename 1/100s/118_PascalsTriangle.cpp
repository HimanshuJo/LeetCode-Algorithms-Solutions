/*
https://leetcode.com/problems/pascals-triangle/description/?envType=daily-question&envId=2025-08-01
*/

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>res;
        res.push_back({1});
        if(numRows==1) return res;
        res.push_back({1, 1});
        if(numRows==2) return res;
        for(int i=2; i<numRows; ++i){
            vector<int>curr;
            curr.push_back(1);
            vector<int>prev=res[i-1];
            int j=0;
            while(true){
                if(j+1>=prev.size()) break;
                int cursm=prev[j]+prev[j+1];
                j++;
                curr.push_back(cursm);
            }
            curr.push_back(1);
            res.push_back(curr);
        }
        return res;
    }
};
