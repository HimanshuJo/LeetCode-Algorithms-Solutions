/*
https://leetcode.com/problems/pyramid-transition-matrix/description/?envType=daily-question&envId=2025-12-29
*/

class Solution_TLE {
public:

    bool dfs(string bottom, unordered_set<string>&valids){
        if(bottom.size()==1) return true;
        int sz=bottom.size();
        vector<string>nextRow;
        function<void(int, string&)>build=[&](int currIdx, string &curr){
            if(currIdx==sz-1){
                nextRow.push_back(curr);
                return;
            }
            string key=bottom.substr(currIdx, 2);
            for(char ch='A'; ch<='Z'; ++ch){
                string pattern=key+ch;
                if(valids.count(pattern)){
                    curr.push_back(ch);
                    build(currIdx+1, curr);
                    curr.pop_back();
                }
            }
        };
        string temp="";
        build(0, temp);
        for(auto &vals: nextRow){
            if(dfs(vals, valids)) return true;
        }
        return false;
    }

    bool pyramidTransition(string bottom, vector<string>& allowed) {
        unordered_set<string>valids(allowed.begin(), allowed.end());
        return dfs(bottom, valids);
    }
};

// ------- ####### -------

class Solution_Opt {
public:

    map<string, bool>memo;
    unordered_map<string, vector<char>>transitions;

    bool dfs(string &bottom){
        if(bottom.size()==1) return true;
        if(memo.find(bottom)!=memo.end()) return memo[bottom];
        int sz=bottom.size();
        function<bool(int, string&)>build=[&](int currIdx, string &curr){
            if(currIdx==sz-1){
                return dfs(curr);
            }
            string key=bottom.substr(currIdx, 2);
            if(transitions.find(key)==transitions.end()) return false;
            for(char &ch: transitions[key]){
                curr.push_back(ch);
                if(build(currIdx+1, curr)) return true;
                curr.pop_back();
            }
            return false;
        };
        string temp="";
        bool curres=build(0, temp);
        return memo[bottom]=curres;
    }
    
    bool pyramidTransition(string bottom, vector<string>& allowed) {
        for(auto &vals: allowed){
            transitions[vals.substr(0, 2)].push_back(vals[2]);
        }
        return dfs(bottom);
    }
};