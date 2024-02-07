/*
https://leetcode.com/problems/first-unique-character-in-a-string/description/?envType=daily-question&envId=2024-02-05
*/

class Solution {
public:

    bool customFind(string &s, char &ch, int idx){
        int sz=s.size();
        if(idx>=sz) return false;
        for(int i=0; i<sz; ++i){
            if(i!=idx&&s[i]==ch) return true;
        }
        return false;
    }

    int firstUniqChar(string s) {
        int sz=s.size();
        for(int i=0; i<sz; ++i){
            bool flag=customFind(s, s[i], i);
            if(!flag){
                return i;
            }
        }
        return -1;
    }
};