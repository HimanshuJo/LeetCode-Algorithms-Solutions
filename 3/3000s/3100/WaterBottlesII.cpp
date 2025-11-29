/*
https://leetcode.com/problems/water-bottles-ii/?envType=daily-question&envId=2025-10-02
*/

class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int currFullBt=numBottles, currEmptyBt=0, res=0;
        while(true){
            if(currFullBt==0&&currEmptyBt<numExchange) break;
            if(currEmptyBt>=numExchange){
                currFullBt+=1;
                currEmptyBt-=numExchange;
                numExchange+=1;
            } else{
                currEmptyBt+=currFullBt;
                res+=currFullBt;
                currFullBt=0;
            }
        }
        return res;
    }
};