/*
https://leetcode.com/problems/check-if-a-parentheses-string-can-be-valid/description/?envType=daily-question&envId=2025-01-12
*/

class Solution {
public:
    bool canBeValid(string s, string locked) {
        int sz=s.size();
        if(sz%2!=0) return false;
        stack<int>opnbrackstk, unlckdstk;
        for(int i=0; i<sz; ++i){
            if(locked[i]=='0'){
                unlckdstk.push(i);
            } else if(s[i]=='('){
                opnbrackstk.push(i);
            } else{
                if(!opnbrackstk.empty()){
                    opnbrackstk.pop();
                } else if(!unlckdstk.empty()){
                    unlckdstk.pop();
                } else return false;
            }
        }
        while(!opnbrackstk.empty()&&!unlckdstk.empty()&&opnbrackstk.top()<unlckdstk.top()){
            opnbrackstk.pop();
            unlckdstk.pop();
        }
        if(!opnbrackstk.empty()) return false;
        return true;
    }
};