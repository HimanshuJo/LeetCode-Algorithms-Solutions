/*
https://leetcode.com/problems/count-vowel-strings-in-ranges/?envType=daily-question&envId=2025-01-02
*/

class Solution {

    public static HashMap<Character, Character>vowelsMap=new HashMap<>();

    Solution(){
        vowelsMap.put('a', 'a');
        vowelsMap.put('e', 'e');
        vowelsMap.put('i', 'i');
        vowelsMap.put('o', 'o');
        vowelsMap.put('u', 'u');
    }

    public static boolean isVowel(Character currentCharacter){
        return vowelsMap.containsKey(currentCharacter);
    }

    public int[] vowelStrings(String[] words, int[][] queries) {
        int lengthOfWords=words.length;
        ArrayList<Integer>prefixArray=new ArrayList<>();
        for(int i=0; i<lengthOfWords; ++i){
            String currentString=words[i];
            if(isVowel(currentString.charAt(0))&&isVowel(currentString.charAt(currentString.length()-1))){
                if(prefixArray.size()==0) prefixArray.add(1);
                else prefixArray.add(prefixArray.get(prefixArray.size()-1)+1);
            } else{
                if(prefixArray.size()==0) prefixArray.add(0);
                else prefixArray.add(prefixArray.get(prefixArray.size()-1));
            }
        }
        int queriesLength=queries.length, index=0;
        int[] resultantArray=new int[queriesLength];
        for(int[] query: queries){
            int beginIndex=query[0], endIndex=query[1];
            int totalCount=prefixArray.get(endIndex), requiredCount=(beginIndex==0?totalCount:totalCount-prefixArray.get(beginIndex-1));
            resultantArray[index++]=requiredCount;
        }
        return resultantArray;
    }
}