/*
https://leetcode.com/problems/average-waiting-time/description/?envType=daily-question&envId=2024-07-09
*/

class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        double res=0;
        int curtime=customers[0][0], sz=customers.size();
        for(int i=0; i<sz; ++i){
            auto curcustT=customers[i][0], curcustSpd=customers[i][1];
            int totalTFrI=0;
            if(curcustT<=curtime){
                totalTFrI=curtime+curcustSpd;
            } else{
                totalTFrI=curcustT+curcustSpd;
            }
            res+=(totalTFrI-curcustT);
            curtime=totalTFrI;
        }
        return res/sz;
    }
};