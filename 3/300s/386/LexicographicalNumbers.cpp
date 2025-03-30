/*
https://leetcode.com/problems/lexicographical-numbers/description/?envType=daily-question&envId=2024-09-21
*/

class Solution {
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