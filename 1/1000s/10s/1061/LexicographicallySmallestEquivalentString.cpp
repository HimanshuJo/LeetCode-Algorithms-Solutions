/*
https://leetcode.com/problems/lexicographically-smallest-equivalent-string/description/?envType=daily-question&envId=2025-06-05
*/

class Solution {
public:

    void bfs(auto &mp, char first, set<char>&sec){
        queue<char>q;
        set<char>qseen;
        for(auto &stvals: sec){
            q.push(stvals);
        }
        while(!q.empty()){
            int qsz=q.size();
            while(qsz--){
                auto curr=q.front();
                q.pop();
                mp[first].insert(curr);
                if(mp.find(curr)!=mp.end()){
                    if(qseen.find(curr)==qseen.end()){
                        qseen.insert(curr);
                        auto nwst=mp[curr];
                        for(auto &nwstvals: nwst){
                            q.push(nwstvals);
                        }
                    }
                }
            }
        }
    }

    string smallestEquivalentString(string s1, string s2, string baseStr) {
        map<char, set<char>>mp;
        int sz=s1.length();
        for(int i=0; i<sz; ++i){
            char atS1=s1[i], atS2=s2[i];
            mp[atS1].insert(atS1);
            mp[atS1].insert(atS2);
            mp[atS2].insert(atS2);
            mp[atS2].insert(atS1);
            auto s1St=mp[atS1];
            for(auto &vals: s1St){
                mp[atS2].insert(vals);
            }
            auto s2St=mp[atS2];
            for(auto &vals: s2St){
                mp[atS1].insert(vals);
            }
        }
        for(auto &entries: mp){
            bfs(mp, entries.first, entries.second);
        }
        int sz2=baseStr.length();
        string res="";
        for(int i=0; i<sz2; ++i){
            char curr=baseStr[i];
            if(mp.find(curr)!=mp.end()){
                auto curst=mp[curr];
                auto itr=curst.begin();
                res+=*itr;
            } else res+=curr;
        }
        return res;
    }
};