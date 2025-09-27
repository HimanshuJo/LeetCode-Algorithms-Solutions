/*
https://leetcode.com/problems/longest-subarray-with-maximum-bitwise-and/?envType=daily-question&envId=2024-09-14
*/

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int sz=nums.size();
        int maxand=*max_element(nums.begin(), nums.end());
        int maxlen=0, currlen=0;
        for(int i=0; i<sz; ++i){
            if(nums[i]==maxand){
                currlen++;
                maxlen=max(maxlen, currlen);
            } else currlen=0;
        }
        return maxlen;
    }
};

// ------- ####### -------

class Solution2 {
public:
    int longestSubarray(vector<int>& nums) {
        int sz=nums.size(), maxVal=0, currentStreak=0, res=0;
        for(int i=0; i<sz; ++i){
            int curVal=nums[i];
            if(curVal>maxVal){
                maxVal=curVal;
                res=0;
                currentStreak=0;
            }
            if(curVal==maxVal){
                currentStreak++;
            } else{
                currentStreak=0;
            }
            res=max(res, currentStreak);
        }
        return res;
    }
};
