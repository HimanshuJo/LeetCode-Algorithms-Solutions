/*
https://leetcode.com/problems/maximum-score-after-splitting-a-string/description/?envType=daily-question&envId=2025-01-01
*/

class Solution {
public:

    int countZeros(string &str){
        int sz=str.size(), count=0;
        for(int i=0; i<sz; ++i){
            if(str[i]=='0') count++;
        }
        return count;
    }

    int countOnes(string &str){
        int sz=str.size(), count=0;
        for(int i=0; i<sz; ++i){
            if(str[i]=='1') count++;
        }
        return count;
    }

    int maxScore(string s) {
        int sz=s.size(), res=INT_MIN;
        for(int i=0; i<sz; ++i){
            string curr="";
            for(int j=i; j<sz; ++j){
                curr+=s[j];
                if(j+1<=sz-1){
                    string next="";
                    for(int k=j+1; k<sz; ++k){
                        next+=s[k];
                    }
                    int countlft=countZeros(curr), countrght=countOnes(next);
                    res=max(res, countlft+countrght);
                }
            }
        }
        return res;
    }
};