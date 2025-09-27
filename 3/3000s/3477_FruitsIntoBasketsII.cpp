/*
https://leetcode.com/problems/fruits-into-baskets-ii/description/?envType=daily-question&envId=2025-08-05
*/

class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int sz=fruits.size(), res=0;
        set<int>seen;
        for(int i=0; i<sz; ++i){
            int curqnty=fruits[i];
            bool flag=false;
            for(int j=0; j<sz; ++j){
                if(seen.find(j)==seen.end()){
                    if(baskets[j]>=curqnty){
                        seen.insert(j);
                        flag=true;
                        break;
                    }
                }
            }
            if(!flag) res++;
        }
        return res;
    }
};
