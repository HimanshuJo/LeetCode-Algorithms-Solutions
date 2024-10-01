/*
https://leetcode.com/problems/check-if-array-pairs-are-divisible-by-k/description/?envType=daily-question&envId=2024-10-01
*/

class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        vector<int>remainderCount(k, 0);
        for(auto &vals: arr){
            int currRemainder=vals%k;
            if(currRemainder<0) currRemainder+=k;
            remainderCount[currRemainder]++;
        }
        for(int i=1; i<=k/2; ++i){
            if(remainderCount[i]!=remainderCount[k-i]) return false;
        }
        return remainderCount[0]%2==0;
    }
};