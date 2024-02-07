/*
	https://leetcode.com/problems/evaluate-reverse-polish-notation/description/?envType=daily-question&envId=2024-01-30
*/

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int res=0;
        stack<int>stk;
        unordered_map<string, string>mp;
        mp["+"]="+", mp["-"]="-", mp["*"]="*", mp["/"]="/";
        for(auto &vals: tokens){
            if(mp.find(vals)==mp.end()){
                stk.push(stoi(vals));
            } else{
                int curtp=stk.top();
                stk.pop();
                int nxt=stk.top();
                stk.pop();
                if(vals=="+"){
                    stk.push(curtp+nxt);
                } else if(vals=="-"){
                    stk.push(nxt-curtp);
                } else if(vals=="*"){
                    stk.push(nxt*curtp);
                } else{
                    stk.push(nxt/curtp);
                }
            }
        }
        return stk.top();
    }
};