/*
https://leetcode.com/problems/count-special-triplets/description/?envType=daily-question&envId=2025-12-09
*/

class Solution_TLE {
public:
    int specialTriplets(vector<int>& nums) {
        int sz=nums.size(), res=0;
        map<int, vector<int>>mp;
        for(int i=0; i<sz; ++i){
            mp[nums[i]].push_back(i);
        }
        for(int i=0; i<sz; ++i){
            if(i+1<=sz-1){
                for(int j=i+1; j<sz; ++j){
                    if(j+1<=sz-1){
                        int numsi=nums[i], numsj=nums[j];
                        if(numsi==numsj*2){
                            auto itr=mp.find(numsi);
                            if(itr!=mp.end()){
                                auto idxToCheckVec=mp[numsi];
                                for(auto &idxToCheck: idxToCheckVec){
                                    if(idxToCheck!=i&&idxToCheck!=j&&idxToCheck>i&&idxToCheck>j){
                                        res++;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        return res;
    }
};

// ------- ******* -------

class Solution_Opt {
public:
    int specialTriplets(vector<int>& nums) {
        int n=nums.size(), MOD=1e9+7, result=0;
        map<long long, long long>leftCount, rightCount;
        for(auto &num: nums){
            rightCount[num]++;
        }
        for (int j = 0; j < n; ++j) {
            long long val = nums[j];
            long long need = val * 2;

            rightCount[val]--;

            long long L = leftCount[need];
            long long R = rightCount[need];

            result = (result + (L * R) % MOD) % MOD;

            leftCount[val]++;
        }
        return result%MOD;
    }
};