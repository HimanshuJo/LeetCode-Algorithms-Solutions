/*
https://leetcode.com/problems/minimum-string-length-after-removing-substrings/description/?envType=daily-question&envId=2024-10-07
*/

class Solution {
public:
    int minLength(string s) {
        bool flag=false;
        while(true){
            flag=false;
            auto itr=s.find("AB");
            if(itr!=string::npos){
                flag=true;
                s.erase(itr, 2);
            }
            auto itr2=s.find("CD");
            if(itr2!=string::npos){
                if(!flag) flag=true;
                s.erase(itr2, 2);
            }
            if(!flag) break;
        }
        return s.size();
    }
};