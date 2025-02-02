/*
https://leetcode.com/problems/maximize-happiness-of-selected-children/description/?envType=daily-question&envId=2024-05-09
*/

class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        priority_queue<int, vector<int>>pq;
        for(auto &vals: happiness){
            pq.push(vals);
        }
        long long res=0, count=1;
        res+=pq.top();
        pq.pop();
        k--;
        while(k){
            int curr=pq.top();
            if(curr-count>0) curr-=count;
            else curr=0;
            res+=curr;
            pq.pop();
            k--;
            count++;
        }
        return res;
    }
};