/*
https://leetcode.com/problems/maximum-candies-you-can-get-from-boxes/description/?envType=daily-question&envId=2025-06-03
*/

class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        int sz=status.size(), res=0;
        vector<bool>hasBoxes(sz, false), canOpen(sz, false), seenBoxes(sz, false);
        queue<int>q;
        for(int i=0; i<sz; ++i){
            if(status[i]==1){
                canOpen[i]=true;
            }
        }
        for(auto &iniBoxes: initialBoxes){
            hasBoxes[iniBoxes]=true;
            if(canOpen[iniBoxes]){
                res+=candies[iniBoxes];
                seenBoxes[iniBoxes]=true;
                q.push(iniBoxes);
            }
        }
        while(!q.empty()){
            int qsz=q.size();
            while(qsz--){
                int curBox=q.front();
                q.pop();
                for(int curKey: keys[curBox]){
                    canOpen[curKey]=true;
                    if(!seenBoxes[curKey]&&hasBoxes[curKey]){
                        res+=candies[curKey];
                        seenBoxes[curKey]=true;
                        q.push(curKey);
                    }
                }
                for(int curContBox: containedBoxes[curBox]){
                    hasBoxes[curContBox]=true;
                    if(!seenBoxes[curContBox]&&canOpen[curContBox]){
                        res+=candies[curContBox];
                        seenBoxes[curContBox]=true;
                        q.push(curContBox);
                    }
                }
            }
        }
        return res;
    }
};