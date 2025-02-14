/*
https://leetcode.com/problems/minimum-number-of-changes-to-make-binary-string-beautiful/description/?envType=daily-question&envId=2024-11-05
*/

class Solution {
public:
    int minChanges(string s) {
        int sz=s.size(), idx=0, count=0;
        while(true){
            if(idx>=sz) break;
            string currstr="";
            while(true){
                if((currstr.size()>0&&currstr.size()%2==0)||idx>=sz) break;
                if(currstr.size()==0){
                    currstr+=s[idx];
                    idx++;
                } else{
                    if(s[idx]!=currstr[0]){
                        count++;
                        currstr+=currstr[0];
                        idx++;
                    } else{
                        currstr+=currstr[0];
                        idx++;
                    }
                }
            }
        }
        return count;
    }
};