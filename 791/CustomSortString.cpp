/*
https://leetcode.com/problems/custom-sort-string/description/?envType=daily-question&envId=2024-03-11
*/

class Solution {
public:
    string customSortString(string order, string s) {
        int szs=s.size();
        set<int>seenidxs;
        string res="";
        for(auto &ordrch: order){
            for(int i=0; i<szs; ++i){
                if(seenidxs.find(i)==seenidxs.end()){
                    if(s[i]==ordrch){
                        res+=ordrch;
                        seenidxs.insert(i);
                    }
                }
            }
        }
        for(int i=0; i<szs; ++i){
            if(seenidxs.find(i)==seenidxs.end()){
                res+=s[i];
            }
        }
        return res;
    }
};