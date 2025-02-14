/*
https://leetcode.com/problems/number-of-senior-citizens/description/?envType=daily-question&envId=2024-08-01
*/

class Solution {
public:
    int countSeniors(vector<string>& details) {
        int res=0;
        for(auto &vals: details){
            if(vals[11]-'0'>=6){
                if(vals[12]-'0'==0){
                    if(vals[11]-'0'!=6) res++;
                } else res++;
            }
        }
        return res;
    }
};