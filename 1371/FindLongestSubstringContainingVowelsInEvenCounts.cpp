/*
https://leetcode.com/problems/find-the-longest-substring-containing-vowels-in-even-counts/description/?envType=daily-question&envId=2024-09-15
*/

class Solution {
public:
    int findTheLongestSubstring(string s) {
        int prefixXOR=0;
        unordered_map<int, int>mp1;
        mp1['a'-'a']=1, mp1['e'-'a']=2, mp1['i'-'a']=4, mp1['o'-'a']=8, mp1['u'-'a']=16;
        vector<int>mp2(32, -1);
        int longestSubstring=0;
        for(int i=0; i<s.size(); ++i){
            prefixXOR^=mp1[s[i]-'a'];
            if(mp2[prefixXOR]==-1&&prefixXOR!=0){
                mp2[prefixXOR]=i;
            }
            longestSubstring=max(longestSubstring, i-mp2[prefixXOR]);
        }
        return longestSubstring;
    }
};