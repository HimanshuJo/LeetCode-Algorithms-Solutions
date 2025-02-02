/*
https://leetcode.com/problems/k-th-smallest-prime-fraction/description/?envType=daily-question&envId=2024-05-10
*/

class CustComp{
    public:
    bool operator()(const pair<double, pair<int, int>>&A, const pair<double, pair<int, int>>&B){
        return A.first>B.first;
    }
};

class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        priority_queue<pair<double, pair<int, int>>, vector<pair<double, pair<int, int>>>, CustComp>pq;
        int sz=arr.size();
        for(int i=0; i<sz; ++i){
            if(i+1<=sz-1){
                for(int j=i+1; j<sz; ++j){
                    pair<int, int>frfst={arr[i], arr[j]};
                    double frsec=arr[i]/(double)arr[j];
                    pq.push(make_pair(frsec, frfst));
                }
            }
        }
        vector<int>res;
        while(!pq.empty()){
            auto curr=pq.top();
            pq.pop();
            k--;
            if(k==0){
                res.push_back(curr.second.first);
                res.push_back(curr.second.second);
                break;
            }
        }
        return res;
    }
};