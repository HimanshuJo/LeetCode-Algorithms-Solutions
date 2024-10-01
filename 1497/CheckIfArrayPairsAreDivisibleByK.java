/*
https://leetcode.com/problems/check-if-array-pairs-are-divisible-by-k/description/?envType=daily-question&envId=2024-10-01
*/

class Solution {
    public boolean canArrange(int[] arr, int k) {
        int[] remainderCount=new int[k];
        for(int vals: arr){
            int currentRemainder=vals%k;
            if(currentRemainder<0) currentRemainder+=k;
            remainderCount[currentRemainder]++;
        }
        for(int i=1; i<=k/2; ++i){
            if(remainderCount[i]!=remainderCount[k-i]) return false;
        }
        return remainderCount[0]%2==0;
    }
}