/*
https://leetcode.com/problems/delete-characters-to-make-fancy-string/description/?envType=daily-question&envId=2024-11-01
*/

class Solution {
public:
    string makeFancyString(string s) {
        int sz=s.size(), idx=0;
        while(true){
            if(idx>=sz) break;
            char curr=s[idx];
            int previdx=idx, progrs=idx, curcount=0;
            bool flag=false;
            while(true){
                if(s[progrs]!=curr||progrs>=sz) break;
                else{
                    curcount++;
                    progrs++;
                }
                if(curcount==3){
                    flag=true;
                    break;
                }
            }
            if(flag){
                s[previdx]='#';
                sz=s.size();
            } else idx++;
        }
        s.erase(remove(s.begin(), s.end(), '#'), s.end());
        return s;
    }
};