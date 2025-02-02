/*
https://leetcode.com/problems/count-number-of-teams/description/?envType=daily-question&envId=2024-07-29
*/

class Solution {
public:
    int numTeams(vector<int>& rating) {
        int sz=rating.size(), res=0;
        for(int i=0; i<sz; ++i){
            int curr=rating[i];
            if(i+1<=sz-1){
                for(int j=i+1; j<sz; ++j){
                    int next=rating[j];
                    if(next>curr){
                        if(j+1<=sz-1){
                            for(int k=j+1; k<sz; ++k){
                                if(rating[k]>next){
                                    res++;
                                }
                            }
                        }
                    } else if(next<curr){
                        if(j+1<=sz-1){
                            for(int k=j+1; k<sz; ++k){
                                if(rating[k]<next){
                                    res++;
                                }
                            }
                        }
                    }
                }
            }
        }
        return res;
    }
};