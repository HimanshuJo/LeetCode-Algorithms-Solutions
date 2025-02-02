/*
https://leetcode.com/problems/replace-words/description/?envType=daily-question&envId=2024-06-07
*/

class Pair{

    private boolean booleanValue;
    private String stringValue;

    Pair(){}

    Pair(boolean booleanValue, String stringValue){
        this.booleanValue=booleanValue;
        this.stringValue=stringValue;
    }

    public boolean getBooleanValue(){
        return this.booleanValue;
    }

    public String getStringValue(){
        return this.stringValue;
    }
}

class Solution {

    public static Pair searchForWordInDictionary(List<String>dictionary, StringBuilder stringNeededToBeSearched){
        int dictionarySize=dictionary.size();
        for(int dictionaryIndex=0; dictionaryIndex<dictionarySize; ++dictionaryIndex){
            if(dictionary.get(dictionaryIndex).equals(String.valueOf(stringNeededToBeSearched)))
                return new Pair(true, String.valueOf(stringNeededToBeSearched));
        }
        return new Pair(false, "Not Found");
    }

    public static ArrayList<String> splitStringAtSpaces(String sentence){
        int sentenceLength=sentence.length(), initialIndex=0;
        StringBuilder currentStringChunckInSentenceWithoutSpace=new StringBuilder();
        ArrayList<String>resultantSplittedStringAtSpaces=new ArrayList<>();
        while(initialIndex<=sentenceLength-1){
            currentStringChunckInSentenceWithoutSpace.append(sentence.charAt(initialIndex));
            initialIndex++;
            if(initialIndex>=sentenceLength) break;
            if(sentence.charAt(initialIndex)==' '){
                resultantSplittedStringAtSpaces.add(String.valueOf(currentStringChunckInSentenceWithoutSpace));
                currentStringChunckInSentenceWithoutSpace=new StringBuilder("");
                initialIndex++;
            }
        }
        if(currentStringChunckInSentenceWithoutSpace.length()>=1){
            resultantSplittedStringAtSpaces.add(String.valueOf(currentStringChunckInSentenceWithoutSpace));
        }
        return resultantSplittedStringAtSpaces;
    }

    public String replaceWords(List<String> dictionary, String sentence) {
        ArrayList<String>splittedStringAtSpaces=splitStringAtSpaces(sentence);
        StringBuilder resultantStringAfterReplacement=new StringBuilder("");
        int splittedStringAtSpacesSize=splittedStringAtSpaces.size();
        for(int splittedStringAtSpacesIndex=0; splittedStringAtSpacesIndex<splittedStringAtSpacesSize; ++splittedStringAtSpacesIndex){
            String currentSplittedStringAtSpace=splittedStringAtSpaces.get(splittedStringAtSpacesIndex);
            int currentSplittedStringAtSpaceLength=currentSplittedStringAtSpace.length(),
                initialTraversalIndex=0;
            StringBuilder currentStringChunk=new StringBuilder();
            boolean isCurrentStringChunkAvailableInDictionary=false;
            while(true){
                if(initialTraversalIndex>=currentSplittedStringAtSpaceLength) break;
                currentStringChunk.append(currentSplittedStringAtSpace.charAt(initialTraversalIndex));
                Pair checkCurrentStringChunkAvailableInDictionary=searchForWordInDictionary(dictionary, currentStringChunk);
                if(checkCurrentStringChunkAvailableInDictionary.getBooleanValue()){
                    isCurrentStringChunkAvailableInDictionary=true;
                    String foundedDictionaryWord=checkCurrentStringChunkAvailableInDictionary.getStringValue();
                    resultantStringAfterReplacement.append(foundedDictionaryWord);
                    resultantStringAfterReplacement.append(" ");
                    break;
                }
                initialTraversalIndex++;
            }
            if(!isCurrentStringChunkAvailableInDictionary){
                resultantStringAfterReplacement.append(currentSplittedStringAtSpace);
                resultantStringAfterReplacement.append(" ");
            }
        }
        if(resultantStringAfterReplacement.length()>=1)
            resultantStringAfterReplacement.deleteCharAt(resultantStringAfterReplacement.length()-1);
        return String.valueOf(resultantStringAfterReplacement);
    }
}