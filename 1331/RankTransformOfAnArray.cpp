/*
https://leetcode.com/problems/rank-transform-of-an-array/description/?envType=daily-question&envId=2024-10-02
*/

class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {        
        set<int>tmp;
        for(auto &vals: arr) tmp.insert(vals);
        vector<int>tmpvec;
        for(auto &vals: tmp) tmpvec.push_back(vals);
        vector<int>res;
        for(auto &vals: arr){
            auto itr=lower_bound(tmpvec.begin(), tmpvec.end(), vals);
            int idx=itr-tmpvec.begin();
            res.push_back(idx+1);
        }
        return res;
    }
};