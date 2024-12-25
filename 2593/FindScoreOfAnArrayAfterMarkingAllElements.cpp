/*
https://leetcode.com/problems/find-score-of-an-array-after-marking-all-elements/description/?envType=daily-question&envId=2024-12-13
*/

class Solution {
public:
    long long findScore(vector<int>& nums) {
        int sz=nums.size();
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>>pq;
        for(int i=0; i<sz; ++i){
            pq.push({nums[i], i});
        }
        set<int>seen;
        long long res=0;
        while(!pq.empty()){
            auto curr=pq.top();
            pq.pop();
            int curval=curr.first, curidx=curr.second;
            if(seen.find(curidx)==seen.end()){
                res+=curval;
                seen.insert(curidx);
                if(curidx-1>=0){
                    if(seen.find(curidx-1)==seen.end()) seen.insert(curidx-1);
                }
                if(curidx+1<=sz-1){
                    if(seen.find(curidx+1)==seen.end()) seen.insert(curidx+1);
                }
            }
        }
        return res;
    }
};