/*
https://leetcode.com/problems/maximum-difference-by-remapping-a-digit/description/?envType=daily-question&envId=2025-06-14
*/

class Solution {
    public int minMaxDifference(int num) {
        String numAsString=String.valueOf(num);
        int lengthOfNumAsString=numAsString.length(), 
            maxNumFormed=Integer.MIN_VALUE, minNumFormed=Integer.MAX_VALUE;
        for(int i=0; i<lengthOfNumAsString; ++i){
            StringBuilder newStringToBeFormed;
            char currentChar=numAsString.charAt(i);
            for(int j=0; j<=9; ++j){
                newStringToBeFormed=new StringBuilder();
                for(int i2=0; i2<i; ++i2){
                    newStringToBeFormed.append(numAsString.charAt(i2));
                }
                newStringToBeFormed.append(String.valueOf(j));
                for(int i3=i+1; i3<lengthOfNumAsString; ++i3){
                    if(numAsString.charAt(i3)!=currentChar){
                        newStringToBeFormed.append(numAsString.charAt(i3));
                    } else{
                        newStringToBeFormed.append(String.valueOf(j));
                    }
                }
                maxNumFormed=Math.max(maxNumFormed, Integer.parseInt(String.valueOf(newStringToBeFormed)));
                minNumFormed=Math.min(minNumFormed, Integer.parseInt(String.valueOf(newStringToBeFormed)));
            }
        }
        return maxNumFormed-minNumFormed;
    }
}