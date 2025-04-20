/*
https://leetcode.com/problems/rabbits-in-forest/description/?envType=daily-question&envId=2025-04-20
*/

class Solution {
public:
    int numRabbits(vector<int>& answers) {
        int sz=answers.size(), res=0;
        unordered_map<int, int>mp;
        for(auto &vals: answers){
            mp[vals]++;
        }
        for(auto &entries: mp){
            int curPossGrpSz=entries.first+1, curCount=entries.second;
            int totalPossRabsGrp=(curCount+curPossGrpSz-1)/curPossGrpSz;
            res+=(curPossGrpSz*totalPossRabsGrp);
        }
        return res;
    }
};