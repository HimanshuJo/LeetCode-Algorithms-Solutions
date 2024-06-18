/*
https://leetcode.com/problems/most-profit-assigning-work/description/?envType=daily-question&envId=2024-06-18
*/

class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        vector<pair<int, int>>comb1, comb2;
        int sz=difficulty.size(), res=0;
        for(int i=0; i<sz; ++i){
            comb1.push_back({difficulty[i], profit[i]});
            comb2.push_back({profit[i], difficulty[i]});
        }
        sort(comb1.begin(), comb1.end());
        sort(comb2.begin(), comb2.end());
        for(auto &vals: worker){
            int idx=0;
            bool flag=false;
            while(idx<=sz-1){
                if(comb1[idx].first<=vals){
                    if(!flag) flag=true;
                    idx++;
                } else break;
            }
            int prttochk=0;
            if(flag){
                if(idx>=1) idx--;
                prttochk=comb1[idx].second;
            }
            int idx2=0;
            while(idx2<=sz-1){
                if(comb2[idx2].second<=vals){
                    prttochk=max(prttochk, comb2[idx2].first);
                }
                idx2++;
            }
            res+=prttochk;
        }
        return res;
    }
};