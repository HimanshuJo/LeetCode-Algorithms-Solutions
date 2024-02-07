/*
https://leetcode.com/problems/sort-characters-by-frequency/description/?envType=daily-question&envId=2024-02-07
*/

class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int>mp1;
        int sz=s.size();
        for(int i=0; i<sz; ++i){
            mp1[s[i]]++;
        }
        map<int, vector<char>, greater<>>mp2;
        for(auto &entries: mp1){
            mp2[entries.second].push_back(entries.first);
        }
        string res="";
        for(auto &entries: mp2){
            int count=entries.first;
            for(auto &vals: entries.second){
                for(int i=0; i<count; ++i){
                    res+=vals;
                }
            }
        }
        return res;
    }
};