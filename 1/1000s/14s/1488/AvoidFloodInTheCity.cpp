/*
https://leetcode.com/problems/avoid-flood-in-the-city/description/?envType=daily-question&envId=2025-10-07
*/

class Solution_TLE {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        int sz=rains.size();
        vector<int>res;
        vector<int>currFilledLakes;
        vector<int>currFloodLakes;
        int lastFull=1;
        for(int i=0; i<sz; ++i){
            if(currFloodLakes.size()>=1) return {};
            if(rains[i]>0){
                res.push_back(-1);
                auto itr=find(currFilledLakes.begin(), currFilledLakes.end(), rains[i]);
                if(itr!=currFilledLakes.end()){
                    currFloodLakes.push_back(rains[i]);
                } else currFilledLakes.push_back(rains[i]);
            } else{
                if(currFloodLakes.size()>=1){
                    int todry=currFloodLakes.back();
                    currFloodLakes.pop_back();
                    res.push_back(todry);
                } else{
                    if(currFilledLakes.size()>=1){
                        int todry=-1;
                        if(i+1<=sz-1){
                            for(int j=i+1; j<sz; ++j){
                                auto itr=find(currFilledLakes.begin(), currFilledLakes.end(), rains[j]);
                                if(itr!=currFilledLakes.end()){
                                    todry=rains[j];
                                    res.push_back(todry);
                                    currFilledLakes.erase(itr);
                                    break;
                                }
                            }
                        }
                        if(todry==-1){
                            todry=currFilledLakes.back();
                            currFilledLakes.pop_back();
                            res.push_back(todry);
                        }
                    } else res.push_back(lastFull);
                }
            }
        }
        if(currFloodLakes.size()>=1) return {};
        return res;
    }
};