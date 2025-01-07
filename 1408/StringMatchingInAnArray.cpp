/*
https://leetcode.com/problems/string-matching-in-an-array/description/?envType=daily-question&envId=2025-01-07
*/

class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        vector<string>res;
        int sz=words.size();
        for(int i=0; i<sz; ++i){
            string curr=words[i];
            for(int j=0; j<sz; ++j){
                if(i!=j){
                    string next=words[j];
                    if(curr.length()<=next.length()){
                        auto ifpresent=next.find(curr);
                        if(ifpresent!=string::npos){
                            res.push_back(curr);
                            break;
                        }
                    }
                }
            }
        }
        return res;
    }
};