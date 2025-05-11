/*
https://leetcode.com/problems/three-consecutive-odds/description/?envType=daily-question&envId=2025-05-11
*/

class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int sz=arr.size(), idx=0;
        while(true){
            if(idx+2>=sz) break;
            if((arr[idx]%2!=0)&&((arr[idx+1])%2!=0)&&((arr[idx+2])%2!=0)) return true;
            idx++;
        }
        return false;
    }
}; 