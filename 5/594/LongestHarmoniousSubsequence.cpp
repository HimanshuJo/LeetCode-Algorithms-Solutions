/*
https://leetcode.com/problems/longest-harmonious-subsequence/description/?envType=daily-question&envId=2025-06-30
*/

class Solution {
public:
    int findLHS(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int sz=nums.size(), res=0;
        for(int i=0; i<sz; ++i){
            vector<int>curr;
            for(int j=i; j<sz; ++j){
                if(curr.size()==0){
                    curr.push_back(nums[j]);
                } else{
                    int tochk=nums[j];
                    if(tochk<curr[0]){
                        if(curr[curr.size()-1]-tochk==1){
                            curr.push_back(nums[j]);
                        }
                    } else if(tochk>curr[curr.size()-1]){
                        if(tochk-curr[0]==1){
                            curr.push_back(nums[j]);
                        } else break;
                    } else{
                        curr.push_back(nums[j]);
                    }
                }
            }
            int tohcksz=curr.size();
            if(curr[curr.size()-1]-curr[0]==1)
                res=max(res, tohcksz);
        }
        return res;
    }
};