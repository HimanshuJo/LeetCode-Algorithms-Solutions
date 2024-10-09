/*
https://leetcode.com/problems/minimum-add-to-make-parentheses-valid/?envType=daily-question&envId=2024-10-09
*/

class Solution {
public:
    int minAddToMakeValid(string s) {
        int sz=s.size(), res=0;
        stack<char>stk;
        for(auto &ch: s){
            if(ch=='('){
                stk.push('(');
            } else{
                if(stk.empty()){
                    res++;
                } else{
                    stk.pop();
                }
            }
        }
        if(!stk.empty()) res+=stk.size();
        return res;
    }
};