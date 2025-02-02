/*
https://leetcode.com/problems/2-keys-keyboard/description/?envType=daily-question&envId=2024-08-19
*/

class Solution {
public:

    long long dfs(int n, string curr, string oldpst, map<pair<string, string>, int>&memo){
        if(curr.size()>n) return INT_MAX;
        if(curr.size()==n) return 0;
        if(memo.find({curr, oldpst})!=memo.end()) return memo[{curr, oldpst}];
        long long res=INT_MAX;
        string pst=curr+curr;
        long long old=1+dfs(n, curr+oldpst, oldpst, memo);
        long long nwpst=2+dfs(n, pst, curr, memo);
        res=min(res, min(old, nwpst));
        return memo[{curr, oldpst}]=res;
    }

    int minSteps(int n) {
        if(n==1) return 0;
        string curr="A", oldpst="A";
        map<pair<string, string>, int>memo;
        return dfs(n, curr, oldpst, memo)+1;
    }
};