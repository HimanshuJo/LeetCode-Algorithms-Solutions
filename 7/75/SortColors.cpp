/*
https://leetcode.com/problems/sort-colors/description/?envType=daily-question&envId=2025-05-17
*/

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int sz=nums.size(), count0=0, count1=0, count2=0, idx=0;
        for(auto &vals: nums){
            if(vals==0) count0++;
            else if(vals==1) count1++;
            else count2++;
        }
        while(true){
            if(idx>=sz) break;
            while(count0--){
                nums[idx++]=0;
                if(idx>=sz) break;
            }
            while(count1--){
                nums[idx++]=1;
                if(idx>=sz) break;
            }
            while(count2--){
                nums[idx++]=2;
                if(idx>=sz) break;
            }
        }
    }
};