/*
https://leetcode.com/problems/lexicographical-numbers/description/?envType=daily-question&envId=2024-09-21
*/

class Solution_BF {
public:
    vector<int> lexicalOrder(int n) {
        vector<string>all;
        for(int i=1; i<=n; ++i){
            all.push_back(to_string(i));
        }
        sort(all.begin(), all.end());
        vector<int>res;
        for(auto &vals: all){
            res.push_back(stoi(vals));
        }
        return res;
    }
};

// ------- ******* -------

class Solution_OptSpace {
public:

    void dfs(int limit, int num, vector<int>&res){
        if(num>limit) return;
        res.push_back(num);
        for(int i=0; i<=9; ++i){
            int nxtNum=num*10+i;
            if(nxtNum>limit) break;
            dfs(limit, nxtNum, res);
        }
        return;
    }

    vector<int> lexicalOrder(int n) {
        vector<int>res;
        for(int i=1; i<=n; ++i){
            if(find(res.begin(), res.end(), i)==res.end())
                dfs(n, i, res);
        }
        return res;
    }
};

// ------- ******* -------

class Solution_Opt {
public:

    void dfs(int limit, int num, vector<int>&res){
        if(num>limit) return;
        res.push_back(num);
        for(int i=0; i<=9; ++i){
            int nxtNum=num*10+i;
            if(nxtNum>limit) break;
            dfs(limit, nxtNum, res);
        }
        return;
    }

    vector<int> lexicalOrder(int n) {
        vector<int>res;
        for(int i=1; i<=9; ++i){
            dfs(n, i, res);
        }
        return res;
    }
};