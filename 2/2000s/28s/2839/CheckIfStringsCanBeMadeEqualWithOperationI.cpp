/*
https://leetcode.com/problems/check-if-strings-can-be-made-equal-with-operations-i/description/?envType=daily-question&envId=2026-03-29
*/

class Solution {
public:
    bool canBeEqual(string s1, string s2) {
        string s1cpy=s1, s2cpy=s2;
        int sz=s1.size();
        bool flag=false;
        for(int i=0; i<sz; ++i){
            char ats2=s2[i];
            if(s1cpy[i]!=ats2){
                if(i+2>=sz){
                    flag=true;
                    break;
                }
                char tochk=s1cpy[i+2];
                if(tochk==ats2){
                    swap(s1cpy[i], s1cpy[i+2]);
                } else{
                    flag=true;
                    break;
                }
            }
        }
        if(!flag) return true;
        flag=false;
        for(int i=0; i<sz; ++i){
            char ats1=s1[i];
            if(s2cpy[i]!=ats1){
                if(i+2>=sz){
                    flag=true;
                    break;
                }
                char tochk=s2cpy[i+2];
                if(tochk==ats1){
                    swap(s2cpy[i], s2cpy[i+2]);
                } else{
                    flag=true;
                    break;
                }
            }
        }
        if(!flag) return true;
        return false;
    }
};