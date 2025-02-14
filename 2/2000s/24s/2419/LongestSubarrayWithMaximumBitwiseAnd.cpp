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