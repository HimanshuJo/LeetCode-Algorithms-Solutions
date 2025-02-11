/*
https://leetcode.com/problems/check-if-array-is-sorted-and-rotated/description/?envType=daily-question&envId=2025-02-02
*/

class Solution {
public:

    vector<int> rotateRight(vector<int>&nums, int positions){
        int sz=nums.size();
        vector<int>res(sz, -1);
        for(int i=0; i<sz; ++i){
            res[(i+positions)%sz]=nums[i];
        }
        return res;
    }

    bool check(vector<int>& nums) {
        vector<int>tmpvec=nums;
        sort(tmpvec.begin(), tmpvec.end());
        int sz=nums.size();
        for(int i=0; i<sz; ++i){
            vector<int>tochkvec=rotateRight(nums, i+1);
            if(tochkvec==tmpvec) return true;
        }
        return false;
    }
};

// ------- ******* -------

class SolutionOptimal {
public:
    bool check(vector<int>& nums) {
        int sz=nums.size(), breakCount=0;
        for(int i=0; i<sz; ++i){
            if(nums[i]>nums[(i+1)%sz]) breakCount++;
        }
        return breakCount<=1;
    }
};