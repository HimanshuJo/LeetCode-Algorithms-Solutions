/*
https://leetcode.com/problems/longest-binary-subsequence-less-than-or-equal-to-k/description/?envType=daily-question&envId=2025-06-26
*/

class Solution {
    public int longestSubsequence(String s, int k) {
        int lengthOfS=s.length();
        int currentTotalValue=0, currentPowOfTwo=1, resultantMaxLength=0;
        for(int i=0; i<lengthOfS; ++i){
            if(s.charAt(i)=='0'){
                resultantMaxLength++;
            }
        }
        for(int i=lengthOfS-1; i>=0; --i){
            if(s.charAt(i)=='1'){
                if(currentPowOfTwo<=k&&currentTotalValue+currentPowOfTwo<=k){
                    currentTotalValue+=currentPowOfTwo;
                    resultantMaxLength++;
                }
            }
            if(currentPowOfTwo<=k){
                currentPowOfTwo<<=1;
            } else break;
        }
        return resultantMaxLength;
    }
}