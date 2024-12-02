class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        int sz=sentence.size(), idx=1;
        string curr="";
        for(int i=0; i<sz; ++i){
            if(curr==searchWord) return idx;
            if(sentence[i]==' '){
                curr="";
                idx++;
            } else{
                curr+=sentence[i];
            }
        }
        if(curr==searchWord) return idx;
        return -1;
    }
};
