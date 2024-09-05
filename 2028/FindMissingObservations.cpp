/*
https://leetcode.com/problems/find-missing-observations/description/?envType=daily-question&envId=2024-09-05
*/

class Solution {
public:

    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int x=rolls.size(), cursum=0;
        for(auto &vals: rolls){
            cursum+=vals;
        }
        int tofnd=(mean*(x+n))-(cursum);
        if(tofnd>6*n||tofnd<n) return {};
        int distMean=tofnd/n, mod=tofnd%n;
        vector<int>temp(n, distMean);
        for(int i=0; i<mod; ++i){
            temp[i]++;
        }
        return temp;
    }
};