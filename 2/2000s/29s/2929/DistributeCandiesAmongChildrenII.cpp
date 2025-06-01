/*
https://leetcode.com/problems/distribute-candies-among-children-ii/?envType=daily-question&envId=2025-06-01
*/

class Solution {
public:

    long long calComb(int val){
        if(val<0) return 0;
        return (long long)val*(val-1)/2;
    }

    long long distributeCandies(int n, int limit) {
        return calComb(n+2)- // Total unrestricted distributions
              3*calComb(n-(limit+1)+2) // At least one child receives more than limit candies; 3 choices
              +3*calComb(n-2*(limit+1)+2) // At least two children receive more than limit candies; 3 choices
              -calComb(n-3*(limit+1)+2); // All three receive more than limit candies
    }
};