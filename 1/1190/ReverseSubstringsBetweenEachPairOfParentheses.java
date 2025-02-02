/*
https://leetcode.com/problems/reverse-substrings-between-each-pair-of-parentheses/description/?envType=daily-question&envId=2024-07-11
*/

class Solution {
    public String reverseParentheses(String s) {
        StringBuilder temporaryS=new StringBuilder(s);
        while(true){
            int beginIndexForFirstClosingBracket=0, indexForLastOpenBracket=0;
            StringBuilder resultantReversedInnermostString=new StringBuilder();
            boolean isAnyClosingBracketAvailable=false;
            while(true){
                if(beginIndexForFirstClosingBracket>=temporaryS.length()) break;
                if(temporaryS.charAt(beginIndexForFirstClosingBracket)==')'){
                    isAnyClosingBracketAvailable=true;
                    temporaryS.setCharAt(beginIndexForFirstClosingBracket, '#');
                    beginIndexForFirstClosingBracket--;
                    indexForLastOpenBracket=beginIndexForFirstClosingBracket;
                    boolean isAnyOpeningBracketAvailable=true;
                    while(true){
                        if(temporaryS.charAt(indexForLastOpenBracket)=='(') break;
                        indexForLastOpenBracket--;
                        if(indexForLastOpenBracket<0){
                            isAnyOpeningBracketAvailable=false;
                            break;
                        }
                    }
                    if(isAnyOpeningBracketAvailable){
                        temporaryS.setCharAt(indexForLastOpenBracket, '#');
                        indexForLastOpenBracket++;
                        for(int i=beginIndexForFirstClosingBracket; i>=indexForLastOpenBracket; --i){
                            resultantReversedInnermostString.append(temporaryS.charAt(i));
                        }
                        int beginIdxForReversedString=0;
                        for(int i=indexForLastOpenBracket; i<=beginIndexForFirstClosingBracket; ++i){
                            temporaryS.setCharAt(i, resultantReversedInnermostString.charAt(beginIdxForReversedString++));
                        }
                        break;
                    } else break;
                }
                beginIndexForFirstClosingBracket++;
            }
            if(!isAnyClosingBracketAvailable) break;
            for(int i=0; i<temporaryS.length(); ++i){
                if(temporaryS.charAt(i)=='#'){
                    temporaryS.deleteCharAt(i);
                    --i;
                }
            }
        }
        return String.valueOf(temporaryS);
    }
}