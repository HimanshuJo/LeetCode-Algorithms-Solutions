/*
https://leetcode.com/problems/count-square-sum-triples/?envType=daily-question&envId=2025-12-08
*/

class Solution {
public:
    int countTriples(int n) {
        int res=0;
        map<int, int>mp;
        for(int i=1; i<=n; ++i){
            mp[i*i]=i;
        }
        for(int i=1; i<=n; ++i){
            if(i+1<=n){
                for(int j=i+1; j<=n; ++j){
                    int valToFind=(i*i)+(j*j);
                    auto itr=mp.find(valToFind);
                    if(itr!=mp.end()){
                        int valToCheck=mp[valToFind];
                        if(valToCheck!=i&&valToCheck!=j){
                            res++;
                        }
                    }
                }
            }
        }
        return res*2;
    }
};