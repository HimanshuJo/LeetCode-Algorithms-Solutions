/*
https://leetcode.com/problems/minimum-number-of-flips-to-make-the-binary-string-alternating/description/?envType=daily-question&envId=2026-03-07
*/

class Solution {

    public static int getI(char ch, int x){
        return ch-'0'==x?1:0;
    }

    public int minFlips(String s) {
        int lengthOfS=s.length();
        int[][] prefSum=new int[lengthOfS][2];
        for(int i=0; i<lengthOfS; ++i){
            prefSum[i][0]=(i==0?0:prefSum[i-1][1])+getI(s.charAt(i), 1);
            prefSum[i][1]=(i==0?0:prefSum[i-1][0])+getI(s.charAt(i), 0);
        }
        int resultantMinSwaps=Math.min(prefSum[lengthOfS-1][0], prefSum[lengthOfS-1][1]);
        if(lengthOfS%2!=0){
            int[][] suffSum=new int[lengthOfS][2];
            for(int i=lengthOfS-1; i>=0; --i){
                suffSum[i][0]=(i==lengthOfS-1?0:suffSum[i+1][1])+getI(s.charAt(i), 1);
                suffSum[i][1]=(i==lengthOfS-1?0:suffSum[i+1][0])+getI(s.charAt(i), 0);
            }
            for(int i=0; i+1<lengthOfS; ++i){
                resultantMinSwaps=Math.min(resultantMinSwaps, prefSum[i][0]+suffSum[i+1][0]);
                resultantMinSwaps=Math.min(resultantMinSwaps, prefSum[i][1]+suffSum[i+1][1]);
            }
        }
        return resultantMinSwaps;
    }
}