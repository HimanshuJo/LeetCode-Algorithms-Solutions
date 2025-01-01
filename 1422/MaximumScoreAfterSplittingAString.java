/*
https://leetcode.com/problems/maximum-score-after-splitting-a-string/description/?envType=daily-question&envId=2025-01-01
*/

class Solution {

    public static int countZeros(StringBuilder str){
        int lengthOfS=str.length(), countZ=0;
        for(int i=0; i<lengthOfS; ++i){
            if(str.charAt(i)=='0') countZ++;
        }
        return countZ;
    }

    public static int countOnes(StringBuilder str){
        int lengthOfS=str.length(), countOn=0;
        for(int i=0; i<lengthOfS; ++i){
            if(str.charAt(i)=='1') countOn++;
        }
        return countOn;
    }

    public int maxScore(String s) {
        int lengthOfS=s.length(), resultantMaxScore=0;
        for(int i=0; i<lengthOfS; ++i){
            StringBuilder currentString=new StringBuilder();
            for(int j=i; j<lengthOfS; ++j){
                currentString.append(s.charAt(j));
                if(j+1<=lengthOfS-1){
                    StringBuilder nextString=new StringBuilder();
                    for(int k=j+1; k<lengthOfS; ++k){
                        nextString.append(s.charAt(k));
                    }
                    int countLeft=countZeros(currentString), countRight=countOnes(nextString);
                    resultantMaxScore=Math.max(resultantMaxScore, countLeft+countRight);
                }
            }
        }
        return resultantMaxScore;
    }
}