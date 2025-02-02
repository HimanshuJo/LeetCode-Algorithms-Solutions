/*
https://leetcode.com/problems/longest-palindrome/description/?envType=daily-question&envId=2024-06-04
*/

class Solution {
public:
    int longestPalindrome(string s) {
        map<char, int>mp;
        for(auto &ch: s){
            mp[ch]++;
        }
        int res=0;
        bool haveOdd=false;
        vector<char>odds;
        for(auto &entries: mp){
            if(entries.second%2==0){
                res+=entries.second;
            } else{
                if(entries.second-1>=1){
                    res+=entries.second-1;
                }
                odds.push_back(entries.first);
            }
        }
        if(odds.size()>=1) res++;
        return res;
    }
};