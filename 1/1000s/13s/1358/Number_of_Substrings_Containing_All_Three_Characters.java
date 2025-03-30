/*
https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/?envType=daily-question&envId=2025-03-11
*/

class Solution {

    public static boolean hasAllRequiredCharacters(int[] freqArray){
        return freqArray[0]>=1&&freqArray[1]>=1&&freqArray[2]>=1;
    }

    public int numberOfSubstrings(String s) {
        int lengthOfS=s.length(), leftPointer=0, rightPointer=0, resultantNumSubstrings=0;
        int[] freqArray=new int[3];
        freqArray[0]=0;
        freqArray[1]=0;
        freqArray[2]=0;
        while(rightPointer<lengthOfS){
            char currentCharacter=s.charAt(rightPointer);
            freqArray[currentCharacter-'a']++;
            while(hasAllRequiredCharacters(freqArray)){
                resultantNumSubstrings+=(lengthOfS-rightPointer);
                char atLeft=s.charAt(leftPointer);
                freqArray[atLeft-'a']--;
                leftPointer++;
            }
            rightPointer++;
        }
        return resultantNumSubstrings;
    }
}
