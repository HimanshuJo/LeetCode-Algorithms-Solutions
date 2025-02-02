/*
https://leetcode.com/problems/reverse-prefix-of-word/description/?envType=daily-question&envId=2024-05-01
*/

class Solution {
    public String reversePrefix(String word, char ch) {
        StringBuilder res=new StringBuilder();
        int sz=word.length(), idxtogt=0;
        while(true){
            if(idxtogt>=sz||(word.charAt(idxtogt)==ch)) break;
            idxtogt++;
        }
        if(idxtogt>=sz) return word;
        for(int i=idxtogt; i>=0; --i){
            res.append(word.charAt(i));
        }
        if(idxtogt+1<=sz-1){
            for(int i=idxtogt+1; i<sz; ++i){
                res.append(word.charAt(i));
            }
        }
        return String.valueOf(res);
    }
}