/*
https://leetcode.com/problems/water-bottles/description/?envType=daily-question&envId=2024-07-07
*/

class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int res=0, nwres=0, curempty=0;
        res+=numBottles, curempty+=numBottles;
        while(true){
            if(curempty<numExchange) break;
            int nwempty=0;
            while(curempty>=numExchange){
                nwres++;
                curempty-=numExchange;
            }
            nwempty+=curempty;
            nwempty+=nwres;
            res+=nwres;
            nwres=0;
            curempty=nwempty;
        }
        return res;
    }
};