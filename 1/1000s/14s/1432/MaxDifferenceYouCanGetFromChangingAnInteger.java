/*
https://leetcode.com/problems/max-difference-you-can-get-from-changing-an-integer/description/?envType=daily-question&envId=2025-06-15
*/

class Solution {
    public int maxDiff(int num) {
        String numAsString=String.valueOf(num);
        StringBuilder toBeProcessedString=new StringBuilder(numAsString);
        int lengthOfString=numAsString.length(),
            maxNumToBeFormed=Integer.MIN_VALUE,
            minNumToBeFormed=Integer.MAX_VALUE;
        for(int i=lengthOfString-1; i>=0; --i){
            char currentChar=toBeProcessedString.charAt(i);
            for(int i2=0; i2<=9; ++i2){
                StringBuilder newStringToBeFormed=new StringBuilder();
                for(int i3=0; i3<lengthOfString; ++i3){
                    if(toBeProcessedString.charAt(i3)!=currentChar){
                        newStringToBeFormed.append(toBeProcessedString.charAt(i3));
                    } else{
                        newStringToBeFormed.append(String.valueOf(i2));
                    }
                }
                int valToCheck=Integer.parseInt(String.valueOf(newStringToBeFormed));
                char currentCharToCheck=newStringToBeFormed.charAt(0);
                if(currentCharToCheck!='0'){
                    maxNumToBeFormed=Math.max(maxNumToBeFormed, valToCheck);
                    minNumToBeFormed=Math.min(minNumToBeFormed, valToCheck);
                }
            }
        }
        return maxNumToBeFormed-minNumToBeFormed;
    }
}