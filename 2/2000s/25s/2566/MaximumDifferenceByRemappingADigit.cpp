/*
https://leetcode.com/problems/maximum-difference-by-remapping-a-digit/description/?envType=daily-question&envId=2025-06-14
*/

class Solution {
public:
    int minMaxDifference(int num) {
        string tochk=to_string(num);
        int sz=tochk.size(), maxNum=INT_MIN, minNum=INT_MAX;
        for(int i=0; i<sz; ++i){
            string nw;
            char curr=tochk[i];
            for(int j=0; j<=9; ++j){
                nw="";
                for(int ii=0; ii<i; ++ii){
                    nw+=tochk[ii];
                }
                nw+=to_string(j);
                for(int jj=i+1; jj<sz; ++jj){
                    if(tochk[jj]!=curr){
                        nw+=tochk[jj];
                    } else{
                        nw+=to_string(j);
                    }
                }
                maxNum=max(maxNum, stoi(nw));
                minNum=min(minNum, stoi(nw));
            }
        }
        return maxNum-minNum;
    }
};