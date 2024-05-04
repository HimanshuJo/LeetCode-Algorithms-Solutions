/*
https://leetcode.com/problems/n-th-tribonacci-number/description/?envType=daily-question&envId=2024-04-24
*/

class Solution {
public:
    int tribonacci(int n) {
        if(n==0) return 0;
        if(n==1||n==2) return 1;
        int t0=0, t1=1, t2=1, cursm=0;
        while(n--){
            if(n==1) break;
            cursm=t0+t1+t2;
            t0=t1;
            t1=t2;
            t2=cursm;
        }
        return cursm;
    }
};