/*
https://leetcode.com/problems/longest-palindrome-by-concatenating-two-letter-words/description/?envType=daily-question&envId=2025-05-25
*/

class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string, int>mp;
        for(auto &vals: words){
            mp[vals]++;
        }
        bool hasMiddle=false;
        int res=0;
        for(auto &entries: mp){
            string curword=entries.first;
            string tmpword=curword;
            reverse(tmpword.begin(), tmpword.end());
            if(curword!=tmpword){
                if(mp.find(tmpword)!=mp.end()){
                    int countfreq=min(mp[curword], mp[tmpword]);
                    res+=(countfreq*4);
                    mp[curword]-=countfreq;
                    mp[tmpword]-=countfreq;
                }
            }
        }
        for(auto &entries: mp){
            string curword=entries.first;
            if(curword[0]==curword[1]){
                res+=((entries.second)/2)*4;
                if(entries.second%2!=0){
                    hasMiddle=true;
                }
            }
        }
        if(hasMiddle) res+=2;
        return res;
    }
};