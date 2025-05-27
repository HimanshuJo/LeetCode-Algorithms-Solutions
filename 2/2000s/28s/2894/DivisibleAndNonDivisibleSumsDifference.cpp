/*
https://leetcode.com/problems/divisible-and-non-divisible-sums-difference/?envType=daily-question&envId=2025-05-27
*/

class Solution {
public:
    int differenceOfSums(int n, int m) {
        int sm1=0, sm2=0;
        for(int i=1; i<=n; ++i){
            if(i%m!=0) sm1+=i;
            else sm2+=i;
        }
        return sm1-sm2;
    }
};