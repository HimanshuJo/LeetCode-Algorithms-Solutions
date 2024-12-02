class Solution {
    public int isPrefixOfWord(String sentence, String searchWord) {
        int lengthOfSentence=sentence.length(), currentIndex=1;
        StringBuilder currentString=new StringBuilder();
        for(int i=0; i<lengthOfSentence; ++i){
            if(String.valueOf(currentString).equals(searchWord)) return currentIndex;
            char currentChar=sentence.charAt(i);
            if(currentChar==' '){
                currentString=new StringBuilder();
                currentIndex++;
            } else{
                currentString.append(currentChar);
            }
        }
        if(String.valueOf(currentString).equals(searchWord)) return currentIndex;
        return -1;
    }
}
