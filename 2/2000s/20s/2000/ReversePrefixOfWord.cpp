/*
https://leetcode.com/problems/reverse-prefix-of-word/description/?envType=daily-question&envId=2024-05-01
*/

class Solution {
public:
    string reversePrefix(string word, char ch) {
        string res="";
        int sz=word.size(), idxtogt=0;
        while(true){
            if((word[idxtogt]==ch)||(idxtogt>=sz)) break;
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
};