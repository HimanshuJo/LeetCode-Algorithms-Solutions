/*
https://leetcode.com/problems/find-the-lexicographically-largest-string-from-the-box-i/description/?envType=daily-question&envId=2025-06-04
*/

class Solution_BF {
public:

    void dfs(string word, int numFriends, vector<string>&allSubs, string &maxStr, int curIdx){
        if(numFriends==0){
            if(curIdx>=word.size()){
                for(auto &strs: allSubs){
                    maxStr=max(maxStr, strs);
                }
            }
            return;
        }
        for(int i=curIdx+1; i<word.size()-numFriends+2; ++i){
            string currPart="";
            for(int j=curIdx; j<i; ++j){
                currPart+=word[j];
            }
            allSubs.push_back(currPart);
            dfs(word, numFriends-1, allSubs, maxStr, i);
            allSubs.pop_back();
        }
        return;
    }

    string answerString(string word, int numFriends) {
        vector<string>allSubs;
        string maxStr="";
        dfs(word, numFriends, allSubs, maxStr, 0);
        return maxStr;
    }
};

// ------- ******* -------

class Solution {
public:
    string answerString(string word, int numFriends) {
        int sz=word.size();
        if(numFriends==1){
            return word;
        }
        string res="";
        for(int i=0; i<sz; ++i){
            res=max(res, word.substr(i, min(sz-numFriends+1, sz-i)));
        }
        return res;
    }
};