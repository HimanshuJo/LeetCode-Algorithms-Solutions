/*
https://leetcode.com/problems/maximum-difference-between-even-and-odd-frequency-i/description/?envType=daily-question&envId=2025-06-10
*/

class Solution {
public:
    int maxDifference(string s) {
        map<char, int>mp1;
        map<int, vector<char>>mp2;
        int sz=s.length();
        for(int i=0; i<sz; ++i){
            mp1[s[i]]++;
        }
        for(auto &entries: mp1){
            mp2[entries.second].push_back(entries.first);
        }
        vector<int>odd, evn;
        for(auto &entries: mp2){
            if(entries.first%2!=0){
                odd.push_back(entries.first);
            } else evn.push_back(entries.first);
        }
        return odd[odd.size()-1]-evn[0];
    }
};