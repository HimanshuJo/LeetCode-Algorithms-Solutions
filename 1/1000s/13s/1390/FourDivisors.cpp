/*
https://leetcode.com/problems/four-divisors/description/?envType=daily-question&envId=2026-01-04
*/

class Solution {
public:

    int divsSum(int num){
        int sm=0, count=0;
        bool flag=false;
        for(int i=1; i<=num; ++i){
            if(num%i==0){
                count++;
                sm+=i;
            }
            if(count>4){
                flag=true;
                break;
            }
        }
        return flag?0:count==4?sm:0;
    }

    int sumFourDivisors(vector<int>& nums) {
        int res=0;
        for(auto &vals: nums){
            res+=divsSum(vals);
        }
        return res;
    }
};