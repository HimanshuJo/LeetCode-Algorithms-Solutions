/*
https://leetcode.com/problems/crawler-log-folder/description/?envType=daily-question&envId=2024-07-10
*/

class Solution {
public:
    int minOperations(vector<string>& logs) {
        int curdepth=0, res=0;
        for(auto &vals: logs){
            int sz=vals.size();
            if(vals=="./") continue;
            else if(vals[sz-1]=='/'&&vals[sz-2]=='.'&&vals[sz-3]=='.'){
                curdepth--;
                if(curdepth<0) curdepth=0;
            }
            else curdepth++;
        }
        while(curdepth>=1){
            res++, curdepth--;
        }
        return res;
    }
};