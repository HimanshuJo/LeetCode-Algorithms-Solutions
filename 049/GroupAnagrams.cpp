/*
https://leetcode.com/problems/group-anagrams/description/?envType=daily-question&envId=2024-02-06
*/

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int sz=strs.size();
        unordered_map<string, vector<int>>mp;
        for(int i=0; i<sz; ++i){
            string tmp=strs[i];
            sort(tmp.begin(), tmp.end());
            mp[tmp].push_back(i);
        }
        vector<vector<string>>res;
        for(auto &entries: mp){
            vector<string>curres;
            vector<int>curmpvec=entries.second;
            int curentrysz=curmpvec.size();
            for(int i=0; i<curentrysz; ++i){
                curres.push_back(strs[curmpvec[i]]);
            }
            res.push_back(curres);
        }
        return res;
    }
};