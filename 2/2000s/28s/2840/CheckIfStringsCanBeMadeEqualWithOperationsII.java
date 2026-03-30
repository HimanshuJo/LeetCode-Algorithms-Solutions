/*
https://leetcode.com/problems/check-if-strings-can-be-made-equal-with-operations-ii/description/?envType=daily-question&envId=2026-03-30
*/

class Solution {
    public boolean checkStrings(String s1, String s2) {
        int lengthOfString=s1.length();
        int[] countEvenS1=new int[127];
        int[] countEvenS2=new int[127];
        int[] countOddS1=new int[127];
        int[] countOddS2=new int[127];
        for(int i=0; i<127; ++i){
            countEvenS1[i]=0;
            countEvenS2[i]=0;
            countOddS1[i]=0;
            countOddS2[i]=0;
        } 
        for(int i=0; i<lengthOfString; ++i){
            if(i%2!=0){
                countOddS1[s1.charAt(i)-'a']++;
                countOddS2[s2.charAt(i)-'a']++;
            } else{
                countEvenS1[s1.charAt(i)-'a']++;
                countEvenS2[s2.charAt(i)-'a']++;
            }
        }
        for(int i=0; i<127; ++i){
            if(countEvenS1[i]!=countEvenS2[i]||(countOddS1[i]!=countOddS2[i])) return false;
        }
        return true;
    }
}