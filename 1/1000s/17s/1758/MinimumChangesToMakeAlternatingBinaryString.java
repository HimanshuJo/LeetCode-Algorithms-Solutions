/*
https://leetcode.com/problems/minimum-changes-to-make-alternating-binary-string/description/?envType=daily-question&envId=2026-03-05
*/

class Solution {

    public static boolean isStringValid(StringBuilder str){
        int lengthOfStr=str.length();
        char prevChar=str.charAt(0);
        for(int i=1; i<lengthOfStr; ++i){
            char nextChar=str.charAt(i);
            if(nextChar==prevChar){
                return false;
            }
            prevChar=nextChar;
        }
        return true;
    }

    public int minOperations(String s) {
        int lengthOfS=s.length(), countBgnWithZero=0, countBgnWithOne=0, resultantMinCount=Integer.MAX_VALUE;
        StringBuilder tempString1=new StringBuilder(s);
        StringBuilder tempString2=new StringBuilder(s);
        if(tempString1.charAt(0)!='0'){
            tempString1.setCharAt(0, '0');
            countBgnWithZero++;
        }
        if(isStringValid(tempString1)){
            resultantMinCount=Math.min(resultantMinCount, countBgnWithZero);
        }
        char prevChar=tempString1.charAt(0);
        for(int i=1; i<lengthOfS; ++i){
            char nextChar=tempString1.charAt(i);
            if(nextChar==prevChar){
                if(prevChar=='0'){
                    tempString1.setCharAt(i, '1');
                } else{
                    tempString1.setCharAt(i, '0');
                }
                countBgnWithZero++;
            }
            prevChar=tempString1.charAt(i);
            if(isStringValid(tempString1)){
                resultantMinCount=Math.min(resultantMinCount, countBgnWithZero);
                break;
            }
        }
        if(tempString2.charAt(0)!='1'){
            tempString2.setCharAt(0, '1');
            countBgnWithOne++;
        }
        if(isStringValid(tempString2)){
            resultantMinCount=Math.min(resultantMinCount, countBgnWithOne);
        }
        prevChar=tempString2.charAt(0);
        for(int i=1; i<lengthOfS; ++i){
            char nextChar=tempString2.charAt(i);
            if(nextChar==prevChar){
                if(prevChar=='0'){
                    tempString2.setCharAt(i, '1');
                } else{
                    tempString2.setCharAt(i, '0');
                }
                countBgnWithOne++;
            }
            prevChar=tempString2.charAt(i);
            if(isStringValid(tempString2)){
                resultantMinCount=Math.min(resultantMinCount, countBgnWithOne);
                break;
            }
        }
        return resultantMinCount;
    }
}