/*
https://leetcode.com/problems/count-vowel-strings-in-ranges/description/?envType=daily-question&envId=2025-01-02
*/

class Solution {
public:

    unordered_map<char, char>vowelsmp;

    bool isVowel(char currentChar){
        if(vowelsmp.find(currentChar)!=vowelsmp.end()) return true;
        return false;
    }

    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        vowelsmp['a']='a', vowelsmp['e']='e', vowelsmp['i']='i', vowelsmp['o']='o', vowelsmp['u']='u';
        int lengthOfWords=words.size();
        vector<int>prefixArr;
        for(int i=0; i<lengthOfWords; ++i){
            string curr=words[i];
            if(isVowel(curr[0])&&isVowel(curr[curr.length()-1])){
                if(prefixArr.size()==0) prefixArr.push_back(1);
                else prefixArr.push_back(prefixArr.back()+1);
            } else{
                if(prefixArr.size()==0) prefixArr.push_back(0);
                else prefixArr.push_back(prefixArr.back());
            }
        }
        vector<int>res;
        for(auto &vecentries: queries){
            int bgn=vecentries[0], end=vecentries[1];
            int ttl=prefixArr[end], req=(bgn==0?ttl:ttl-prefixArr[bgn-1]);
            res.push_back(req);
        }
        return res;
    }
};