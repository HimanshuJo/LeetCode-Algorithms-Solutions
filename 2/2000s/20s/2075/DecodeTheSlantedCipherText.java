/*
https://leetcode.com/problems/decode-the-slanted-ciphertext/?envType=daily-question&envId=2026-04-04
*/

class Solution {
    public String decodeCiphertext(String encodedText, int rows) {
        int lengthOfEncodedText=encodedText.length(), columns=lengthOfEncodedText/rows;
        StringBuilder resultantOriginalString=new StringBuilder();
        for(int startCol=0; startCol<columns; ++startCol){
            int i=0, j=startCol;
            while(i<rows&&j<columns){
                resultantOriginalString.append(encodedText.charAt(i*columns+j));
                ++i;
                ++j;
            }
        }
        while(!resultantOriginalString.isEmpty()&&resultantOriginalString.charAt(resultantOriginalString.length()-1)==' '){
            resultantOriginalString.deleteCharAt(resultantOriginalString.length()-1);
        }
        return String.valueOf(resultantOriginalString);
    }
}