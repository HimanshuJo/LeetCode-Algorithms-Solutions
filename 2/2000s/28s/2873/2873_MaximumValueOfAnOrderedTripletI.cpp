/*
https://leetcode.com/problems/maximum-value-of-an-ordered-triplet-i/description/?envType=daily-question&envId=2025-04-02
*/

class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int sz=nums.size();
        long long res=LONG_MIN;
        for(int i=0; i<sz; ++i){
            if(i+1<=sz-1){
                for(int j=i+1; j<sz; ++j){
                    if(j+1<=sz-1){
                        for(int k=j+1; k<sz; ++k){
                            long long tochk=(nums[i]-nums[j])*(long long)nums[k];
                            if(tochk>=0) res=max(res, tochk);
                        }
                    }
                }
            }
        }
        return res!=LONG_MIN?res:0;
    }
};
