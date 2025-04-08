/*
https://leetcode.com/problems/minimum-number-of-operations-to-make-elements-in-array-distinct/description/?envType=daily-question&envId=2025-04-08
*/

class Solution {
public:

    bool isValid(vector<int>&nums){
        int sz=nums.size();
        if(sz==0) return true;
        unordered_map<int, int>mp;
        for(int i=0; i<sz; ++i){
            if(mp.find(nums[i])!=mp.end()) return false;
            mp[nums[i]]=nums[i];
        }
        return true;
    }

    int minimumOperations(vector<int>& nums) {
        int sz=nums.size(), res=0;
        while(true){
            if(isValid(nums)) break;
            if(nums.size()<3){
                res++;
                break;
            } else{
                nums[0]=-1, nums[1]=-1, nums[2]=-1;
                nums.erase(remove(nums.begin(), nums.end(), -1), nums.end());
                res++;
            }
        }
        return res;
    }
};
