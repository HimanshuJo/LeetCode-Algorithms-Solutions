/*
https://leetcode.com/problems/find-all-k-distant-indices-in-an-array/description/?envType=daily-question&envId=2025-06-24
*/

class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        vector<int>res, kyIndices;
        int sz=nums.size();
        for(int i=0; i<sz; ++i){
            if(nums[i]==key){
                kyIndices.push_back(i);
            }
        }
        for(int i=0; i<sz; ++i){
            int curidx=i;
            for(auto &vals: kyIndices){
                if(abs(curidx-vals)<=k){
                    res.push_back(i);
                    break;
                }
            }
        }
        return res;
    }
};