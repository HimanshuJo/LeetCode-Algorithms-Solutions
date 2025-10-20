/*
https://leetcode.com/problems/successful-pairs-of-spells-and-potions/description/?envType=daily-question&envId=2025-10-08
*/

class Solution_TLE {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        vector<int>res;
        int sz1=spells.size(), sz2=potions.size();
        for(int i=0; i<sz1; ++i){
            int curSpell=spells[i], curCount=0;
            for(int j=0; j<sz2; ++j){
                long long curProd=(long long)curSpell*potions[j];
                if(curProd>=success){
                    curCount++;
                }
            }
            res.push_back(curCount);
        }
        return res;
    }
};

// ------- ******* -------

class Solution_OPT {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(), potions.end());
        vector<int>res;
        int sz=potions.size();
        for(int spell: spells){
            long long req=(success+spell-1)/spell;
            int idx=lower_bound(potions.begin(), potions.end(), req)-potions.begin();
            res.push_back(sz-idx);
        }
        return res;
    }
};