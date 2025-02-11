/*
https://leetcode.com/problems/remove-all-occurrences-of-a-substring/description/?envType=daily-question&envId=2025-02-11
*/

class Solution {
public:
    string removeOccurrences(string s, string part) {
        while(true){
            int sz=s.size();
            if(sz==0) break;
            auto itr=s.find(part);
            if(itr!=string::npos){
                int bgnidx=(int)itr, count=part.length();
                while(count--){
                    s[bgnidx++]='#';
                }
                s.erase(remove(s.begin(), s.end(), '#'), s.end());
            } else break;
        }
        return s;
    }
};