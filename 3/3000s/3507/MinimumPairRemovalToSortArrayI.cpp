/*
https://leetcode.com/problems/minimum-pair-removal-to-sort-array-i/description/?envType=daily-question&envId=2026-01-22
*/

class Solution {
public:

    bool isValid(vector<int>&nums){
        vector<int>tochk=nums;
        sort(tochk.begin(), tochk.end());
        if(tochk==nums) return true;
        return false;
    }

    int minimumPairRemoval(vector<int>& nums) {
        int sz=nums.size(), res=0;
        while(true){
            if(isValid(nums)) break;
            map<int, vector<pair<int, int>>>mp;
            for(int i=0; i<sz; ++i){
                if(i+1<=sz-1){
                    int cursm=nums[i]+nums[i+1];
                    mp[cursm].push_back({i, i+1});;
                }
            }
            auto itr=mp.begin();
            int smToAd=itr->first;
            auto pair=(itr->second)[0];
            int frstIdx=pair.first, secIdx=pair.second;
            vector<int>nwNums;
            int idx=0;
            while(true){
                if(idx>=sz) break;
                if(idx==frstIdx){
                    nwNums.push_back(smToAd);
                    nums[idx]=-1e9;
                    nums[idx+1]=-1e9;
                    idx+=2;
                } else nwNums.push_back(nums[idx++]);
            }
            nums.erase(remove(nums.begin(), nums.end(), -1e9), nums.end());
            nums=nwNums;
            sz=nums.size();
            res++;
        }
        return res;
    }
};