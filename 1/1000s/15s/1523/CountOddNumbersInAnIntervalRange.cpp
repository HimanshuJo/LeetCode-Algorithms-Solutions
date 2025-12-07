/*
https://leetcode.com/problems/count-odd-numbers-in-an-interval-range/?envType=daily-question&envId=2025-12-07
*/

class Solution {
public:
    int countOdds(int low, int high) {
        int res=0;
        if(low&1) res++;
        else if(high&1) res++;
        res+=((high-low)/2);
        return res;
    }
};