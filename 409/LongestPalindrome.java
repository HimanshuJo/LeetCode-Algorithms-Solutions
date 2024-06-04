/*
https://leetcode.com/problems/longest-palindrome/description/?envType=daily-question&envId=2024-06-04
*/

class Solution {
    public int longestPalindrome(String s) {
        HashMap<Character, Integer>dictionaryToCountOccurrencesOfEachCharacterInS=new HashMap<>();
        int lengthOfS=s.length();
        for(int index=0; index<lengthOfS; ++index){
            char currentCharacterAtIndexInS=s.charAt(index);
            if(dictionaryToCountOccurrencesOfEachCharacterInS.containsKey(currentCharacterAtIndexInS)){
                int currentCountOfCurrentCharacterAtIndexInSIn_DictionaryToCountOccurrencesOfEachCharacterInS=dictionaryToCountOccurrencesOfEachCharacterInS.get(currentCharacterAtIndexInS);
                currentCountOfCurrentCharacterAtIndexInSIn_DictionaryToCountOccurrencesOfEachCharacterInS++;
                dictionaryToCountOccurrencesOfEachCharacterInS.put(currentCharacterAtIndexInS, currentCountOfCurrentCharacterAtIndexInSIn_DictionaryToCountOccurrencesOfEachCharacterInS);
            } else{
                dictionaryToCountOccurrencesOfEachCharacterInS.put(currentCharacterAtIndexInS, 1);
            }
        }
        int lengthOfTheLongestPalindrome=0;
        ArrayList<Character>listOfAllCharactersWithOddOccurrencesInS=new ArrayList<>();
        for(Map.Entry<Character, Integer>entriesIn_DictionaryToCountOccurrencesOfEachCharacterInS: dictionaryToCountOccurrencesOfEachCharacterInS.entrySet()){
            if((int)entriesIn_DictionaryToCountOccurrencesOfEachCharacterInS.getValue()%2==0){
                lengthOfTheLongestPalindrome+=(int)entriesIn_DictionaryToCountOccurrencesOfEachCharacterInS.getValue();
            } else{
                if((int)entriesIn_DictionaryToCountOccurrencesOfEachCharacterInS.getValue()-1>=1){
                    lengthOfTheLongestPalindrome+=entriesIn_DictionaryToCountOccurrencesOfEachCharacterInS.getValue()-1;
                }
                listOfAllCharactersWithOddOccurrencesInS.add((char)entriesIn_DictionaryToCountOccurrencesOfEachCharacterInS.getKey());
            }
        }
        if(listOfAllCharactersWithOddOccurrencesInS.size()>=1){
            lengthOfTheLongestPalindrome++;
        }
        return lengthOfTheLongestPalindrome;
    }
}