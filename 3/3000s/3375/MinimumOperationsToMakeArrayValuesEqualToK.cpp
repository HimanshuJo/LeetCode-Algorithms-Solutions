/*
https://leetcode.com/problems/minimum-operations-to-make-array-values-equal-to-k/description/?envType=daily-question&envId=2025-04-09
*/

class Solution {
public:

    bool isValid(vector<int>&vec, int val){
        int sz=vec.size(), tochk=-1;
        for(int i=0; i<sz; ++i){
            if(vec[i]>val){
                tochk=vec[i];
                break;
            }
        }
        if(tochk==-1) return false;
        for(int i=0; i<sz; ++i){
            if(vec[i]>val){
                if(vec[i]!=tochk) return false;
            }
        }
        return true;
    }

    bool isValidK(vector<int>&vec, int val, bool &flag){
        for(int i=0; i<vec.size(); ++i){
            if(vec[i]<val) return false;
            else if(vec[i]!=val){
                if(!flag) flag=true;
            }
        }
        return true;
    }

    int minOperations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        set<int>seen;
        int sz=nums.size(), res=0;
        if(sz==1){
            if(nums[0]<k) return -1;
            if(nums[0]!=k) res++;
            return res;
        }
        bool flag1=false;
        for(int i=0; i<sz; ++i){
            if(nums[i]!=k){
                flag1=true;
                break;
            }
        }
        if(!flag1) return res;
        if(isValid(nums, k)){
            bool flag=false;
            if(isValidK(nums, k, flag)){
                if(flag)
                    res++;
                return res;
            }
        }
        for(int i=sz-1; i>=0; --i){
            if(seen.find(nums[i])==seen.end()){
                if(isValid(nums, nums[i])){
                    seen.insert(nums[i]);
                    for(int j=0; j<sz; ++j){
                        if(nums[j]>nums[i]){
                            nums[j]=nums[i];
                        }
                    }
                    res++;
                    if(isValid(nums, k)){
                        bool flag=false;
                        if(isValidK(nums, k, flag)){
                            if(flag)
                                res++;
                            return res;
                        }
                    }
                }
            }
        }
        return -1;
    }
};