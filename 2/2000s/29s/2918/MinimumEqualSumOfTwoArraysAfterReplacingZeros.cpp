/*
https://leetcode.com/problems/minimum-equal-sum-of-two-arrays-after-replacing-zeros/description/?envType=daily-question&envId=2025-05-10
*/

class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        long long sm1=0, sm2=0;
        int count1=0, count2=0;
        for(auto &vals: nums1){
            if(vals==0) count1++;
            sm1+=vals;
        }
        for(auto &vals: nums2){
            if(vals==0) count2++;
            sm2+=vals;
        }
        if(sm1==sm2&&count1!=0&&count2!=0) return sm1+=max(count1, count2);
        if((sm2+count2)>(sm1+count1)){
            while(count2--){
                sm2++;
            }
            if(count1==0&&sm1!=sm2) return -1;
            else if(count1==0&&sm1==sm2) return sm2;
            while(count1!=1){
                sm1++;
                count1--;
            }
            if(sm1>=sm2) return -1;
            sm1+=(sm2-sm1);
            return sm2;
        }
        while(count1--){
            sm1++;
        }
        if(count2==0&&sm1!=sm2) return -1;
        else if(count2==0&&sm1==sm2) return sm1;
        while(count2!=1){
            sm2++;
            count2--;
        }
        if(sm2>=sm1) return -1;
        sm2+=(sm1-sm2);
        return sm1;
    }
};