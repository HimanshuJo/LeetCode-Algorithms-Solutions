/*
https://leetcode.com/problems/find-the-town-judge/description/?envType=daily-question&envId=2024-02-22
*/

class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        int sz=trust.size();
        if(sz==0){
            if(n!=1) return -1;
            return 1;
        }
        map<int, vector<int>>pplsmp;
        for(auto &trustentries: trust){
            pplsmp[trustentries[0]].push_back(trustentries[1]);
        }
        for(int i=1; i<=n; ++i){
            auto itr=pplsmp.find(i);
            if(itr==pplsmp.end()){
                bool flag=false;
                for(int j=1; j<=n; ++j){
                    if(j!=i){
                        auto itr2=pplsmp.find(j);
                        if(itr2!=pplsmp.end()){
                            auto vec=pplsmp[j];
                            auto itr2=find(vec.begin(), vec.end(), i);
                            if(itr2==vec.end()){
                                flag=true;
                                break;
                            }
                        } else{
                            flag=true;
                            break;
                        }
                    }
                }
                if(!flag) return i;
            }
        }
        return -1;
    }
};