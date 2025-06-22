/*
https://leetcode.com/problems/divide-a-string-into-groups-of-size-k/description/?envType=daily-question&envId=2025-06-22
*/

class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string>res;
        int sz=s.size(), idx=0;
        string curr="";
        while(true){
            if(idx>=sz) break;
            if(curr.size()==k){
                res.push_back(curr);
                curr="";
            } else{
                curr+=s[idx++];
            }
        }
        while(true){
            if(curr.size()==0||curr.size()==k) break;
            curr+=fill;
        }
        if(curr.size()>=1) res.push_back(curr);
        return res;
    }
};