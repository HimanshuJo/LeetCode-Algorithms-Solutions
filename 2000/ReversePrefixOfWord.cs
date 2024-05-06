/*
https://leetcode.com/problems/reverse-prefix-of-word/description/?envType=daily-question&envId=2024-05-01
*/

public class Solution {
    public string ReversePrefix(string word, char ch) {
        string res="";
        int sz=word.Length, idxtogt=0;
        while(true){
            if(idxtogt>=sz||(word[idxtogt]==ch)) break;
            idxtogt++;
        }
        if(idxtogt>=sz) return word;
        for(int i=idxtogt; i>=0; --i){
            res+=word[i];
        }
        if(idxtogt+1<=sz-1){
            for(int i=idxtogt+1; i<sz; ++i){
                res+=word[i];
            }
        }
        return res;
    }
}