/*
https://leetcode.com/problems/find-the-pivot-integer/description/?envType=daily-question&envId=2024-03-13
*/

class Solution {
public:

    bool isValid(int num, int maxLim){
        int ttlsm=(maxLim*(maxLim+1))/2, lftsm=(num*(num+1))/2, rghtsm=(ttlsm-lftsm)+num;
        return lftsm==rghtsm;
    }

    int pivotInteger(int n) {
        for(int i=1; i<=n; ++i){
            if(isValid(i, n)) return i;
        }
        return -1;
    }
};