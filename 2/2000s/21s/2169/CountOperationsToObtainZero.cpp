/*
https://leetcode.com/problems/count-operations-to-obtain-zero/?envType=daily-question&envId=2025-11-09
*/

class Solution {
public:
    int countOperations(int num1, int num2) {
        int res=0;
        while(true){
            if(num1==0||num2==0) break;
            if(num1>=num2){
                num1-=num2;
            } else num2-=num1;
            res++;
        }
        return res;
    }
};