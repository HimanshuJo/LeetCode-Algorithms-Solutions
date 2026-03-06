/*
https://leetcode.com/problems/check-if-binary-string-has-at-most-one-segment-of-ones/description/?envType=daily-question&envId=2026-03-06
*/

class Solution {
    public boolean checkOnesSegment(String s) {
        int lengthOfS=s.length();
        if(lengthOfS==1&&s.charAt(0)=='1') return true;
        ArrayList<String>allStrings=new ArrayList<>();
        int currentIndex=0;
        StringBuilder currentString=new StringBuilder();
        while(true){
            if(currentIndex>=lengthOfS) break;
            char currentCharacter=s.charAt(currentIndex);
            if(currentCharacter=='1'){
                while(true){
                    if(currentIndex>=lengthOfS) break;
                    if(s.charAt(currentIndex)!='1') break;
                    currentString.append(s.charAt(currentIndex));
                    currentIndex++;
                }
                if(currentString.length()>=1){
                    allStrings.add(String.valueOf(currentString));
                    currentString=new StringBuilder("");
                }
            } else currentIndex++;
        }
        return allStrings.size()==1;
    }
}