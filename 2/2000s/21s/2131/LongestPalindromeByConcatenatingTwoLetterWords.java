/*
https://leetcode.com/problems/longest-palindrome-by-concatenating-two-letter-words/description/?envType=daily-question&envId=2025-05-25
*/

class Solution {
    public int longestPalindrome(String[] words) {
        TreeMap<String, Integer>wordsCount=new TreeMap<>();
        for(String word: words){
            if(wordsCount.containsKey(word)){
                wordsCount.put(word, wordsCount.get(word)+1);
            } else{
                wordsCount.put(word, 1);
            }
        }
        boolean canHaveMiddleString=false;
        int resultantLength=0;
        for(Map.Entry<String, Integer>entry: wordsCount.entrySet()){
            String currentWord=entry.getKey();
            String tempCurrentWord=currentWord;
            StringBuilder toRev=new StringBuilder(tempCurrentWord);
            StringBuilder revStr=toRev.reverse();
            if(!currentWord.equals(String.valueOf(revStr))){
                if(wordsCount.containsKey(String.valueOf(revStr))){
                    int countFreq=Math.min((int)wordsCount.get(currentWord), (int)wordsCount.get(String.valueOf(revStr)));
                    resultantLength+=(countFreq*4);
                    wordsCount.put(currentWord, wordsCount.get(currentWord)-countFreq);
                    wordsCount.put(String.valueOf(revStr), wordsCount.get(String.valueOf(revStr))-countFreq);
                }
            }
        }
        for(Map.Entry<String, Integer>entries: wordsCount.entrySet()){
            String currentWord=entries.getKey();
            if(currentWord.charAt(0)==currentWord.charAt(1)){
                resultantLength+=((entries.getValue())/2)*4;
                if(entries.getValue()%2!=0){
                    canHaveMiddleString=true;
                }
            }
        }
        if(canHaveMiddleString) resultantLength+=2;
        return resultantLength;
    }
}