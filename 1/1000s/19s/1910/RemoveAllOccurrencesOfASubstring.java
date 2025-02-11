/*
https://leetcode.com/problems/remove-all-occurrences-of-a-substring/description/?envType=daily-question&envId=2025-02-11
*/

class Solution {
    public String removeOccurrences(String s, String part) {
        StringBuilder temporaryS=new StringBuilder(s);
        while(true){
            int lengthOfS=temporaryS.length();
            if(lengthOfS==0) break;
            int firstIndexOfPart=(String.valueOf(temporaryS)).indexOf(part);
            if(firstIndexOfPart!=-1){
                int count=part.length();
                while(count-- >0){
                    temporaryS.setCharAt(firstIndexOfPart++, '#');
                }
                temporaryS=new StringBuilder(String.valueOf(temporaryS).replaceAll("#", ""));
            } else break;
        }
        return String.valueOf(temporaryS);
    }
}