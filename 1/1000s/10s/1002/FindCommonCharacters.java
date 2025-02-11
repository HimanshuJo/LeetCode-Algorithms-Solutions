/*
https://leetcode.com/problems/find-common-characters/description/?envType=daily-question&envId=2024-06-05
*/

class Pair{
    
    private boolean booleanValueForCurrentCharacterInString;
    private int indexForCurrentCharacterInString;

    Pair(){};

    Pair(boolean booleanValueForCurrentCharacterInString, int indexForCurrentCharacterInString){
        this.booleanValueForCurrentCharacterInString=booleanValueForCurrentCharacterInString;
        this.indexForCurrentCharacterInString=indexForCurrentCharacterInString;
    }

    public boolean getBooleanValueForCurrentCharacterInString(){
        return this.booleanValueForCurrentCharacterInString;
    }

    public int getIndexForCurrentCharacterInString(){
        return this.indexForCurrentCharacterInString;
    }
}

class Solution {

    public static Pair searchForCharacterInString(StringBuilder currentWordAt_index_words, char currentCharacterIn_stringAtZerothIndexInWords){
        int lengthOf_currentWordAt_index_words=currentWordAt_index_words.length();
        for(int currentWordAt_index_words_index=0; currentWordAt_index_words_index<lengthOf_currentWordAt_index_words; ++currentWordAt_index_words_index){
            if(currentWordAt_index_words.charAt(currentWordAt_index_words_index)==currentCharacterIn_stringAtZerothIndexInWords){
                return new Pair(true, currentWordAt_index_words_index);
            }
        }
        return new Pair(false, -1);
    }

    public List<String> commonChars(String[] words) {
        List<StringBuilder>words_AsStringBuilder=new ArrayList<>();
        int lengthOf_words=words.length;
        for(int words_index=0; words_index<lengthOf_words; ++words_index){
            StringBuilder currentWordAsStringBuilder=new StringBuilder(words[words_index]);
            words_AsStringBuilder.add(currentWordAsStringBuilder);
        }
        List<String>result_ArrayAllCharactersInAllStringsInWordsArrayIncludingDuplicates=new ArrayList<>();
        String stringAtZerothIndexInWords=String.valueOf(words_AsStringBuilder.get(0));
        int lengthOf_stringAtZerothIndexInWords=stringAtZerothIndexInWords.length();
        for(int stringAtZerothIndexInWords_index=0; stringAtZerothIndexInWords_index<lengthOf_stringAtZerothIndexInWords; ++stringAtZerothIndexInWords_index){
            boolean isCurrentCharacterAvailableInRestOfString=true;
            char currentCharacterIn_stringAtZerothIndexInWords=stringAtZerothIndexInWords.charAt(stringAtZerothIndexInWords_index);
            List<Integer>listStoringIndexesForRestOfStringsWhereCurrentCharacterIsFound=new ArrayList<>();
            for(int words_index=1; words_index<lengthOf_words; ++words_index){
                StringBuilder currentWordAt_words_index=words_AsStringBuilder.get(words_index);
                Pair isCurrentCharacterAvailable=searchForCharacterInString(currentWordAt_words_index, currentCharacterIn_stringAtZerothIndexInWords);
                if(isCurrentCharacterAvailable.getBooleanValueForCurrentCharacterInString()){
                    listStoringIndexesForRestOfStringsWhereCurrentCharacterIsFound.add(isCurrentCharacterAvailable.getIndexForCurrentCharacterInString());
                } else{
                    isCurrentCharacterAvailableInRestOfString=false;
                    break;
                }
            }
            if(isCurrentCharacterAvailableInRestOfString){
                StringBuilder currentCharacterIn_stringAtZerothIndexInWords_AsString=new StringBuilder();
                currentCharacterIn_stringAtZerothIndexInWords_AsString.append(currentCharacterIn_stringAtZerothIndexInWords);
                result_ArrayAllCharactersInAllStringsInWordsArrayIncludingDuplicates.add(String.valueOf(currentCharacterIn_stringAtZerothIndexInWords_AsString));
                for(int words_index=1; words_index<lengthOf_words; ++words_index){
                    words_AsStringBuilder.get(words_index).setCharAt(listStoringIndexesForRestOfStringsWhereCurrentCharacterIsFound.get(words_index-1), '#');
                }
            }
        }
        return result_ArrayAllCharactersInAllStringsInWordsArrayIncludingDuplicates;
    }
}