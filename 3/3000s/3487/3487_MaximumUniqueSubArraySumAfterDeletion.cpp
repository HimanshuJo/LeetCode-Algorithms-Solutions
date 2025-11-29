/*
https://leetcode.com/problems/maximum-unique-subarray-sum-after-deletion/description/?envType=daily-question&envId=2025-07-25
*/

class Solution {
public:
    int maxSum(vector<int>& nums) {
        int res=0, maxNum=INT_MIN;
        set<int>st;
        for(auto &vals: nums){
            st.insert(vals);
            maxNum=max(maxNum, vals);
        }
        bool flag=false;
        for(auto &vals: st){
            if(vals>=0){
                flag=true;
                res+=vals;
            }
        }
        if(!flag) return maxNum;
        return res;
    }
};

// ------- ******* -------

class Solution2 {
public:
    int maxSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int res=0, maxNum=-101;
        bool flag=false;
        int prev=-101;
        for(auto &vals: nums){
            if(vals!=prev){
                if(vals>=0){
                    flag=!flag?true:flag;
                    res+=vals;
                    prev=vals;
                }
            }
            maxNum=max(maxNum, vals);
        }
        return !flag?maxNum:res;
    }
};
