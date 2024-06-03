/*
https://leetcode.com/problems/append-characters-to-string-to-make-subsequence/?envType=daily-question&envId=2024-06-03
*/

class Solution {
    public int appendCharacters(String s, String t) {
        int minCharactersNeededToMakeTSubsequenceOfS=0, 
            sizeOfS=s.length(), sizeOfT=t.length(), currentTraversalIndexInS=-1;
        for(int indexInT=0; indexInT<sizeOfT; ++indexInT){
            char currentCharacterAtIndexInT=t.charAt(indexInT);
            boolean haveFoundCurrentCharacterAtIndexInTInS=false;
            if(currentTraversalIndexInS+1<=sizeOfS-1){
                for(int indexInS=currentTraversalIndexInS+1; indexInS<sizeOfS; ++indexInS){
                    if(s.charAt(indexInS)==currentCharacterAtIndexInT){
                        haveFoundCurrentCharacterAtIndexInTInS=true;
                        currentTraversalIndexInS=indexInS;
                        break;
                    }
                }
            }
            if(!haveFoundCurrentCharacterAtIndexInTInS){
                minCharactersNeededToMakeTSubsequenceOfS+=(sizeOfT-indexInT);
                break;
            }
        }
        return minCharactersNeededToMakeTSubsequenceOfS;
    }
}