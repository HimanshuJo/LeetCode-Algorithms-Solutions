/*
https://leetcode.com/problems/find-the-winner-of-the-circular-game/description/?envType=daily-question&envId=2024-07-08
*/

class Solution {
public:
    int findTheWinner(int n, int k) {
        int nextIdx=0;
        vector<int>all;
        for(int i=1; i<=n; ++i){
            all.push_back(i);
        }
        while(true){
            if(all.size()==1) break;
            all[(nextIdx+k-1)%all.size()]=-1;
            nextIdx=(nextIdx+k-1)%all.size();
            all.erase(remove(all.begin(), all.end(), -1), all.end());
        }
        return all[0];
    }
};