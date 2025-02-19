/*
https://leetcode.com/problems/the-k-th-lexicographical-string-of-all-happy-strings-of-length-n/description/?envType=daily-question&envId=2025-02-19
*/

class Solution {
public:

    void dfs(int n, vector<string>&all, string curr){
        if(curr.size()==n){
            all.push_back(curr);
            return;
        }
        for(char ch='a'; ch<='c'; ++ch){
            if(curr.size()>0&&curr.back()==ch) continue;
            dfs(n, all, curr+ch);
        }
    }

    vector<string> genAllPermus(int n){
        vector<string>all;
        string curr="";
        dfs(n, all, curr);
        return all;
    }

    string getHappyString(int n, int k) {
        vector<string>all=genAllPermus(n);
        if(all.size()<k) return "";
        sort(all.begin(), all.end());
        return all[k-1];
    }
};