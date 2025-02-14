/*
https://leetcode.com/problems/maximal-score-after-applying-k-operations/description/?envType=daily-question&envId=2024-10-14
*/

class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        int sz=nums.size();
        double res=0;
        priority_queue<double, vector<double>>pq;
        for(auto &vals: nums) pq.push(vals);
        while(k--){
            int curr=pq.top();
            pq.pop();
            res+=curr;
            auto nw=ceil((double)curr/3);
            pq.push(nw);
        }
        return res;
    }
};