/*
https://leetcode.com/problems/four-divisors/description/?envType=daily-question&envId=2026-01-04
*/

class Solution {

    public int findDivisorsSum(int num){
        int totalSumDivisors=0, divisorsCount=0;
        boolean isCountGreaterThan4=false;
        for(int i=1; i<=num; ++i){
            if(num%i==0){
                divisorsCount++;
                totalSumDivisors+=i;
            }
            if(divisorsCount>4){
                isCountGreaterThan4=true;
                break;
            }
        }
        return isCountGreaterThan4?0:divisorsCount==4?totalSumDivisors:0;
    }

    public int sumFourDivisors(int[] nums) {
        int resultantSum=0;
        for(int num: nums){
            resultantSum+=findDivisorsSum(num);
        }
        return resultantSum;
    }
}