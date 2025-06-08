/*
https://leetcode.com/problems/lexicographically-minimum-string-after-removing-stars/description/?envType=daily-question&envId=2025-06-07
*/

class Solution {
public:
    string clearStars(string s) {
        int sz=s.size();
        vector<stack<int>>vec(26);
        for(int i=0; i<sz; ++i){
            if(s[i]!='*'){
                vec[s[i]-'a'].push(i);
            } else{
                for(int j=0; j<26; ++j){
                    if(!vec[j].empty()){
                        int curIdx=vec[j].top();
                        vec[j].pop();
                        s[curIdx]='*';
                        break;
                    }
                }
            }
        }
        string res="";
        for(int i=0; i<sz; ++i){
            if(s[i]!='*'){
                res+=s[i];
            }
        }
        return res;
    }
};