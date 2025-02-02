/*
https://leetcode.com/problems/relative-ranks/submissions/1252524434/?envType=daily-question&envId=2024-05-08
*/

class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        vector<int>tmp=score;
        sort(tmp.begin(), tmp.end());
        unordered_map<int, string>rnkNdMdl_mp;
        int sz=tmp.size(), idx=sz-1;
        if(tmp.size()>=1){
            rnkNdMdl_mp[tmp[idx]]="Gold Medal";
        }
        if(tmp.size()>=2){
            idx--;
            rnkNdMdl_mp[tmp[idx]]="Silver Medal";
        }
        if(tmp.size()>=3){
            idx--;
            rnkNdMdl_mp[tmp[idx]]="Bronze Medal";
        }
        vector<string>res;
        for(auto &vals: score){
            auto itr_mp=rnkNdMdl_mp.find(vals);
            if(itr_mp!=rnkNdMdl_mp.end()) res.push_back(rnkNdMdl_mp[vals]);
            else{
                auto itr_tmp=find(tmp.begin(), tmp.end(), vals);
                int idx=itr_tmp-tmp.begin();
                idx=sz-idx;
                res.push_back(to_string(idx));
            }
        }
        return res;
    }
};