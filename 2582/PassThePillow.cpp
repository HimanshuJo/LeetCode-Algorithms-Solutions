/*
https://leetcode.com/problems/pass-the-pillow/description/?envType=daily-question&envId=2024-07-06
*/

class Solution {
public:
    int passThePillow(int n, int time) {
        if(time<n) return time+1;
        vector<int>all;
        int bgn=1, end=n, tempT=time;;
        bool flag=false;
        while(true){
            if(time<0) break;
            if(bgn==end){
                flag=true;
            } else if(bgn==1){
                flag=false;
            }
            all.push_back(bgn);
            if(flag){
                bgn--;
            } else{
                bgn++;
            }
            time--;
        }
        return all[tempT];
    }
};