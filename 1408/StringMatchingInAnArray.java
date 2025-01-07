/*
https://leetcode.com/problems/string-matching-in-an-array/description/?envType=daily-question&envId=2025-01-07
*/

class Solution {

    public static boolean checkForSubstring(String stringToCheck, String currentString){
        return currentString.contains(stringToCheck);
    }

    public List<String> stringMatching(String[] words) {
        ArrayList<String>resultantList=new ArrayList<>();
        int lengthOfWords=words.length;
        for(int i=0; i<lengthOfWords; ++i){
            String stringToCheck=words[i];
            for(int j=0; j<lengthOfWords; ++j){
                if(i!=j){
                    String currentString=words[j];
                    if(stringToCheck.length()<=currentString.length()){
                        boolean isSubstring=checkForSubstring(stringToCheck, currentString);
                        if(isSubstring){
                            resultantList.add(stringToCheck);
                            break;
                        }
                    }
                }
            }
        }
        return resultantList;
    }
}