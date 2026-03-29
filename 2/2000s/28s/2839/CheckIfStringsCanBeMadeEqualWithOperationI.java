/*
https://leetcode.com/problems/check-if-strings-can-be-made-equal-with-operations-i/description/?envType=daily-question&envId=2026-03-29
*/

class Solution {
    public boolean canBeEqual(String s1, String s2) {
        StringBuilder s1cpy=new StringBuilder(s1);
        StringBuilder s2cpy=new StringBuilder(s2);
        int lengthOfString=s1.length();
        boolean areEqual=true;
        for(int i=0; i<lengthOfString; ++i){
            char charAtiInS2=s2.charAt(i);
            if(s1cpy.charAt(i)!=charAtiInS2){
                if(i+2>=lengthOfString){
                    areEqual=false;
                    break;
                }
                char charToCheck=s1cpy.charAt(i+2);
                if(charToCheck==charAtiInS2){
                    char temp=s1cpy.charAt(i);
                    s1cpy.setCharAt(i, s1cpy.charAt(i));
                    s1cpy.setCharAt(i+2, temp);
                } else{
                    areEqual=false;
                    break;
                }
            }
        }
        if(areEqual) return true;
        areEqual=true;
        for(int i=0; i<lengthOfString; ++i){
            char charAtiInS1=s1.charAt(i);
            if(s2cpy.charAt(i)!=charAtiInS1){
                if(i+2>=lengthOfString){
                    areEqual=false;
                    break;
                }
                char charToCheck=s2cpy.charAt(i+2);
                if(charToCheck==charAtiInS1){
                    char temp=s2cpy.charAt(i);
                    s2cpy.setCharAt(i, s2cpy.charAt(i));
                    s2cpy.setCharAt(i+2, temp);
                } else{
                    areEqual=false;
                    break;
                }
            }
        }
        return areEqual;
    }
}