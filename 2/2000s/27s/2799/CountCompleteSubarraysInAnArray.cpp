/*
https://leetcode.com/problems/count-complete-subarrays-in-an-array/description/?envType=daily-question&envId=2025-04-24
*/

class Solution {
public:

    bool isValid(set<int>&st, int sztochk){
        return st.size()==sztochk;
    }

    int countCompleteSubarrays(vector<int>& nums) {
        int sz=nums.size(), res=0;
        set<int>st;
        for(auto &vals: nums){
            st.insert(vals);
        }
        int szst=st.size();
        for(int i=0; i<sz; ++i){
            set<int>curr;
            for(int j=i; j<sz; ++j){
                curr.insert(nums[j]);
                if(isValid(curr, szst)) res++;
                else if(st.size()>szst) break;
            }
        }
        return res;
    }
};